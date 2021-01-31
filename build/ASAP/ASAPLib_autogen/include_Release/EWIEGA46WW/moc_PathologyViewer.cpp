/****************************************************************************
** Meta object code from reading C++ file 'PathologyViewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../src/ASAP/PathologyViewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PathologyViewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PathologyViewer_t {
    QByteArrayData data[20];
    char stringdata0[259];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PathologyViewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PathologyViewer_t qt_meta_stringdata_PathologyViewer = {
    {
QT_MOC_LITERAL(0, 0, 15), // "PathologyViewer"
QT_MOC_LITERAL(1, 16, 18), // "fieldOfViewChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 3), // "FOV"
QT_MOC_LITERAL(4, 40, 5), // "level"
QT_MOC_LITERAL(5, 46, 10), // "updateBBox"
QT_MOC_LITERAL(6, 57, 24), // "backgroundChannelChanged"
QT_MOC_LITERAL(7, 82, 9), // "channelNr"
QT_MOC_LITERAL(8, 92, 6), // "moveTo"
QT_MOC_LITERAL(9, 99, 3), // "pos"
QT_MOC_LITERAL(10, 103, 16), // "changeActiveTool"
QT_MOC_LITERAL(11, 120, 20), // "onFieldOfViewChanged"
QT_MOC_LITERAL(12, 141, 24), // "onForegroundImageChanged"
QT_MOC_LITERAL(13, 166, 35), // "std::weak_ptr<MultiResolution..."
QT_MOC_LITERAL(14, 202, 7), // "for_img"
QT_MOC_LITERAL(15, 210, 5), // "scale"
QT_MOC_LITERAL(16, 216, 15), // "showContextMenu"
QT_MOC_LITERAL(17, 232, 11), // "scalingTime"
QT_MOC_LITERAL(18, 244, 1), // "x"
QT_MOC_LITERAL(19, 246, 12) // "zoomFinished"

    },
    "PathologyViewer\0fieldOfViewChanged\0\0"
    "FOV\0level\0updateBBox\0backgroundChannelChanged\0"
    "channelNr\0moveTo\0pos\0changeActiveTool\0"
    "onFieldOfViewChanged\0onForegroundImageChanged\0"
    "std::weak_ptr<MultiResolutionImage>\0"
    "for_img\0scale\0showContextMenu\0scalingTime\0"
    "x\0zoomFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PathologyViewer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       5,    1,   69,    2, 0x06 /* Public */,
       6,    1,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   75,    2, 0x0a /* Public */,
      10,    0,   78,    2, 0x0a /* Public */,
      11,    2,   79,    2, 0x0a /* Public */,
      12,    2,   84,    2, 0x0a /* Public */,
      16,    1,   89,    2, 0x08 /* Private */,
      17,    1,   92,    2, 0x08 /* Private */,
      19,    0,   95,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QRectF, QMetaType::UInt,    3,    4,
    QMetaType::Void, QMetaType::QRectF,    3,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QRectF, QMetaType::UInt,    3,    4,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Float,   14,   15,
    QMetaType::Void, QMetaType::QPoint,    9,
    QMetaType::Void, QMetaType::QReal,   18,
    QMetaType::Void,

       0        // eod
};

void PathologyViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PathologyViewer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fieldOfViewChanged((*reinterpret_cast< const QRectF(*)>(_a[1])),(*reinterpret_cast< const uint(*)>(_a[2]))); break;
        case 1: _t->updateBBox((*reinterpret_cast< const QRectF(*)>(_a[1]))); break;
        case 2: _t->backgroundChannelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->moveTo((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 4: _t->changeActiveTool(); break;
        case 5: _t->onFieldOfViewChanged((*reinterpret_cast< const QRectF(*)>(_a[1])),(*reinterpret_cast< const uint(*)>(_a[2]))); break;
        case 6: _t->onForegroundImageChanged((*reinterpret_cast< std::weak_ptr<MultiResolutionImage>(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 7: _t->showContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 8: _t->scalingTime((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 9: _t->zoomFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PathologyViewer::*)(const QRectF & , const unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PathologyViewer::fieldOfViewChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PathologyViewer::*)(const QRectF & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PathologyViewer::updateBBox)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PathologyViewer::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PathologyViewer::backgroundChannelChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PathologyViewer::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_PathologyViewer.data,
    qt_meta_data_PathologyViewer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PathologyViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PathologyViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PathologyViewer.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int PathologyViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void PathologyViewer::fieldOfViewChanged(const QRectF & _t1, const unsigned int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PathologyViewer::updateBBox(const QRectF & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PathologyViewer::backgroundChannelChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
