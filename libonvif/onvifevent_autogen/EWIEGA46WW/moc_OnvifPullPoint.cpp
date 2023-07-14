/****************************************************************************
** Meta object code from reading C++ file 'OnvifPullPoint.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "OnvifPullPoint.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OnvifPullPoint.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OnvifPullPointWorker_t {
    QByteArrayData data[5];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OnvifPullPointWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OnvifPullPointWorker_t qt_meta_stringdata_OnvifPullPointWorker = {
    {
QT_MOC_LITERAL(0, 0, 20), // "OnvifPullPointWorker"
QT_MOC_LITERAL(1, 21, 15), // "MessageReceived"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 45), // "Response<wsnt__NotificationMe..."
QT_MOC_LITERAL(4, 84, 9) // "rResponse"

    },
    "OnvifPullPointWorker\0MessageReceived\0"
    "\0Response<wsnt__NotificationMessageHolderType>\0"
    "rResponse"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OnvifPullPointWorker[] = {

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
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void OnvifPullPointWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OnvifPullPointWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->MessageReceived((*reinterpret_cast< const Response<wsnt__NotificationMessageHolderType>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OnvifPullPointWorker::*)(const Response<wsnt__NotificationMessageHolderType> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OnvifPullPointWorker::MessageReceived)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OnvifPullPointWorker::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_OnvifPullPointWorker.data,
    qt_meta_data_OnvifPullPointWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OnvifPullPointWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OnvifPullPointWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OnvifPullPointWorker.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int OnvifPullPointWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void OnvifPullPointWorker::MessageReceived(const Response<wsnt__NotificationMessageHolderType> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_OnvifPullPoint_t {
    QByteArrayData data[9];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OnvifPullPoint_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OnvifPullPoint_t qt_meta_stringdata_OnvifPullPoint = {
    {
QT_MOC_LITERAL(0, 0, 14), // "OnvifPullPoint"
QT_MOC_LITERAL(1, 15, 15), // "MessageReceived"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 36), // "Response<_tev__PullMessagesRe..."
QT_MOC_LITERAL(4, 69, 9), // "rResponse"
QT_MOC_LITERAL(5, 79, 12), // "Unsubscribed"
QT_MOC_LITERAL(6, 92, 13), // "ActiveChanged"
QT_MOC_LITERAL(7, 106, 5), // "Start"
QT_MOC_LITERAL(8, 112, 4) // "Stop"

    },
    "OnvifPullPoint\0MessageReceived\0\0"
    "Response<_tev__PullMessagesResponse>\0"
    "rResponse\0Unsubscribed\0ActiveChanged\0"
    "Start\0Stop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OnvifPullPoint[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    0,   42,    2, 0x06 /* Public */,
       6,    0,   43,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   44,    2, 0x0a /* Public */,
       8,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void OnvifPullPoint::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OnvifPullPoint *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->MessageReceived((*reinterpret_cast< const Response<_tev__PullMessagesResponse>(*)>(_a[1]))); break;
        case 1: _t->Unsubscribed(); break;
        case 2: _t->ActiveChanged(); break;
        case 3: _t->Start(); break;
        case 4: _t->Stop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OnvifPullPoint::*)(const Response<_tev__PullMessagesResponse> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OnvifPullPoint::MessageReceived)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (OnvifPullPoint::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OnvifPullPoint::Unsubscribed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (OnvifPullPoint::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OnvifPullPoint::ActiveChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OnvifPullPoint::staticMetaObject = { {
    &Client::staticMetaObject,
    qt_meta_stringdata_OnvifPullPoint.data,
    qt_meta_data_OnvifPullPoint,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OnvifPullPoint::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OnvifPullPoint::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OnvifPullPoint.stringdata0))
        return static_cast<void*>(this);
    return Client::qt_metacast(_clname);
}

int OnvifPullPoint::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Client::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void OnvifPullPoint::MessageReceived(const Response<_tev__PullMessagesResponse> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void OnvifPullPoint::Unsubscribed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void OnvifPullPoint::ActiveChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
