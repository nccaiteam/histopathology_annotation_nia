/****************************************************************************
** Meta object code from reading C++ file 'RenderWorker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../src/ASAP/RenderWorker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RenderWorker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RenderWorker_t {
    QByteArrayData data[10];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RenderWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RenderWorker_t qt_meta_stringdata_RenderWorker = {
    {
QT_MOC_LITERAL(0, 0, 12), // "RenderWorker"
QT_MOC_LITERAL(1, 13, 10), // "tileLoaded"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 8), // "QPixmap*"
QT_MOC_LITERAL(4, 34, 4), // "tile"
QT_MOC_LITERAL(5, 39, 5), // "tileX"
QT_MOC_LITERAL(6, 45, 5), // "tileY"
QT_MOC_LITERAL(7, 51, 8), // "tileSize"
QT_MOC_LITERAL(8, 60, 12), // "tileByteSize"
QT_MOC_LITERAL(9, 73, 9) // "tileLevel"

    },
    "RenderWorker\0tileLoaded\0\0QPixmap*\0"
    "tile\0tileX\0tileY\0tileSize\0tileByteSize\0"
    "tileLevel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RenderWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,    4,    5,    6,    7,    8,    9,

       0        // eod
};

void RenderWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RenderWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tileLoaded((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5])),(*reinterpret_cast< uint(*)>(_a[6]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RenderWorker::*)(QPixmap * , unsigned int , unsigned int , unsigned int , unsigned int , unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RenderWorker::tileLoaded)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RenderWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_RenderWorker.data,
    qt_meta_data_RenderWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RenderWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RenderWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RenderWorker.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int RenderWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void RenderWorker::tileLoaded(QPixmap * _t1, unsigned int _t2, unsigned int _t3, unsigned int _t4, unsigned int _t5, unsigned int _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
