/****************************************************************************
** Meta object code from reading C++ file 'MiniMap.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../src/ASAP/MiniMap.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MiniMap.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MiniMap_t {
    QByteArrayData data[9];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MiniMap_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MiniMap_t qt_meta_stringdata_MiniMap = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MiniMap"
QT_MOC_LITERAL(1, 8, 15), // "positionClicked"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 8), // "position"
QT_MOC_LITERAL(4, 34, 17), // "updateFieldOfView"
QT_MOC_LITERAL(5, 52, 11), // "fieldOfView"
QT_MOC_LITERAL(6, 64, 17), // "toggleCoverageMap"
QT_MOC_LITERAL(7, 82, 15), // "drawCoverageMap"
QT_MOC_LITERAL(8, 98, 17) // "onCoverageUpdated"

    },
    "MiniMap\0positionClicked\0\0position\0"
    "updateFieldOfView\0fieldOfView\0"
    "toggleCoverageMap\0drawCoverageMap\0"
    "onCoverageUpdated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MiniMap[] = {

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
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x0a /* Public */,
       6,    1,   40,    2, 0x0a /* Public */,
       8,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPointF,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QRectF,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,

       0        // eod
};

void MiniMap::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MiniMap *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->positionClicked((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 1: _t->updateFieldOfView((*reinterpret_cast< const QRectF(*)>(_a[1]))); break;
        case 2: _t->toggleCoverageMap((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onCoverageUpdated(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MiniMap::*)(QPointF );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MiniMap::positionClicked)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MiniMap::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MiniMap.data,
    qt_meta_data_MiniMap,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MiniMap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MiniMap::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MiniMap.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MiniMap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void MiniMap::positionClicked(QPointF _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
