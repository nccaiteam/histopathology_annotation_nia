/****************************************************************************
** Meta object code from reading C++ file 'AnnotationTool.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../src/ASAP/annotation/AnnotationTool.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AnnotationTool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AnnotationTool_t {
    QByteArrayData data[6];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AnnotationTool_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AnnotationTool_t qt_meta_stringdata_AnnotationTool = {
    {
QT_MOC_LITERAL(0, 0, 14), // "AnnotationTool"
QT_MOC_LITERAL(1, 15, 16), // "cancelAnnotation"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 16), // "zoomToAnnotation"
QT_MOC_LITERAL(4, 50, 3), // "val"
QT_MOC_LITERAL(5, 54, 24) // "zoomToAnnotationFinished"

    },
    "AnnotationTool\0cancelAnnotation\0\0"
    "zoomToAnnotation\0val\0zoomToAnnotationFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AnnotationTool[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    1,   30,    2, 0x09 /* Protected */,
       5,    0,   33,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal,    4,
    QMetaType::Void,

       0        // eod
};

void AnnotationTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AnnotationTool *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cancelAnnotation(); break;
        case 1: _t->zoomToAnnotation((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 2: _t->zoomToAnnotationFinished(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AnnotationTool::staticMetaObject = { {
    QMetaObject::SuperData::link<ToolPluginInterface::staticMetaObject>(),
    qt_meta_stringdata_AnnotationTool.data,
    qt_meta_data_AnnotationTool,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AnnotationTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnnotationTool::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AnnotationTool.stringdata0))
        return static_cast<void*>(this);
    return ToolPluginInterface::qt_metacast(_clname);
}

int AnnotationTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ToolPluginInterface::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
