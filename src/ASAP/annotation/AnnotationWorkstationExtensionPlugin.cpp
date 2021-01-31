#include "AnnotationWorkstationExtensionPlugin.h"
#include "DotAnnotationTool.h"
#include "PolyAnnotationTool.h"
#include "PointSetAnnotationTool.h"
#include "SplineAnnotationTool.h"
#include "annotation/AnnotationService.h"
#include "annotation/AnnotationList.h"
#include "annotation/AnnotationGroup.h"
#include "QtAnnotation.h"
#include "QtAnnotationGroup.h"
#include "annotation/Annotation.h"
#include "annotation/ImageScopeRepository.h"
#include "annotation/AnnotationToMask.h"
#include "DotQtAnnotation.h"
#include "PolyQtAnnotation.h"
#include "MeasurementQtAnnotation.h"
#include "RectangleAnnotationTool.h"
#include "MeasurementAnnotationTool.h"
#include "PointSetQtAnnotation.h"
#include "multiresolutionimageinterface/MultiResolutionImage.h"
#include "../PathologyViewer.h"
#include <QtUiTools>
#include <QDockWidget>
#include <QTreeWidget>
#include <QPushButton>
#include <QFileDialog>
#include <QLabel>
#include <QApplication>
#include <QColorDialog>
#include <QSettings>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QFormLayout>
#include <QSpinBox>
#include "core/filetools.h"
#include "../QtProgressMonitor.h"
#include <QProgressDialog>
#include <QMessageBox>
#include <QInputDialog>

#include <numeric>
#include <iostream>

unsigned int AnnotationWorkstationExtensionPlugin::_annotationIndex = 0;
unsigned int AnnotationWorkstationExtensionPlugin::_annotationGroupIndex = 0;

AnnotationWorkstationExtensionPlugin::AnnotationWorkstationExtensionPlugin() :
  WorkstationExtensionPluginInterface(),
  _generatedAnnotation(NULL),
  _activeAnnotation(NULL),
  _dockWidget(NULL),
  _treeWidget(NULL),
  _oldEvent(NULL),
  _currentAnnotationLine(NULL),
  _currentAnnotationLabel(NULL),
  _currentAnnotationHeaderLabel(NULL),
  _currentPixelArea(1.)
{
  QUiLoader loader;
  QFile file(":/AnnotationWorkstationExtensionPlugin_ui/AnnotationDockWidget.ui");
  bool openend = file.open(QFile::ReadOnly);
  _dockWidget = qobject_cast<QDockWidget*>(loader.load(&file));
  if (_dockWidget) {
    _dockWidget->setEnabled(false);
    _treeWidget = _dockWidget->findChild<QTreeWidget*>("AnnotationTreeWidget");
    _treeWidget->viewport()->installEventFilter(this);
    _treeWidget->setMouseTracking(true);
    _treeWidget->installEventFilter(this);
    QPushButton* groupButton = _dockWidget->findChild<QPushButton*>("addGroupButton");
    QPushButton* clearButton = _dockWidget->findChild<QPushButton*>("clearButton");
    QPushButton* saveButton = _dockWidget->findChild<QPushButton*>("saveButton");
    QPushButton* loadButton = _dockWidget->findChild<QPushButton*>("loadButton");
    QPushButton* optionsButton = _dockWidget->findChild<QPushButton*>("optionsButton");
    _currentAnnotationLine = _dockWidget->findChild<QFrame*>("currentAnnotationLine");
    _currentAnnotationLabel = _dockWidget->findChild<QLabel*>("currentAnnotationLabel");
    _currentAnnotationHeaderLabel = _dockWidget->findChild<QLabel*>("currentAnnotationHeaderLabel");
    _currentAnnotationLine->setVisible(false);
    _currentAnnotationLabel->setVisible(false);
    _currentAnnotationHeaderLabel->setVisible(false);
    connect(groupButton, SIGNAL(clicked()), this, SLOT(addAnnotationGroup()));
    connect(clearButton, SIGNAL(clicked()), this, SLOT(onClearButtonPressed()));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(onSaveButtonPressed()));
    connect(loadButton, SIGNAL(clicked()), this, SLOT(onLoadButtonPressed()));
    connect(optionsButton, SIGNAL(clicked()), this, SLOT(onOptionsButtonPressed()));
    connect(_treeWidget, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(onItemNameChanged(QTreeWidgetItem*, int)));
    connect(_treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(onTreeWidgetItemDoubleClicked(QTreeWidgetItem*, int)));
    connect(_treeWidget, SIGNAL(itemSelectionChanged()), this, SLOT(onTreeWidgetSelectedItemsChanged()));
    connect(_treeWidget, SIGNAL(itemExpanded(QTreeWidgetItem*)), this, SLOT(resizeOnExpand()));
  }
  _settings = new QSettings(QSettings::IniFormat, QSettings::UserScope, "DIAG", "Path Annotator", this);

  for (int i = 0; i < QColorDialog::customCount(); ++i) {
    QColor customColor = _settings->value("annotationCustomColor" + QString(i), QColor("white")).value<QColor>();
    QColorDialog::setCustomColor(i, customColor);
  }
  QtAnnotation::selectionSensitivity = _settings->value("annotationSelectionSensitivity", 100.).value<float>();

  qRegisterMetaTypeStreamOperators<QtAnnotation*>("QtAnnotation*");
  qRegisterMetaTypeStreamOperators<QtAnnotationGroup*>("QtAnnotationGroup*");
}

AnnotationWorkstationExtensionPlugin::~AnnotationWorkstationExtensionPlugin() {
  for (int i = 0; i < QColorDialog::customCount(); ++i) {
    QColor customColor = QColorDialog::customColor(i);
    _settings->setValue("annotationCustomColor" + QString(i), customColor);
  }
  clear();
}

void AnnotationWorkstationExtensionPlugin::onClearButtonPressed() {
  if (shouldClear()) {
    clear();
  }
}

void AnnotationWorkstationExtensionPlugin::onOptionsButtonPressed() {
  QDialog* optionsDialog = new QDialog();
  optionsDialog->setWindowTitle("Set options for annotation tools");
  QVBoxLayout* dialogLayout = new QVBoxLayout();
  QFormLayout* optionsDialogLayout = new QFormLayout();
  QHBoxLayout* buttonLayout = new QHBoxLayout();
  QDoubleSpinBox * selSensSpinBox = new QDoubleSpinBox();
  selSensSpinBox->setMinimum(20);
  selSensSpinBox->setMaximum(1000);
  selSensSpinBox->setValue(QtAnnotation::selectionSensitivity);
  selSensSpinBox->setSingleStep(20);
  selSensSpinBox->setObjectName("SelectionSensitivity");
  selSensSpinBox->setToolTip("Sets the selection sensitivy for clicking individual points in an annatation. Higher means easier to click.");
  optionsDialogLayout->addRow("Selection sensitivity", selSensSpinBox);
  dialogLayout->addLayout(optionsDialogLayout);
  QPushButton* cancel = new QPushButton("Cancel");
  QPushButton* ok = new QPushButton("Ok");
  cancel->setDefault(true);
  connect(cancel, SIGNAL(clicked()), optionsDialog, SLOT(reject()));
  connect(ok, SIGNAL(clicked()), optionsDialog, SLOT(accept()));
  buttonLayout->addWidget(cancel);
  buttonLayout->addWidget(ok);
  dialogLayout->addLayout(buttonLayout);
  optionsDialog->setLayout(dialogLayout);
  int rval = optionsDialog->exec();
  if (rval) {
    float newSelectionSensitivity = static_cast<float>(selSensSpinBox->value());
    QtAnnotation::selectionSensitivity = newSelectionSensitivity;
    _settings->setValue("annotationSelectionSensitivity", newSelectionSensitivity);
  }
}

void AnnotationWorkstationExtensionPlugin::clear() {
  if (_generatedAnnotation) {
    for (std::vector<std::shared_ptr<ToolPluginInterface> >::iterator it = _annotationTools.begin(); it != _annotationTools.end(); ++it) {
      std::dynamic_pointer_cast<AnnotationTool>((*it))->cancelAnnotation();
    }
  }
  _treeWidget->clearSelection();
  clearTreeWidget();
  clearQtAnnotations();
  clearAnnotationList();
  _annotationGroupIndex = 0;
  _annotationIndex = 0;
}

void AnnotationWorkstationExtensionPlugin::resizeOnExpand() {
  if (_treeWidget) {
    _treeWidget->resizeColumnToContents(0);
    _treeWidget->resizeColumnToContents(1);
  }
}

void AnnotationWorkstationExtensionPlugin::clearTreeWidget() {
  if (_treeWidget) {
    _annotToItem.clear();
    _treeWidget->clear();
  }
}

void AnnotationWorkstationExtensionPlugin::clearAnnotationList() {
  if (_annotationService) {
    _annotationService->getList()->removeAllAnnotations();
    _annotationService->getList()->removeAllGroups();
  }
}

void AnnotationWorkstationExtensionPlugin::clearQtAnnotations() {
  for (QList<QtAnnotation*>::iterator it = _qtAnnotations.begin(); it != _qtAnnotations.end(); ++it) {
    _viewer->scene()->removeItem(*it);
    (*it)->deleteLater();
  }
  _qtAnnotations.clear();
  _activeAnnotation = NULL;
  _generatedAnnotation = NULL;
}

void AnnotationWorkstationExtensionPlugin::onItemNameChanged(QTreeWidgetItem* item, int column) {
  if (item && column == 1) {
    if (QtAnnotation* annot = item->data(1, Qt::UserRole).value<QtAnnotation*>()) {
       annot->getAnnotation()->setName(item->text(1).toStdString());
    }
    else {
      QtAnnotationGroup* grp = item->data(1, Qt::UserRole).value<QtAnnotationGroup*>();
      if (grp) {
        grp->getAnnotationGroup()->setName(item->text(1).toStdString());
      }
    }
  }
}

void AnnotationWorkstationExtensionPlugin::updateAnnotationToolTip(QtAnnotation* annotation) {
  if (annotation) {
    QMap<QtAnnotation*, QTreeWidgetItem*>::iterator it = _annotToItem.find(annotation);
    if (it != _annotToItem.end()) {
      unsigned int nrPoints = annotation->getAnnotation()->getNumberOfPoints();
      float area = annotation->getAnnotation()->getArea();
      QString areaUnit(" pixels.");
      if (_currentPixelArea != 1.) {
        areaUnit = QString(" um<sup>2</sup></html>");
      }
      it.value()->setToolTip(1, QString("<html>Total number of control points: ") + QString::number(nrPoints) + QString("<br/>") + QString("Total area: ") + QString::number(area * _currentPixelArea, 'g', 4) + areaUnit);
      QTreeWidgetItem* parentItem = it.value()->parent();
      while (parentItem) {
        if (QtAnnotationGroup* grp = parentItem->data(1, Qt::UserRole).value<QtAnnotationGroup*>()) {
          unsigned int nrPoints = grp->getAnnotationGroup()->getNumberOfPoints();
          float area = grp->getAnnotationGroup()->getArea();
          QString areaUnit(" pixels.");
          if (_currentPixelArea != 1.) {
            areaUnit = QString(" um<sup>2</sup></html>");
          }
          parentItem->setToolTip(1, QString("<html>Total number of control points: ") + QString::number(nrPoints) + QString("<br/>") + QString("Total area: ") + QString::number(area * _currentPixelArea, 'g', 4) + areaUnit);
        }
        else if (QtAnnotation* annot = parentItem->data(1, Qt::UserRole).value<QtAnnotation*>()) {
          unsigned int nrPoints = annot->getAnnotation()->getNumberOfPoints();
          float area = annot->getAnnotation()->getArea();
          QString areaUnit(" pixels.");
          if (_currentPixelArea != 1.) {
            areaUnit = QString(" um<sup>2</sup></html>");
          }
          parentItem->setToolTip(1, QString("<html>Total number of control points: ") + QString::number(nrPoints) + QString("<br/>") + QString("Total area: ") + QString::number(area * _currentPixelArea, 'g', 4) + areaUnit);
        }
        parentItem = parentItem->parent();
      }
    }
  }
}

void AnnotationWorkstationExtensionPlugin::onTreeWidgetItemDoubleClicked(QTreeWidgetItem * item, int column)
{
  if (_treeWidget && column == 1) {
    _treeWidget->editItem(item, column);
  }
  else if (_treeWidget && column == 0) {
    QColor newColor = QColorDialog::getColor(item->data(0, Qt::UserRole).value<QColor>(), NULL, QString("Select a color"));
    if (newColor.isValid()) {
      int cHeight = _treeWidget->visualItemRect(item).height();
      QPixmap iconPM(cHeight, cHeight);
      iconPM.fill(newColor);
      QIcon color(iconPM);
      item->setIcon(0, color);
      item->setData(0, Qt::UserRole, newColor);
      if (QtAnnotation* annot = item->data(1, Qt::UserRole).value<QtAnnotation*>()) {
        annot->getAnnotation()->setColor(newColor.name().toStdString());
      }
      else {
        QtAnnotationGroup* grp = item->data(1, Qt::UserRole).value<QtAnnotationGroup* >();
        if (grp) {
            grp->getAnnotationGroup()->setColor(newColor.name().toStdString());
        }
      }
    }
  }
}

void AnnotationWorkstationExtensionPlugin::onTreeWidgetSelectedItemsChanged() {
  // First clear all the selected annotations
  for (QSet<QtAnnotation*>::iterator it = _selectedAnnotations.begin(); it != _selectedAnnotations.end(); ++it) {
    (*it)->setSelected(false);
    (*it)->clearActiveSeedPoint();
  }
  _selectedAnnotations.clear();
  _activeAnnotation = NULL;

  // Then update from list view
  QList<QTreeWidgetItem*> selItems = _treeWidget->selectedItems();
  for (QList<QTreeWidgetItem*>::iterator itm = selItems.begin(); itm != selItems.end(); ++itm) {
    if (QtAnnotation* annot = (*itm)->data(1, Qt::UserRole).value<QtAnnotation*>()) {
      annot->setSelected(true);
      _selectedAnnotations.insert(annot);
      _activeAnnotation = annot;
    }
    else {
      if ((*itm)->childCount() > 0) {
        QTreeWidgetItemIterator subItm((*itm)->child(0));
        while (*subItm && (*subItm)->parent() != (*itm)->parent()) {
          if (QtAnnotation* annot = (*itm)->data(1, Qt::UserRole).value<QtAnnotation*>()) {
            annot->setSelected(true);
            _selectedAnnotations.insert(annot);
            _activeAnnotation = annot;
          }
          ++subItm;
        }
      }
    }
  }
}

bool AnnotationWorkstationExtensionPlugin::canClose() {
  return shouldClear();
}

bool AnnotationWorkstationExtensionPlugin::shouldClear() {
  bool shouldClear = false;
  if (_annotationService->getList()->isModified()) {
    QMessageBox msgBox;
	msgBox.setWindowTitle("Path Annotator");
    msgBox.setText("The annotations have been modified.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    switch (ret) {
      case QMessageBox::Save:      
        shouldClear = onSaveButtonPressed();
        break;
      case QMessageBox::Discard:
        shouldClear = true;
        break;
      case QMessageBox::Cancel:
        shouldClear = false;
      default:
        shouldClear = false;
    }
  }
  else {
    shouldClear = true;
  }
  return shouldClear;
}

void AnnotationWorkstationExtensionPlugin::onLoadButtonPressed(const std::string& filePath) {
  QString fileName;
  if (filePath.empty()) {
    fileName = QFileDialog::getOpenFileName(NULL, tr("Load annotations"), _settings->value("lastOpenendPath", QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation)).toString(), tr("Annotation files (*.xml *.ndpa)"));
  }
  else {
    fileName = QString::fromStdString(filePath);
  }
  if (!fileName.isEmpty()) {
    if (!shouldClear()) {
      return;
    }
    clear();
    if (!_annotationService->loadRepositoryFromFile(fileName.toStdString())) {
      int ret = QMessageBox::warning(NULL, tr("Path Annotator"),
        tr("The annotations could not be loaded."),
        QMessageBox::Ok);
    }
    // Check if it is an ImageScopeRepository, if so, offer the user the chance to reload with new closing distance
    std::shared_ptr<ImageScopeRepository> imscRepo = std::dynamic_pointer_cast<ImageScopeRepository>(_annotationService->getRepository());
    if (imscRepo) {
      bool ok = false;
      bool ok2 = false;
      float newClosingDistance = QInputDialog::getDouble(_viewer, tr("Enter the annotation closing distance."), tr("Please provide the maximal distance for which annotations are automatically closed by Path Annotator if they remain open."), 30., 0, 1000, 1, &ok);
      float simplifcationDistance = QInputDialog::getDouble(_viewer, tr("Enter the simplification distance."), tr("Please provide the minimal perpendicular distance for which points are automatically merged."), 100, 0, 1000, 2, &ok2);
      float closingDistance = imscRepo->getClosingDistance();
      if (ok && newClosingDistance != closingDistance) {
        _annotationService->getList()->removeAllAnnotations();
        _annotationService->getList()->removeAllGroups();
        imscRepo->setClosingDistance(newClosingDistance);
        imscRepo->load();
      }
      if (ok2 && simplifcationDistance > 0) {
        std::vector<std::shared_ptr<Annotation> > annotations = _annotationService->getList()->getAnnotations();
        for (std::vector<std::shared_ptr<Annotation> >::iterator it = annotations.begin(); it != annotations.end(); ++it) {
          (*it)->simplify(0, simplifcationDistance);
        }
      }
    }
    // Add loaded groups to treewidget
    QList<QtAnnotationGroup* > childGroups;
    std::map<std::shared_ptr<AnnotationGroup>, QTreeWidgetItem*> annotToWidget;
    std::vector<std::shared_ptr<AnnotationGroup> > grps = _annotationService->getList()->getGroups();
    for (std::vector<std::shared_ptr<AnnotationGroup> >::const_iterator it = grps.begin(); it != grps.end(); ++it) {
      QtAnnotationGroup *grp = new QtAnnotationGroup(*it, this);
      if ((*it)->getGroup() == NULL) {
        _qtAnnotationGroups.append(grp);
        QTreeWidgetItem* newAnnotationGroup = new QTreeWidgetItem(_treeWidget);
        newAnnotationGroup->setText(1, QString::fromStdString((*it)->getName()));
        newAnnotationGroup->setText(2, "Group");
        newAnnotationGroup->setData(1, Qt::UserRole, QVariant::fromValue<QtAnnotationGroup*>(grp));
        newAnnotationGroup->setFlags(newAnnotationGroup->flags() | Qt::ItemIsEditable);
        int cHeight = _treeWidget->visualItemRect(newAnnotationGroup).height();
        QPixmap iconPM(cHeight, cHeight);
        iconPM.fill(QColor((*it)->getColor().c_str()));
        QIcon color(iconPM);
        newAnnotationGroup->setIcon(0, color);
        newAnnotationGroup->setData(0, Qt::UserRole, QColor((*it)->getColor().c_str()));
        annotToWidget[grp->getAnnotationGroup()] = newAnnotationGroup;
      }
      else {
        childGroups.append(grp);
      }
    }
    while (!childGroups.empty()) {
      for (QList<QtAnnotationGroup*>::iterator it = childGroups.begin(); it != childGroups.end();) {
        if (annotToWidget.find((*it)->getAnnotationGroup()->getGroup()) != annotToWidget.end()) {
          _qtAnnotationGroups.append((*it));
          QTreeWidgetItem* newAnnotationGroup = new QTreeWidgetItem(annotToWidget[(*it)->getAnnotationGroup()->getGroup()]);
          newAnnotationGroup->setText(1, QString::fromStdString((*it)->getAnnotationGroup()->getName()));
          newAnnotationGroup->setText(2, "Group");
          newAnnotationGroup->setData(1, Qt::UserRole, QVariant::fromValue<QtAnnotationGroup*>((*it)));
          newAnnotationGroup->setFlags(newAnnotationGroup->flags() | Qt::ItemIsEditable);
          int cHeight = _treeWidget->visualItemRect(newAnnotationGroup).height();
          QPixmap iconPM(cHeight, cHeight);
          iconPM.fill(QColor((*it)->getAnnotationGroup()->getColor().c_str()));
          QIcon color(iconPM);
          newAnnotationGroup->setIcon(0, color);
          newAnnotationGroup->setData(0, Qt::UserRole, QColor((*it)->getAnnotationGroup()->getColor().c_str()));
          annotToWidget[(*it)->getAnnotationGroup()] = newAnnotationGroup;
          it = childGroups.erase(it);
        }
        else{
          ++it;
        }
      }
    }
    std::vector<std::shared_ptr<Annotation> > annots = _annotationService->getList()->getAnnotations();
    for (std::vector<std::shared_ptr<Annotation> >::const_iterator it = annots.begin(); it != annots.end(); ++it) {
      QTreeWidgetItem* prnt = _treeWidget->invisibleRootItem();
      if ((*it)->getGroup()) {
        prnt = annotToWidget[(*it)->getGroup()];
      }
      std::string key = "Annotation " + QString::number(_annotationIndex).toStdString() + "_annotation";
      
      // Add QtAnnotation
      QtAnnotation* annot = NULL;
      if ((*it)->getType() == Annotation::Type::DOT) {
        annot = new DotQtAnnotation((*it), this, _viewer->getSceneScale());
      }
      else if ((*it)->getType() == Annotation::Type::POLYGON || (*it)->getType() == Annotation::Type::RECTANGLE) {
        annot = new PolyQtAnnotation((*it), this, _viewer->getSceneScale());
        dynamic_cast<PolyQtAnnotation*>(annot)->setInterpolationType("linear");
      }
      else if ((*it)->getType() == Annotation::Type::SPLINE) {
        annot = new PolyQtAnnotation((*it), this, _viewer->getSceneScale());
        dynamic_cast<PolyQtAnnotation*>(annot)->setInterpolationType("spline");
      }
      else if ((*it)->getType() == Annotation::Type::MEASUREMENT) {
        annot = new MeasurementQtAnnotation((*it), this, _viewer->getSceneScale());
      }
      else if ((*it)->getType() == Annotation::Type::POINTSET) {
        annot = new PointSetQtAnnotation((*it), this, _viewer->getSceneScale());
      }
      else if ((*it)->getType() == Annotation::Type::RECTANGLE) {
        annot = new PolyQtAnnotation((*it), this, _viewer->getSceneScale());
      }
      if (annot) {
        annot->finish();
        _qtAnnotations.append(annot);
        _viewer->scene()->addItem(annot);
        annot->setZValue(20.);


        _annotationIndex += 1;
        QTreeWidgetItem* newAnnotation = new QTreeWidgetItem(prnt);
        newAnnotation->setText(1, QString::fromStdString((*it)->getName()));
        newAnnotation->setText(2, QString::fromStdString((*it)->getTypeAsString()));
        newAnnotation->setFlags(newAnnotation->flags() & ~Qt::ItemIsDropEnabled);
        newAnnotation->setFlags(newAnnotation->flags() | Qt::ItemIsEditable);
        newAnnotation->setData(1, Qt::UserRole, QVariant::fromValue<QtAnnotation*>(annot));
        int cHeight = _treeWidget->visualItemRect(newAnnotation).height();
        if (_treeWidget->topLevelItemCount() > 0) {
          cHeight = _treeWidget->visualItemRect(_treeWidget->topLevelItem(0)).height();
        }
        QPixmap iconPM(cHeight, cHeight);
        iconPM.fill(QColor((*it)->getColor().c_str()));
        QIcon color(iconPM);
        newAnnotation->setIcon(0, color);
        newAnnotation->setData(0, Qt::UserRole, QColor((*it)->getColor().c_str()));
        _annotToItem[annot] = newAnnotation;
        updateAnnotationToolTip(annot);
        connect(annot, SIGNAL(annotationChanged(QtAnnotation*)), this, SLOT(updateAnnotationToolTip(QtAnnotation*)));
      }
    }
    _treeWidget->resizeColumnToContents(0);
    _treeWidget->resizeColumnToContents(1);
  }
}

bool AnnotationWorkstationExtensionPlugin::onSaveButtonPressed() {
  QDir defaultName = _settings->value("lastOpenendPath", QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation)).toString();
  QString basename = QFileInfo(_settings->value("currentFile", QString()).toString()).completeBaseName();
  if (basename.isEmpty()) {
    basename = QString("annotation.xml");
  }
  else {
    basename += QString(".xml");
  }
  QString fileName = QFileDialog::getSaveFileName(NULL, tr("Save annotations"), defaultName.filePath(basename), tr("XML file (*.xml);;TIF file (*.tif);;All files (*)"));
  if (fileName.endsWith(".tif")) {
    if (std::shared_ptr<MultiResolutionImage> local_img = _img.lock()) {
      std::vector<std::shared_ptr<AnnotationGroup> > grps = this->_annotationService->getList()->getGroups();
      QDialog* nameToLabel = new QDialog();
      nameToLabel->setWindowTitle("Assign labels to annotation groups");
      QVBoxLayout* dialogLayout = new QVBoxLayout();
      QFormLayout* nameToLabelLayout = new QFormLayout();
      QHBoxLayout* buttonLayout = new QHBoxLayout();
      if (grps.empty()) {
        QSpinBox* label = new QSpinBox();
        label->setMinimum(0);
        label->setValue(1);
        label->setObjectName("All annotations");
        nameToLabelLayout->addRow("All annotations", label);
      }
      else {
        for (unsigned int i = 0; i < grps.size(); ++i) {
          if (!grps[i]->getGroup()) {
            QSpinBox* label = new QSpinBox();
            QString grpName = QString::fromStdString(grps[i]->getName());
            label->setObjectName(grpName);
            label->setMinimum(0);
            label->setValue(i + 1);
            nameToLabelLayout->addRow(grpName, label);
          }
        }
      }
      dialogLayout->addLayout(nameToLabelLayout);
      QPushButton* cancel = new QPushButton("Cancel");
      QPushButton* ok = new QPushButton("Ok");
      cancel->setDefault(true);
      connect(cancel, SIGNAL(clicked()), nameToLabel, SLOT(reject()));
      connect(ok, SIGNAL(clicked()), nameToLabel, SLOT(accept()));
      buttonLayout->addWidget(cancel);
      buttonLayout->addWidget(ok);
      dialogLayout->addLayout(buttonLayout);
      nameToLabel->setLayout(dialogLayout);
      int rval = nameToLabel->exec();
      if (rval) {
        QList<QSpinBox*> assignedLabels = nameToLabel->findChildren<QSpinBox*>();
        std::map<std::string, int> nameToLab;
        for (QList<QSpinBox*>::iterator it = assignedLabels.begin(); it != assignedLabels.end(); ++it) {
          if ((*it)->objectName().toStdString() == "All annotations") {
            continue;
          }
          nameToLab[(*it)->objectName().toStdString()] = (*it)->value();
        }
        AnnotationToMask maskConverter;
        QtProgressMonitor monitor;
        maskConverter.setProgressMonitor(&monitor);
        QProgressDialog progressDialog;
        QObject::connect(&monitor, SIGNAL(progressChanged(int)), &progressDialog, SLOT(setValue(int)));
        progressDialog.setMinimum(0);
        progressDialog.setMaximum(100);
        progressDialog.setCancelButton(NULL);
        progressDialog.setWindowModality(Qt::WindowModal);
        progressDialog.setValue(0);
        progressDialog.show();
        QApplication::processEvents();
        maskConverter.convert(_annotationService->getList(), fileName.toStdString(), local_img->getDimensions(), local_img->getSpacing(), nameToLab);
        delete nameToLabel;
        return true;
      }
    }
    else {
      return false;
    }
  }
  else if (!fileName.isEmpty()) {
    if (!_annotationService->saveRepositoryToFile(fileName.toStdString())) {
      int ret = QMessageBox::warning(NULL, tr("Path Annotator"),
        tr("The annotations could not be saved."),
        QMessageBox::Ok);
      return false;
    }
    else {
      _annotationService->getList()->resetModifiedStatus();
      return true;
    }
  }
  return false;
}

bool AnnotationWorkstationExtensionPlugin::eventFilter(QObject* watched, QEvent* event) {
  
  if (qobject_cast<QWidget*>(watched) == _treeWidget->viewport()) {
    if (event->type() == QEvent::Drop) {
      if (event == _oldEvent) {
        return false;
      }
      else {
        _oldEvent = event;
        QApplication::sendEvent(_treeWidget->viewport(), event);
      }
      QTreeWidgetItemIterator it(_treeWidget);
      while (*it) {
        QtAnnotation* annot = (*it)->data(1, Qt::UserRole).value<QtAnnotation*>();
        if (!(*it)->parent()) {
          if (annot) {            
            annot->getAnnotation()->setGroup(NULL);
          }
          else {
            QtAnnotationGroup* grp = (*it)->data(1, Qt::UserRole).value<QtAnnotationGroup*>();
            if (grp) {
              grp->getAnnotationGroup()->setGroup(NULL);
            }
          }
        }
        else {
          QtAnnotation* annot = (*it)->data(1, Qt::UserRole).value<QtAnnotation*>();
          if (annot) {
            annot->getAnnotation()->setGroup((*it)->parent()->data(1, Qt::UserRole).value<QtAnnotationGroup*>()->getAnnotationGroup());
          }
          else {
            QtAnnotationGroup* grp = (*it)->data(1, Qt::UserRole).value<QtAnnotationGroup*>();
            if (grp) {
              grp->getAnnotationGroup()->setGroup((*it)->parent()->data(1, Qt::UserRole).value<QtAnnotationGroup*>()->getAnnotationGroup());
            }
          }
        }
        ++it;
      }
      _oldEvent = NULL;
      _treeWidget->resizeColumnToContents(0);
      _treeWidget->resizeColumnToContents(1);
    }
  }
  else if (qobject_cast<QWidget*>(watched) == _treeWidget && event->type() == QEvent::KeyPress) {
    QKeyEvent* kpEvent = dynamic_cast<QKeyEvent*>(event);
    if (kpEvent->key() == Qt::Key::Key_Delete) {
      QList<QTreeWidgetItem*> selItems = _treeWidget->selectedItems();
      // Handle selected items iteratively to make sure we do not accidentely remove the parent before the child
      while (!selItems.empty()) {
        QTreeWidgetItem* itm = selItems[0];
        if (QtAnnotationGroup* grp = itm->data(1, Qt::UserRole).value<QtAnnotationGroup*>()) {
          deleteAnnotationGroup(grp);
        }
        else {
          deleteAnnotation(itm->data(1, Qt::UserRole).value<QtAnnotation*>());
        }
        selItems = _treeWidget->selectedItems();
      }
      connect(_treeWidget, SIGNAL(itemSelectionChanged()), this, SLOT(onTreeWidgetSelectedItemsChanged()));
    }
    else if (kpEvent->key() == Qt::Key::Key_Z) {
      if (std::shared_ptr<AnnotationTool> tool = std::dynamic_pointer_cast<AnnotationTool>(_viewer->getActiveTool())) {
        tool->keyPressEvent(kpEvent);
      }
    }
  }
  return QObject::eventFilter(watched, event);
}

void AnnotationWorkstationExtensionPlugin::addAnnotationGroup() {
  if (_treeWidget && _annotationService) {
    std::shared_ptr<AnnotationGroup> grp = std::make_shared<AnnotationGroup>();
    QtAnnotationGroup* annotGroup = new QtAnnotationGroup(grp, this);
    grp->setName("Annotation Group " + QString::number(_annotationGroupIndex).toStdString());
    _annotationGroupIndex += 1;
    QString grpUID = QString::fromStdString(grp->getName() + "_group");
    _annotationService->getList()->addGroup(grp);
    _qtAnnotationGroups.append(annotGroup);
    QTreeWidgetItem* newAnnotationGroup = new QTreeWidgetItem(_treeWidget);
    newAnnotationGroup->setText(1, QString::fromStdString(grp->getName()));
    newAnnotationGroup->setText(2, "Group");
    newAnnotationGroup->setData(1, Qt::UserRole, QVariant::fromValue<QtAnnotationGroup* >(annotGroup));
    newAnnotationGroup->setFlags(newAnnotationGroup->flags() | Qt::ItemIsEditable);
    int cHeight = _treeWidget->visualItemRect(newAnnotationGroup).height();
    QPixmap iconPM(cHeight, cHeight);
    iconPM.fill(QColor("#64FE2E"));
    QIcon color(iconPM);
    newAnnotationGroup->setIcon(0, color);
    newAnnotationGroup->setData(0, Qt::UserRole, QColor("#64FE2E"));
    grp->setColor("#64FE2E");
    _treeWidget->resizeColumnToContents(0);
    _treeWidget->resizeColumnToContents(1);
  }
}

QDockWidget* AnnotationWorkstationExtensionPlugin::getDockWidget() {
  return _dockWidget;
}

void AnnotationWorkstationExtensionPlugin::onNewImageLoaded(std::weak_ptr<MultiResolutionImage> img, std::string fileName) {
  _img = img;
  if (_dockWidget) {
    _dockWidget->setEnabled(true);
  }
  if (!fileName.empty()) {
    std::string annotationPath = fileName;
    core::changeExtension(annotationPath, "xml");
    if (core::fileExists(annotationPath)) {
      onLoadButtonPressed(annotationPath);
    }
  }
  if (std::shared_ptr<MultiResolutionImage> local_img = _img.lock()) {
    std::vector<double> spacing = local_img->getSpacing();
    if (spacing.size() > 1) {
      _currentPixelArea = spacing[0] * spacing[1];
    }
    else {
      _currentPixelArea = 1.;
    }
  }
}

std::weak_ptr<MultiResolutionImage> AnnotationWorkstationExtensionPlugin::getCurrentImage() {
  return _img;
}

void AnnotationWorkstationExtensionPlugin::onImageClosed() {
  clear();
  if (_dockWidget) {
    _dockWidget->setEnabled(false);
  }
}

bool AnnotationWorkstationExtensionPlugin::initialize(PathologyViewer* viewer) {
  _viewer = viewer;
  std::shared_ptr<ToolPluginInterface> tool(new DotAnnotationTool(this, viewer));
  _annotationTools.push_back(tool);
  tool.reset(new RectangleAnnotationTool(this, viewer));
  _annotationTools.push_back(tool);
  tool.reset(new PolyAnnotationTool(this, viewer));
  _annotationTools.push_back(tool);
  tool.reset(new SplineAnnotationTool(this, viewer));
  _annotationTools.push_back(tool);
  tool.reset(new PointSetAnnotationTool(this, viewer));
  _annotationTools.push_back(tool);
  tool.reset(new MeasurementAnnotationTool(this, viewer));
  _annotationTools.push_back(tool);
  _annotationService.reset(new AnnotationService());
  return true;
}

std::vector<std::shared_ptr<ToolPluginInterface> > AnnotationWorkstationExtensionPlugin::getTools() {
  return _annotationTools;
}

void AnnotationWorkstationExtensionPlugin::startAnnotation(float x, float y, const std::string& type) {
  if (_generatedAnnotation) {
    return;
  }
  std::shared_ptr<Annotation> annot = std::make_shared<Annotation>();
  annot->addCoordinate(x / _viewer->getSceneScale(), y / _viewer->getSceneScale());
  if (type == "dotannotation") {
    annot->setType(Annotation::Type::DOT);
    _generatedAnnotation = new DotQtAnnotation(annot, this, _viewer->getSceneScale());
  }
  else if (type == "polyannotation") {
    annot->setType(Annotation::Type::POLYGON);
    PolyQtAnnotation* temp = new PolyQtAnnotation(annot, this, _viewer->getSceneScale());
    temp->setInterpolationType("linear");
    _generatedAnnotation = temp;
  }
  else if (type == "splineannotation") {
    annot->setType(Annotation::Type::SPLINE);
    PolyQtAnnotation* temp = new PolyQtAnnotation(annot, this, _viewer->getSceneScale());
    temp->setInterpolationType("spline");
    _generatedAnnotation = temp;    
  }
  else if (type == "pointsetannotation") {
    annot->setType(Annotation::Type::POINTSET);
    PointSetQtAnnotation* temp = new PointSetQtAnnotation(annot, this, _viewer->getSceneScale());
    _generatedAnnotation = temp;
  }
  else if (type == "measurementannotation") {
    annot->setType(Annotation::Type::MEASUREMENT);
    MeasurementQtAnnotation* temp = new MeasurementQtAnnotation(annot, this, _viewer->getSceneScale());
    _generatedAnnotation = temp;
  }
  else if (type == "rectangleannotation") {
    annot->setType(Annotation::Type::RECTANGLE);
    PolyQtAnnotation* temp = new PolyQtAnnotation(annot, this, _viewer->getSceneScale());
    temp->setInterpolationType("linear");
    _generatedAnnotation = temp;
  }
  else {
    return;
  }
  if (_generatedAnnotation) {
    _treeWidget->clearSelection();
    _viewer->scene()->addItem(_generatedAnnotation);
    _generatedAnnotation->setZValue(20.);
    updateGeneratingAnnotationLabel(_generatedAnnotation);
    connect(_generatedAnnotation, SIGNAL(annotationChanged(QtAnnotation*)), this, SLOT(updateGeneratingAnnotationLabel(QtAnnotation*)));
  }
}

void AnnotationWorkstationExtensionPlugin::updateGeneratingAnnotationLabel(QtAnnotation* annotation) {
  if (annotation) {
    _currentAnnotationLine->setVisible(true);
    _currentAnnotationLabel->setVisible(true);
    _currentAnnotationHeaderLabel->setVisible(true);
    unsigned int nrPoints = annotation->getAnnotation()->getNumberOfPoints();
    float area = annotation->getAnnotation()->getArea();
    QString areaUnit(" pixels.");
    if (_currentPixelArea != 1.) {
      areaUnit = QString(" um<sup>2</sup>");
    }
    _currentAnnotationLabel->setText(QString("Total number of control points: ") + QString::number(nrPoints) + QString("<br/>") + QString("Total area: ") + QString::number(area * _currentPixelArea, 'g', 4) + areaUnit);
  }
  else {
    _currentAnnotationLine->setVisible(false);
    _currentAnnotationLabel->setVisible(false);
    _currentAnnotationHeaderLabel->setVisible(false);
  }
}

void AnnotationWorkstationExtensionPlugin::finishAnnotation(bool cancel) {
  if (_generatedAnnotation) {
    _generatedAnnotation->finish();
    updateGeneratingAnnotationLabel(NULL);
    disconnect(_generatedAnnotation, SIGNAL(annotationChanged(QtAnnotation*)), this, SLOT(updateGeneratingAnnotationLabel(QtAnnotation*)));
    if (!cancel) {
      _generatedAnnotation->getAnnotation()->setName("Annotation " + QString::number(_annotationIndex).toStdString());
      _annotationIndex += 1;
      _qtAnnotations.append(_generatedAnnotation);
      _annotationService->getList()->addAnnotation(_generatedAnnotation->getAnnotation());
      QTreeWidgetItem* newAnnotation = new QTreeWidgetItem(_treeWidget);
      newAnnotation->setText(1, QString::fromStdString(_generatedAnnotation->getAnnotation()->getName()));
      newAnnotation->setText(2, QString::fromStdString(_generatedAnnotation->getAnnotation()->getTypeAsString()));
      newAnnotation->setFlags(newAnnotation->flags() & ~Qt::ItemIsDropEnabled);
      newAnnotation->setFlags(newAnnotation->flags() | Qt::ItemIsEditable);
      newAnnotation->setData(1, Qt::UserRole, QVariant::fromValue<QtAnnotation*>(_generatedAnnotation));
      newAnnotation->setSelected(true);
      int cHeight = _treeWidget->visualItemRect(newAnnotation).height();
      QPixmap iconPM(cHeight, cHeight);
      iconPM.fill(QColor("yellow"));
      QIcon color(iconPM);
      newAnnotation->setIcon(0, color);
      newAnnotation->setData(0, Qt::UserRole, QColor("#F4FA58"));
      _generatedAnnotation->getAnnotation()->setColor("#F4FA58");
      _treeWidget->resizeColumnToContents(0);      
      _treeWidget->resizeColumnToContents(1);
      _activeAnnotation = _generatedAnnotation;
      _annotToItem[_activeAnnotation] = newAnnotation;
      updateAnnotationToolTip(_activeAnnotation);
      connect(_activeAnnotation, SIGNAL(annotationChanged(QtAnnotation*)), this, SLOT(updateAnnotationToolTip(QtAnnotation*)));
      _generatedAnnotation = NULL;
    }
    else {
      _viewer->scene()->removeItem(_generatedAnnotation);
      _generatedAnnotation->deleteLater();
      _generatedAnnotation = NULL;
    }
  }
}

void AnnotationWorkstationExtensionPlugin::deleteAnnotation(QtAnnotation* annotation) {
  if (annotation) {
    if (_treeWidget) {
      QTreeWidgetItemIterator it(_treeWidget);
      while (*it) {
        if (annotation == (*it)->data(1, Qt::UserRole).value<QtAnnotation*>()) {
          if (_viewer) {
            _viewer->scene()->removeItem(annotation);
          }
          if (_annotationService) {
            std::vector<std::shared_ptr<Annotation> > annots = _annotationService->getList()->getAnnotations();
            int annotInd = std::find(annots.begin(), annots.end(), annotation->getAnnotation()) - annots.begin();
            _annotationService->getList()->removeAnnotation(annotInd);
          }
          annotation->deleteLater();
          _annotToItem.remove(annotation);
          _qtAnnotations.removeOne(annotation);
          _selectedAnnotations.remove(annotation);
          (*it)->setSelected(false);
          delete (*it);
          break;
        }
        ++it;
      }
    }
  }
}

void AnnotationWorkstationExtensionPlugin::deleteAnnotationGroup(QtAnnotationGroup* group) {
  if (_treeWidget) {
    QTreeWidgetItemIterator it(_treeWidget);
    while (*it) {
      if (group == (*it)->data(1, Qt::UserRole).value<QtAnnotationGroup* >()) {
        if ((*it)->childCount() > 0) {
          for (int i = (*it)->childCount() - 1; i >= 0; --i) {
            QTreeWidgetItem* itm = (*it)->child(i);
            if (QtAnnotation* annot = itm->data(1, Qt::UserRole).value<QtAnnotation*>()) {
              deleteAnnotation(annot);
            }
            else {
              QtAnnotationGroup* grp = itm->data(1, Qt::UserRole).value<QtAnnotationGroup* >();
              if (grp) {              
                deleteAnnotationGroup(grp);
              }
            }
          }
        }
        if (_annotationService) {
          std::vector<std::shared_ptr<AnnotationGroup> > groups = _annotationService->getList()->getGroups();
          int groupInd = std::find(groups.begin(), groups.end(), group->getAnnotationGroup()) - groups.begin(); 
          _annotationService->getList()->removeGroup(groupInd);
        }
        _qtAnnotationGroups.removeOne(group);
        (*it)->setSelected(false);
        delete (*it);
        break;
      }
      ++it;
    }
  }
}

QtAnnotation* AnnotationWorkstationExtensionPlugin::getGeneratedAnnotation() {
  return _generatedAnnotation;
}

QtAnnotation* AnnotationWorkstationExtensionPlugin::getActiveAnnotation() {
  return _activeAnnotation;
}

void AnnotationWorkstationExtensionPlugin::clearSelection() {
  if (_treeWidget) {
    _treeWidget->clearSelection();
  }
}

void AnnotationWorkstationExtensionPlugin::addAnnotationToSelection(QtAnnotation* annotation) {
  QTreeWidgetItemIterator it(_treeWidget);
  while (*it) {
    if ((*it)->data(1, Qt::UserRole).value<QtAnnotation*>() == annotation) {
      (*it)->setSelected(true);
      break;
    }
    ++it;
  }
}

void AnnotationWorkstationExtensionPlugin::removeAnnotationFromSelection(QtAnnotation* annotation) {
  QTreeWidgetItemIterator it(_treeWidget);
  while (*it) {
    if ((*it)->data(1, Qt::UserRole).value<QtAnnotation*>() == annotation)  {
      (*it)->setSelected(true);
      break;
    }
    ++it;
  }
}

QSet<QtAnnotation*> AnnotationWorkstationExtensionPlugin::getSelectedAnnotations() {
  return _selectedAnnotations;
}
