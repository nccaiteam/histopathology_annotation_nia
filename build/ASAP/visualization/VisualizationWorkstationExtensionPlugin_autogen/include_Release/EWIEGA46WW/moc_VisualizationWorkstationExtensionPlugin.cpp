/****************************************************************************
** Meta object code from reading C++ file 'VisualizationWorkstationExtensionPlugin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../src/ASAP/visualization/VisualizationWorkstationExtensionPlugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VisualizationWorkstationExtensionPlugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VisualizationWorkstationExtensionPlugin_t {
    QByteArrayData data[24];
    char stringdata0[373];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VisualizationWorkstationExtensionPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VisualizationWorkstationExtensionPlugin_t qt_meta_stringdata_VisualizationWorkstationExtensionPlugin = {
    {
QT_MOC_LITERAL(0, 0, 39), // "VisualizationWorkstationExten..."
QT_MOC_LITERAL(1, 40, 21), // "changeForegroundImage"
QT_MOC_LITERAL(2, 62, 0), // ""
QT_MOC_LITERAL(3, 63, 35), // "std::weak_ptr<MultiResolution..."
QT_MOC_LITERAL(4, 99, 5), // "scale"
QT_MOC_LITERAL(5, 105, 16), // "onNewImageLoaded"
QT_MOC_LITERAL(6, 122, 3), // "img"
QT_MOC_LITERAL(7, 126, 11), // "std::string"
QT_MOC_LITERAL(8, 138, 8), // "fileName"
QT_MOC_LITERAL(9, 147, 13), // "onImageClosed"
QT_MOC_LITERAL(10, 161, 25), // "onEnableLikelihoodToggled"
QT_MOC_LITERAL(11, 187, 7), // "toggled"
QT_MOC_LITERAL(12, 195, 16), // "onOpacityChanged"
QT_MOC_LITERAL(13, 212, 7), // "opacity"
QT_MOC_LITERAL(14, 220, 27), // "onEnableSegmentationToggled"
QT_MOC_LITERAL(15, 248, 24), // "onOpenResultImageClicked"
QT_MOC_LITERAL(16, 273, 12), // "onLUTChanged"
QT_MOC_LITERAL(17, 286, 7), // "LUTname"
QT_MOC_LITERAL(18, 294, 20), // "onWindowValueChanged"
QT_MOC_LITERAL(19, 315, 6), // "window"
QT_MOC_LITERAL(20, 322, 19), // "onLevelValueChanged"
QT_MOC_LITERAL(21, 342, 5), // "level"
QT_MOC_LITERAL(22, 348, 16), // "onChannelChanged"
QT_MOC_LITERAL(23, 365, 7) // "channel"

    },
    "VisualizationWorkstationExtensionPlugin\0"
    "changeForegroundImage\0\0"
    "std::weak_ptr<MultiResolutionImage>\0"
    "scale\0onNewImageLoaded\0img\0std::string\0"
    "fileName\0onImageClosed\0onEnableLikelihoodToggled\0"
    "toggled\0onOpacityChanged\0opacity\0"
    "onEnableSegmentationToggled\0"
    "onOpenResultImageClicked\0onLUTChanged\0"
    "LUTname\0onWindowValueChanged\0window\0"
    "onLevelValueChanged\0level\0onChannelChanged\0"
    "channel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VisualizationWorkstationExtensionPlugin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   74,    2, 0x0a /* Public */,
       9,    0,   79,    2, 0x0a /* Public */,
      10,    1,   80,    2, 0x0a /* Public */,
      12,    1,   83,    2, 0x0a /* Public */,
      14,    1,   86,    2, 0x0a /* Public */,
      15,    0,   89,    2, 0x0a /* Public */,
      16,    1,   90,    2, 0x0a /* Public */,
      18,    1,   93,    2, 0x0a /* Public */,
      20,    1,   96,    2, 0x0a /* Public */,
      22,    1,   99,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Float,    2,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 7,    6,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Double,   13,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   21,
    QMetaType::Void, QMetaType::Int,   23,

       0        // eod
};

void VisualizationWorkstationExtensionPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VisualizationWorkstationExtensionPlugin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeForegroundImage((*reinterpret_cast< std::weak_ptr<MultiResolutionImage>(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 1: _t->onNewImageLoaded((*reinterpret_cast< std::weak_ptr<MultiResolutionImage>(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 2: _t->onImageClosed(); break;
        case 3: _t->onEnableLikelihoodToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->onOpacityChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->onEnableSegmentationToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->onOpenResultImageClicked(); break;
        case 7: _t->onLUTChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->onWindowValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->onLevelValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->onChannelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VisualizationWorkstationExtensionPlugin::*)(std::weak_ptr<MultiResolutionImage> , float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VisualizationWorkstationExtensionPlugin::changeForegroundImage)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VisualizationWorkstationExtensionPlugin::staticMetaObject = { {
    QMetaObject::SuperData::link<WorkstationExtensionPluginInterface::staticMetaObject>(),
    qt_meta_stringdata_VisualizationWorkstationExtensionPlugin.data,
    qt_meta_data_VisualizationWorkstationExtensionPlugin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VisualizationWorkstationExtensionPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VisualizationWorkstationExtensionPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VisualizationWorkstationExtensionPlugin.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ASAP.WorkstationExtensionPluginInterface/1.0"))
        return static_cast< WorkstationExtensionPluginInterface*>(this);
    return WorkstationExtensionPluginInterface::qt_metacast(_clname);
}

int VisualizationWorkstationExtensionPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WorkstationExtensionPluginInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void VisualizationWorkstationExtensionPlugin::changeForegroundImage(std::weak_ptr<MultiResolutionImage> _t1, float _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

QT_PLUGIN_METADATA_SECTION
static constexpr unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x30,  'A',  'S',  'A',  'P',  '.', 
    'V',  'i',  's',  'u',  'a',  'l',  'i',  'z', 
    'a',  't',  'i',  'o',  'n',  'W',  'o',  'r', 
    'k',  's',  't',  'a',  't',  'i',  'o',  'n', 
    'E',  'x',  't',  'e',  'n',  's',  'i',  'o', 
    'n',  'P',  'l',  'u',  'g',  'i',  'n',  '/', 
    '1',  '.',  '0', 
    // "className"
    0x03,  0x78,  0x27,  'V',  'i',  's',  'u',  'a', 
    'l',  'i',  'z',  'a',  't',  'i',  'o',  'n', 
    'W',  'o',  'r',  'k',  's',  't',  'a',  't', 
    'i',  'o',  'n',  'E',  'x',  't',  'e',  'n', 
    's',  'i',  'o',  'n',  'P',  'l',  'u',  'g', 
    'i',  'n', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(VisualizationWorkstationExtensionPlugin, VisualizationWorkstationExtensionPlugin)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
