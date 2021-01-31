/****************************************************************************
** Meta object code from reading C++ file 'FilterThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../src/ASAP/filters/FilterThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FilterThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FilterThread_t {
    QByteArrayData data[12];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FilterThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FilterThread_t qt_meta_stringdata_FilterThread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FilterThread"
QT_MOC_LITERAL(1, 13, 12), // "filterResult"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "QGraphicsItem*"
QT_MOC_LITERAL(4, 42, 6), // "result"
QT_MOC_LITERAL(5, 49, 4), // "size"
QT_MOC_LITERAL(6, 54, 18), // "updateFilterResult"
QT_MOC_LITERAL(7, 73, 3), // "FOV"
QT_MOC_LITERAL(8, 77, 35), // "std::weak_ptr<MultiResolution..."
QT_MOC_LITERAL(9, 113, 3), // "img"
QT_MOC_LITERAL(10, 117, 5), // "level"
QT_MOC_LITERAL(11, 123, 7) // "channel"

    },
    "FilterThread\0filterResult\0\0QGraphicsItem*\0"
    "result\0size\0updateFilterResult\0FOV\0"
    "std::weak_ptr<MultiResolutionImage>\0"
    "img\0level\0channel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilterThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   39,    2, 0x0a /* Public */,
       6,    4,   40,    2, 0x0a /* Public */,
       6,    3,   49,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QRectF,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QRectF, 0x80000000 | 8, QMetaType::UInt, QMetaType::Int,    7,    9,   10,   11,
    QMetaType::Void, QMetaType::QRectF, 0x80000000 | 8, QMetaType::UInt,    7,    9,   10,

       0        // eod
};

void FilterThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FilterThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->filterResult((*reinterpret_cast< QGraphicsItem*(*)>(_a[1])),(*reinterpret_cast< QRectF(*)>(_a[2]))); break;
        case 1: _t->updateFilterResult(); break;
        case 2: _t->updateFilterResult((*reinterpret_cast< const QRectF(*)>(_a[1])),(*reinterpret_cast< std::weak_ptr<MultiResolutionImage>(*)>(_a[2])),(*reinterpret_cast< const uint(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 3: _t->updateFilterResult((*reinterpret_cast< const QRectF(*)>(_a[1])),(*reinterpret_cast< std::weak_ptr<MultiResolutionImage>(*)>(_a[2])),(*reinterpret_cast< const uint(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FilterThread::*)(QGraphicsItem * , QRectF );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FilterThread::filterResult)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FilterThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_FilterThread.data,
    qt_meta_data_FilterThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FilterThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilterThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FilterThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int FilterThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void FilterThread::filterResult(QGraphicsItem * _t1, QRectF _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
