/****************************************************************************
** Meta object code from reading C++ file 'ASAP.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../src/ASAP/ASAP.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ASAP.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ASAP_t {
    QByteArrayData data[8];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ASAP_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ASAP_t qt_meta_stringdata_ASAP = {
    {
QT_MOC_LITERAL(0, 0, 4), // "ASAP"
QT_MOC_LITERAL(1, 5, 14), // "newImageLoaded"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 35), // "std::weak_ptr<MultiResolution..."
QT_MOC_LITERAL(4, 57, 11), // "std::string"
QT_MOC_LITERAL(5, 69, 11), // "imageClosed"
QT_MOC_LITERAL(6, 81, 24), // "on_actionClose_triggered"
QT_MOC_LITERAL(7, 106, 23) // "on_actionOpen_triggered"

    },
    "ASAP\0newImageLoaded\0\0"
    "std::weak_ptr<MultiResolutionImage>\0"
    "std::string\0imageClosed\0"
    "on_actionClose_triggered\0"
    "on_actionOpen_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ASAP[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       5,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   40,    2, 0x08 /* Private */,
       7,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ASAP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ASAP *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newImageLoaded((*reinterpret_cast< std::weak_ptr<MultiResolutionImage>(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 1: _t->imageClosed(); break;
        case 2: _t->on_actionClose_triggered(); break;
        case 3: _t->on_actionOpen_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ASAP::*)(std::weak_ptr<MultiResolutionImage> , const std::string & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ASAP::newImageLoaded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ASAP::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ASAP::imageClosed)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ASAP::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ASAP.data,
    qt_meta_data_ASAP,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ASAP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ASAP::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ASAP.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ASAP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void ASAP::newImageLoaded(std::weak_ptr<MultiResolutionImage> _t1, const std::string & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ASAP::imageClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
