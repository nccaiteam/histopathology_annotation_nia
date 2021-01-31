/****************************************************************************
** Meta object code from reading C++ file 'ColorDeconvolutionFilterPlugin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../src/ASAP/filters/ColorDeconvolutionFilterPlugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ColorDeconvolutionFilterPlugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ColorDeconvolutionFilterPlugin_t {
    QByteArrayData data[5];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ColorDeconvolutionFilterPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ColorDeconvolutionFilterPlugin_t qt_meta_stringdata_ColorDeconvolutionFilterPlugin = {
    {
QT_MOC_LITERAL(0, 0, 30), // "ColorDeconvolutionFilterPlugin"
QT_MOC_LITERAL(1, 31, 23), // "filterParametersChanged"
QT_MOC_LITERAL(2, 55, 0), // ""
QT_MOC_LITERAL(3, 56, 29), // "updateFilterFromSettingsPanel"
QT_MOC_LITERAL(4, 86, 20) // "revertStainToDefault"

    },
    "ColorDeconvolutionFilterPlugin\0"
    "filterParametersChanged\0\0"
    "updateFilterFromSettingsPanel\0"
    "revertStainToDefault"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ColorDeconvolutionFilterPlugin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ColorDeconvolutionFilterPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ColorDeconvolutionFilterPlugin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->filterParametersChanged(); break;
        case 1: _t->updateFilterFromSettingsPanel(); break;
        case 2: _t->revertStainToDefault(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ColorDeconvolutionFilterPlugin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ColorDeconvolutionFilterPlugin::filterParametersChanged)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ColorDeconvolutionFilterPlugin::staticMetaObject = { {
    QMetaObject::SuperData::link<ImageFilterPluginInterface::staticMetaObject>(),
    qt_meta_stringdata_ColorDeconvolutionFilterPlugin.data,
    qt_meta_data_ColorDeconvolutionFilterPlugin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ColorDeconvolutionFilterPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ColorDeconvolutionFilterPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ColorDeconvolutionFilterPlugin.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ASAP.ImageFilterPluginInterface/1.0"))
        return static_cast< ImageFilterPluginInterface*>(this);
    return ImageFilterPluginInterface::qt_metacast(_clname);
}

int ColorDeconvolutionFilterPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ImageFilterPluginInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ColorDeconvolutionFilterPlugin::filterParametersChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

QT_PLUGIN_METADATA_SECTION
static constexpr unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x21,  'A',  'S',  'A',  'P',  '.', 
    'C',  'o',  'l',  'o',  'r',  'D',  'e',  'c', 
    'o',  'n',  'v',  'o',  'l',  'u',  't',  'i', 
    'o',  'n',  'F',  'i',  'l',  't',  'e',  'r', 
    '/',  '1',  '.',  '0', 
    // "className"
    0x03,  0x78,  0x1e,  'C',  'o',  'l',  'o',  'r', 
    'D',  'e',  'c',  'o',  'n',  'v',  'o',  'l', 
    'u',  't',  'i',  'o',  'n',  'F',  'i',  'l', 
    't',  'e',  'r',  'P',  'l',  'u',  'g',  'i', 
    'n', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(ColorDeconvolutionFilterPlugin, ColorDeconvolutionFilterPlugin)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
