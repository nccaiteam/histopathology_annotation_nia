/****************************************************************************
** Meta object code from reading C++ file 'RenderThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../src/ASAP/RenderThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RenderThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RenderThread_t {
    QByteArrayData data[11];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RenderThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RenderThread_t qt_meta_stringdata_RenderThread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "RenderThread"
QT_MOC_LITERAL(1, 13, 26), // "onBackgroundChannelChanged"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 7), // "channel"
QT_MOC_LITERAL(4, 49, 26), // "onForegroundChannelChanged"
QT_MOC_LITERAL(5, 76, 23), // "onWindowAndLevelChanged"
QT_MOC_LITERAL(6, 100, 6), // "window"
QT_MOC_LITERAL(7, 107, 5), // "level"
QT_MOC_LITERAL(8, 113, 12), // "onLUTChanged"
QT_MOC_LITERAL(9, 126, 11), // "std::string"
QT_MOC_LITERAL(10, 138, 7) // "LUTname"

    },
    "RenderThread\0onBackgroundChannelChanged\0"
    "\0channel\0onForegroundChannelChanged\0"
    "onWindowAndLevelChanged\0window\0level\0"
    "onLUTChanged\0std::string\0LUTname"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RenderThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    1,   37,    2, 0x0a /* Public */,
       5,    2,   40,    2, 0x0a /* Public */,
       8,    1,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void RenderThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RenderThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onBackgroundChannelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onForegroundChannelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onWindowAndLevelChanged((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 3: _t->onLUTChanged((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RenderThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_RenderThread.data,
    qt_meta_data_RenderThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RenderThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RenderThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RenderThread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RenderThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
