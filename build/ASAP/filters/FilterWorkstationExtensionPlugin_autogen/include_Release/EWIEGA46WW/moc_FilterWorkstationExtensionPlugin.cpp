/****************************************************************************
** Meta object code from reading C++ file 'FilterWorkstationExtensionPlugin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../src/ASAP/filters/FilterWorkstationExtensionPlugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FilterWorkstationExtensionPlugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FilterWorkstationExtensionPlugin_t {
    QByteArrayData data[22];
    char stringdata0[373];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FilterWorkstationExtensionPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FilterWorkstationExtensionPlugin_t qt_meta_stringdata_FilterWorkstationExtensionPlugin = {
    {
QT_MOC_LITERAL(0, 0, 32), // "FilterWorkstationExtensionPlugin"
QT_MOC_LITERAL(1, 33, 16), // "onNewImageLoaded"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 35), // "std::weak_ptr<MultiResolution..."
QT_MOC_LITERAL(4, 87, 3), // "img"
QT_MOC_LITERAL(5, 91, 11), // "std::string"
QT_MOC_LITERAL(6, 103, 8), // "fileName"
QT_MOC_LITERAL(7, 112, 13), // "onImageClosed"
QT_MOC_LITERAL(8, 126, 19), // "updateFilteredImage"
QT_MOC_LITERAL(9, 146, 14), // "QGraphicsItem*"
QT_MOC_LITERAL(10, 161, 6), // "result"
QT_MOC_LITERAL(11, 168, 4), // "size"
QT_MOC_LITERAL(12, 173, 21), // "onChangeCurrentFilter"
QT_MOC_LITERAL(13, 195, 43), // "std::shared_ptr<ImageFilterPl..."
QT_MOC_LITERAL(14, 239, 6), // "filter"
QT_MOC_LITERAL(15, 246, 20), // "onFieldOfViewChanged"
QT_MOC_LITERAL(16, 267, 3), // "FOV"
QT_MOC_LITERAL(17, 271, 5), // "level"
QT_MOC_LITERAL(18, 277, 28), // "onFilterResultClearRequested"
QT_MOC_LITERAL(19, 306, 29), // "onFilterResultUpdateRequested"
QT_MOC_LITERAL(20, 336, 25), // "onAutoUpdateStatusChanged"
QT_MOC_LITERAL(21, 362, 10) // "autoUpdate"

    },
    "FilterWorkstationExtensionPlugin\0"
    "onNewImageLoaded\0\0std::weak_ptr<MultiResolutionImage>\0"
    "img\0std::string\0fileName\0onImageClosed\0"
    "updateFilteredImage\0QGraphicsItem*\0"
    "result\0size\0onChangeCurrentFilter\0"
    "std::shared_ptr<ImageFilterPluginInterface>\0"
    "filter\0onFieldOfViewChanged\0FOV\0level\0"
    "onFilterResultClearRequested\0"
    "onFilterResultUpdateRequested\0"
    "onAutoUpdateStatusChanged\0autoUpdate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilterWorkstationExtensionPlugin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    2,   60,    2, 0x0a /* Public */,
      12,    1,   65,    2, 0x0a /* Public */,
      15,    2,   68,    2, 0x0a /* Public */,
      18,    0,   73,    2, 0x08 /* Private */,
      19,    0,   74,    2, 0x08 /* Private */,
      20,    1,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QRectF,   10,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::QRectF, QMetaType::UInt,   16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   21,

       0        // eod
};

void FilterWorkstationExtensionPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FilterWorkstationExtensionPlugin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onNewImageLoaded((*reinterpret_cast< std::weak_ptr<MultiResolutionImage>(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 1: _t->onImageClosed(); break;
        case 2: _t->updateFilteredImage((*reinterpret_cast< QGraphicsItem*(*)>(_a[1])),(*reinterpret_cast< QRectF(*)>(_a[2]))); break;
        case 3: _t->onChangeCurrentFilter((*reinterpret_cast< std::shared_ptr<ImageFilterPluginInterface>(*)>(_a[1]))); break;
        case 4: _t->onFieldOfViewChanged((*reinterpret_cast< const QRectF(*)>(_a[1])),(*reinterpret_cast< const uint(*)>(_a[2]))); break;
        case 5: _t->onFilterResultClearRequested(); break;
        case 6: _t->onFilterResultUpdateRequested(); break;
        case 7: _t->onAutoUpdateStatusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< std::shared_ptr<ImageFilterPluginInterface> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FilterWorkstationExtensionPlugin::staticMetaObject = { {
    QMetaObject::SuperData::link<WorkstationExtensionPluginInterface::staticMetaObject>(),
    qt_meta_stringdata_FilterWorkstationExtensionPlugin.data,
    qt_meta_data_FilterWorkstationExtensionPlugin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FilterWorkstationExtensionPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilterWorkstationExtensionPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FilterWorkstationExtensionPlugin.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ASAP.WorkstationExtensionPluginInterface/1.0"))
        return static_cast< WorkstationExtensionPluginInterface*>(this);
    return WorkstationExtensionPluginInterface::qt_metacast(_clname);
}

int FilterWorkstationExtensionPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WorkstationExtensionPluginInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

QT_PLUGIN_METADATA_SECTION
static constexpr unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x29,  'A',  'S',  'A',  'P',  '.', 
    'F',  'i',  'l',  't',  'e',  'r',  'W',  'o', 
    'r',  'k',  's',  't',  'a',  't',  'i',  'o', 
    'n',  'E',  'x',  't',  'e',  'n',  's',  'i', 
    'o',  'n',  'P',  'l',  'u',  'g',  'i',  'n', 
    '/',  '1',  '.',  '0', 
    // "className"
    0x03,  0x78,  0x20,  'F',  'i',  'l',  't',  'e', 
    'r',  'W',  'o',  'r',  'k',  's',  't',  'a', 
    't',  'i',  'o',  'n',  'E',  'x',  't',  'e', 
    'n',  's',  'i',  'o',  'n',  'P',  'l',  'u', 
    'g',  'i',  'n', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(FilterWorkstationExtensionPlugin, FilterWorkstationExtensionPlugin)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
