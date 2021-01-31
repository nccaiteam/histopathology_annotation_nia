#include <string>
#include <vector>
#include <iostream>

#include <QFileDialog>
#include <QToolButton>
#include <QIcon>
#include <QLabel>
#include <QGraphicsEffect>
#include <QDebug>
#include <QPushButton>
#include <QDockWidget>
#include <QListWidget>
#include <QPlainTextEdit>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPluginLoader>
#include <QComboBox>
#include <QToolBar>
#include <QStyle>
#include <QActionGroup>
#include <QSettings>
#include <QFileInfo>
#include <QStandardPaths>
#include <QtUiTools>
#include <QTreeWidget>

#include "ASAP.h"
#include "PathologyViewer.h"
#include "interfaces/interfaces.h"
#include "WSITileGraphicsItemCache.h"
#include "config/ASAPMacros.h"
#include "multiresolutionimageinterface/MultiResolutionImageReader.h"
#include "multiresolutionimageinterface/MultiResolutionImage.h"
#include "multiresolutionimageinterface/MultiResolutionImageFactory.h"
#include "multiresolutionimageinterface/OpenSlideImage.h"

#ifdef WIN32
const char* ASAP::sharedLibraryExtensions = ".dll";
#else
const char* ASAP::sharedLibraryExtensions = ".so";
#endif

using namespace std;

ASAP::ASAP(QWidget *parent) :
    QMainWindow(parent),
    _cacheMaxByteSize(1000*512*512*3),
    _settings(NULL)
{
  setupUi();
  retranslateUi();
  connect(actionOpen, SIGNAL(triggered(bool)), this, SLOT(on_actionOpen_triggered()));
  connect(actionClose, SIGNAL(triggered(bool)), this, SLOT(on_actionClose_triggered()));

  PathologyViewer* view = this->findChild<PathologyViewer*>("pathologyView");
  this->loadPlugins();
  view->setCacheSize(_cacheMaxByteSize);
  if (view->hasTool("pan")) {
    view->setActiveTool("pan");
    QList<QAction*> toolButtons = mainToolBar->actions();
    for (QList<QAction*>::iterator it = toolButtons.begin(); it != toolButtons.end(); ++it) {
      if ((*it)->objectName() == "pan") {
        (*it)->setChecked(true);
      }
    }
  }  
  view->setEnabled(false);
  _settings = new QSettings(QSettings::IniFormat, QSettings::UserScope, "DIAG", "Path Annotator", this);
  readSettings();
  QStringList args = QApplication::arguments();
  if (args.size() > 1) {
    openFile(args[1], "default");
  }
}

void ASAP::writeSettings()
{
  _settings->beginGroup("Path Annotator");
  _settings->setValue("size", size());
  _settings->setValue("maximized", isMaximized());
  _settings->endGroup();
}

void ASAP::readSettings()
{
  _settings->beginGroup("Path Annotator");
  resize(_settings->value("size", QSize(1037, 786)).toSize());
  if (_settings->value("maximized", false).toBool()) {
    this->setWindowState(Qt::WindowMaximized);
  }
  _settings->endGroup();
}

void ASAP::loadPlugins() {
  PathologyViewer* viewer = this->findChild<PathologyViewer*>("pathologyView");
  _pluginsDir = QDir(qApp->applicationDirPath());
  if (_pluginsDir.cd("plugins")) {
    if (_pluginsDir.cd("tools")) {
      foreach(QString fileName, _pluginsDir.entryList(QDir::Files)) {
        if (fileName.toLower().endsWith(sharedLibraryExtensions)) {
          QPluginLoader loader(_pluginsDir.absoluteFilePath(fileName));
          QObject *plugin = loader.instance();
          if (plugin) {
            std::shared_ptr<ToolPluginInterface> tool(qobject_cast<ToolPluginInterface*>(plugin));
            if (tool) {
              tool->setViewer(viewer);
              QAction* toolAction = tool->getToolButton();
              connect(toolAction, SIGNAL(triggered(bool)), viewer, SLOT(changeActiveTool()));
              _toolPluginFileNames.push_back(fileName.toStdString());
              viewer->addTool(tool);
              QToolBar* mainToolBar = this->findChild<QToolBar *>("mainToolBar");
              toolAction->setCheckable(true);
              _toolActions->addAction(toolAction);
              mainToolBar->addAction(toolAction);
            }
          }
        }
      }
      _pluginsDir.cdUp();
    }
    if (_pluginsDir.cd("workstationextension")) {
      QDockWidget* lastDockWidget = NULL;
      QDockWidget* firstDockWidget = NULL;
      foreach(QString fileName, _pluginsDir.entryList(QDir::Files)) {
        if (fileName.toLower().endsWith(sharedLibraryExtensions)) {        
          QPluginLoader loader(_pluginsDir.absoluteFilePath(fileName));       
          QObject *plugin = loader.instance();    
          if (plugin) {         
            std::unique_ptr<WorkstationExtensionPluginInterface> extension(qobject_cast<WorkstationExtensionPluginInterface*>(plugin));
            if (extension) {
              _extensionPluginFileNames.push_back(fileName.toStdString());
              connect(this, SIGNAL(newImageLoaded(std::weak_ptr<MultiResolutionImage>, std::string)), &*extension, SLOT(onNewImageLoaded(std::weak_ptr<MultiResolutionImage>, std::string)));
              connect(this, SIGNAL(imageClosed()), &*extension, SLOT(onImageClosed()));
              extension->initialize(viewer);
              if (extension->getToolBar()) {
                this->addToolBar(extension->getToolBar());
              }
              if (extension->getDockWidget()) {
                QDockWidget* extensionDW = extension->getDockWidget();
                extensionDW->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
                if (lastDockWidget) {
                  this->tabifyDockWidget(lastDockWidget, extensionDW);
                }
                else {
                  this->addDockWidget(Qt::LeftDockWidgetArea, extensionDW);
                  firstDockWidget = extensionDW;
                }
                extensionDW->setTitleBarWidget(new QWidget());
                lastDockWidget = extensionDW;
                QMenu* viewMenu = this->findChild<QMenu*>("menuView");
                QMenu* viewDocksMenu = viewMenu->findChild<QMenu*>("menuViewDocks");
                if (!viewDocksMenu) {
                  viewDocksMenu = viewMenu->addMenu("Docks");
                  viewDocksMenu->setObjectName("menuViewDocks");
                }
                viewDocksMenu->addAction(extensionDW->toggleViewAction());
              }
              if (extension->getMenu()) {
                this->menuBar->addMenu(extension->getMenu());
              }
              std::vector<std::shared_ptr<ToolPluginInterface> > tools = extension->getTools();
              if (!tools.empty()) {
                mainToolBar->addSeparator();
                for (unsigned int i = 0; i < tools.size(); ++i) {
                  QAction* toolAction = tools[i]->getToolButton();
                  connect(toolAction, SIGNAL(triggered(bool)), viewer, SLOT(changeActiveTool()));
                  viewer->addTool(tools[i]);
                  mainToolBar->addAction(toolAction);
                  toolAction->setCheckable(true);
                  _toolActions->addAction(toolAction);
                }
              }
              _extensions.push_back(std::move(extension));
            }
          }
        }
      }
      _pluginsDir.cdUp();
      if (firstDockWidget) {
        firstDockWidget->raise();
      }
    }
  }
}

void ASAP::closeEvent(QCloseEvent *event) {
  event->accept();
}

ASAP::~ASAP()
{
  on_actionClose_triggered();
  writeSettings();
}

void ASAP::on_actionClose_triggered()
{
    for (std::vector<std::unique_ptr<WorkstationExtensionPluginInterface> >::iterator it = _extensions.begin(); it != _extensions.end(); ++it) {
      if (!(*it)->canClose()) {
        return;
      }
    }
    emit imageClosed();
    _settings->setValue("currentFile", QString());
    this->setWindowTitle("Path Annotator");
    if (_img) {
		  PathologyViewer* view = this->findChild<PathologyViewer*>("pathologyView");
		  view->close();
		  _img.reset();
		  statusBar->showMessage("Closed file!", 5);
    }
}

void ASAP::openFile(const QString& fileName, const QString& factoryName) {
  statusBar->clearMessage();
  if (!fileName.isEmpty()) {
    if (_img) {
      on_actionClose_triggered();
    }
    std::string fn = fileName.toStdString();
    _settings->setValue("lastOpenendPath", QFileInfo(fileName).dir().path());
    _settings->setValue("currentFile", QFileInfo(fileName).fileName());
    this->setWindowTitle(QString("Path Annotator - ") + QFileInfo(fileName).fileName());
    MultiResolutionImageReader imgReader;
    _img.reset(imgReader.open(fn, factoryName.toStdString()));
    if (_img) {
      if (_img->valid()) {
        vector<unsigned long long> dimensions = _img->getLevelDimensions(_img->getNumberOfLevels() - 1);
        PathologyViewer* view = this->findChild<PathologyViewer*>("pathologyView");
        view->initialize(_img);
        emit newImageLoaded(_img, fn);
      }
      else {
        statusBar->showMessage("Unsupported file type version");
      }
    }
    else {
      statusBar->showMessage("Invalid file type");
    }
  }
}

void ASAP::on_actionOpen_triggered()
{ 
  QString filterList;
  std::set<std::string> allExtensions = MultiResolutionImageFactory::getAllSupportedExtensions();
  QString defaultString = "All supported types (";
  for (auto it = allExtensions.begin(); it != allExtensions.end(); ++it) {
    defaultString += " *." + QString::fromStdString(*it);
  }
  defaultString += ")";
  filterList += defaultString;

  std::vector<std::pair<std::string, std::set<std::string>> > factoriesAndExtensions = MultiResolutionImageFactory::getLoadedFactoriesAndSupportedExtensions();
  for (auto it = factoriesAndExtensions.begin(); it != factoriesAndExtensions.end(); ++it) {
    QString extensionString = "(*." + QString::fromStdString(*(it->second.begin()));
    for (auto extensionIt = std::next(it->second.begin(), 1); extensionIt != it->second.end(); ++extensionIt) {
      extensionString += " *." + QString::fromStdString(*extensionIt);
    }
    extensionString += ")";
    filterList += (";;" + QString::fromStdString(it->first) + " " + extensionString);
  }
  QString selectedFilter;
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), _settings->value("lastOpenendPath", QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation)).toString(), filterList, &selectedFilter);
  QString selectedFactory = selectedFilter.split("(")[0].trimmed();
  openFile(fileName, selectedFactory == "All supported types" ? "default": selectedFactory);
}

void ASAP::setCacheSize(const unsigned long long& cacheMaxByteSize) {
  PathologyViewer* view = this->findChild<PathologyViewer*>("pathologyView");
  if (view) {
    view->setCacheSize(_cacheMaxByteSize);
  }
}
    
unsigned long long ASAP::getCacheSize() const {
  PathologyViewer* view = this->findChild<PathologyViewer*>("pathologyView");
  if (view) {
    return view->getCacheSize();
  }
}

void ASAP::setupUi()
{
  if (this->objectName().isEmpty()) {
      this->setObjectName(QStringLiteral("Path Annotator"));
  }
  this->resize(1037, 786);
  this->setTabPosition(Qt::DockWidgetArea::LeftDockWidgetArea, QTabWidget::East);
  this->setTabPosition(Qt::DockWidgetArea::RightDockWidgetArea, QTabWidget::West);
  QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  sizePolicy.setHorizontalStretch(0);
  sizePolicy.setVerticalStretch(0);
  sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
  this->setSizePolicy(sizePolicy);
  actionOpen = new QAction(this);
  actionOpen->setObjectName(QStringLiteral("actionOpen"));
  actionClose = new QAction(this);
  actionClose->setObjectName(QStringLiteral("actionClose"));
  actionOpen->setIcon(QIcon(QPixmap(":/ASAP_icons/open.png")));
  actionClose->setIcon(QIcon(QPixmap(":/ASAP_icons/close.png")));
  menuBar = new QMenuBar(this);
  menuBar->setObjectName(QStringLiteral("menuBar"));
  menuBar->setGeometry(QRect(0, 0, 1037, 21));
  menuFile = new QMenu(menuBar);
  menuFile->setObjectName(QStringLiteral("menuFile"));
  menuView = new QMenu(menuBar);
  menuView->setObjectName(QStringLiteral("menuView"));
  this->setMenuBar(menuBar);
  mainToolBar = new QToolBar(this);
  mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
  mainToolBar->addAction(actionOpen);
  mainToolBar->addAction(actionClose);
  mainToolBar->addSeparator();
  this->addToolBar(Qt::TopToolBarArea, mainToolBar);
  _toolActions = new QActionGroup(this);
  statusBar = new QStatusBar(this);
  statusBar->setObjectName(QStringLiteral("statusBar"));
  this->setStatusBar(statusBar);

  menuBar->addAction(menuFile->menuAction());
  menuBar->addAction(menuView->menuAction());
  menuFile->addAction(actionOpen);
  menuFile->addAction(actionClose);
  centralWidget = new QWidget(this);
  centralWidget->setObjectName(QStringLiteral("centralWidget"));
  sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
  centralWidget->setSizePolicy(sizePolicy);
  centralWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
  horizontalLayout_2 = new QHBoxLayout(centralWidget);
  horizontalLayout_2->setSpacing(6);
  horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
  horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
  pathologyView = new PathologyViewer(centralWidget);
  pathologyView->setObjectName(QStringLiteral("pathologyView"));

  horizontalLayout_2->addWidget(pathologyView);

  this->setCentralWidget(centralWidget);
}

void ASAP::retranslateUi()
{
  this->setWindowTitle(QApplication::translate("PathologyWorkstation", "Path Annotator", 0));
  actionOpen->setText(QApplication::translate("PathologyWorkstation", "Open", 0));
  actionOpen->setIconText(QApplication::translate("PathologyWorkstation", "Open", 0));
  actionOpen->setShortcut(QApplication::translate("PathologyWorkstation", "Ctrl+O", 0));
  actionClose->setText(QApplication::translate("PathologyWorkstation", "Close", 0));
  actionClose->setShortcut(QApplication::translate("PathologyWorkstation", "Ctrl+C", 0));
  actionClose->setIconText(QApplication::translate("PathologyWorkstation", "Close", 0));
  menuFile->setTitle(QApplication::translate("PathologyWorkstation", "File", 0));
  menuView->setTitle(QApplication::translate("PathologyWorkstation", "View", 0));
} 
