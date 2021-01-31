/****************************************************************************
** Meta object code from reading C++ file 'FilterDockWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../src/ASAP/filters/FilterDockWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FilterDockWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FilterDockWidget_t {
    QByteArrayData data[21];
    char stringdata0[382];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FilterDockWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FilterDockWidget_t qt_meta_stringdata_FilterDockWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "FilterDockWidget"
QT_MOC_LITERAL(1, 17, 19), // "changeCurrentFilter"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 43), // "std::shared_ptr<ImageFilterPl..."
QT_MOC_LITERAL(4, 82, 6), // "filter"
QT_MOC_LITERAL(5, 89, 25), // "requestFilterResultUpdate"
QT_MOC_LITERAL(6, 115, 24), // "requestFilterResultClear"
QT_MOC_LITERAL(7, 140, 22), // "changeAutoUpdateStatus"
QT_MOC_LITERAL(8, 163, 10), // "autoUpdate"
QT_MOC_LITERAL(9, 174, 13), // "onItemClicked"
QT_MOC_LITERAL(10, 188, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(11, 205, 4), // "item"
QT_MOC_LITERAL(12, 210, 12), // "onProcessing"
QT_MOC_LITERAL(13, 223, 20), // "onApplyFilterClicked"
QT_MOC_LITERAL(14, 244, 20), // "onClearFilterClicked"
QT_MOC_LITERAL(15, 265, 19), // "onAutoUpdateToggled"
QT_MOC_LITERAL(16, 285, 25), // "onFilterParametersChanged"
QT_MOC_LITERAL(17, 311, 16), // "onNewImageLoaded"
QT_MOC_LITERAL(18, 328, 35), // "std::weak_ptr<MultiResolution..."
QT_MOC_LITERAL(19, 364, 3), // "img"
QT_MOC_LITERAL(20, 368, 13) // "onImageClosed"

    },
    "FilterDockWidget\0changeCurrentFilter\0"
    "\0std::shared_ptr<ImageFilterPluginInterface>\0"
    "filter\0requestFilterResultUpdate\0"
    "requestFilterResultClear\0"
    "changeAutoUpdateStatus\0autoUpdate\0"
    "onItemClicked\0QListWidgetItem*\0item\0"
    "onProcessing\0onApplyFilterClicked\0"
    "onClearFilterClicked\0onAutoUpdateToggled\0"
    "onFilterParametersChanged\0onNewImageLoaded\0"
    "std::weak_ptr<MultiResolutionImage>\0"
    "img\0onImageClosed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilterDockWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       5,    0,   77,    2, 0x06 /* Public */,
       6,    0,   78,    2, 0x06 /* Public */,
       7,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   82,    2, 0x08 /* Private */,
      12,    0,   85,    2, 0x08 /* Private */,
      13,    0,   86,    2, 0x08 /* Private */,
      14,    0,   87,    2, 0x08 /* Private */,
      15,    1,   88,    2, 0x08 /* Private */,
      16,    0,   91,    2, 0x08 /* Private */,
      17,    1,   92,    2, 0x0a /* Public */,
      20,    0,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,

       0        // eod
};

void FilterDockWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FilterDockWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeCurrentFilter((*reinterpret_cast< std::shared_ptr<ImageFilterPluginInterface>(*)>(_a[1]))); break;
        case 1: _t->requestFilterResultUpdate(); break;
        case 2: _t->requestFilterResultClear(); break;
        case 3: _t->changeAutoUpdateStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->onItemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->onProcessing(); break;
        case 6: _t->onApplyFilterClicked(); break;
        case 7: _t->onClearFilterClicked(); break;
        case 8: _t->onAutoUpdateToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->onFilterParametersChanged(); break;
        case 10: _t->onNewImageLoaded((*reinterpret_cast< std::weak_ptr<MultiResolutionImage>(*)>(_a[1]))); break;
        case 11: _t->onImageClosed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FilterDockWidget::*)(std::shared_ptr<ImageFilterPluginInterface> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FilterDockWidget::changeCurrentFilter)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FilterDockWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FilterDockWidget::requestFilterResultUpdate)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FilterDockWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FilterDockWidget::requestFilterResultClear)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FilterDockWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FilterDockWidget::changeAutoUpdateStatus)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FilterDockWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QDockWidget::staticMetaObject>(),
    qt_meta_stringdata_FilterDockWidget.data,
    qt_meta_data_FilterDockWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FilterDockWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilterDockWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FilterDockWidget.stringdata0))
        return static_cast<void*>(this);
    return QDockWidget::qt_metacast(_clname);
}

int FilterDockWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void FilterDockWidget::changeCurrentFilter(std::shared_ptr<ImageFilterPluginInterface> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FilterDockWidget::requestFilterResultUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FilterDockWidget::requestFilterResultClear()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void FilterDockWidget::changeAutoUpdateStatus(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
