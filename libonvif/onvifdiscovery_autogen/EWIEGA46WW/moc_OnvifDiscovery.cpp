/****************************************************************************
** Meta object code from reading C++ file 'OnvifDiscovery.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "OnvifDiscovery.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OnvifDiscovery.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OnvifDiscoveryWorker_t {
    QByteArrayData data[5];
    char stringdata0[50];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OnvifDiscoveryWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OnvifDiscoveryWorker_t qt_meta_stringdata_OnvifDiscoveryWorker = {
    {
QT_MOC_LITERAL(0, 0, 20), // "OnvifDiscoveryWorker"
QT_MOC_LITERAL(1, 21, 5), // "Match"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 14), // "DiscoveryMatch"
QT_MOC_LITERAL(4, 43, 6) // "rMatch"

    },
    "OnvifDiscoveryWorker\0Match\0\0DiscoveryMatch\0"
    "rMatch"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OnvifDiscoveryWorker[] = {

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

void OnvifDiscoveryWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OnvifDiscoveryWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Match((*reinterpret_cast< const DiscoveryMatch(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DiscoveryMatch >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OnvifDiscoveryWorker::*)(const DiscoveryMatch & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OnvifDiscoveryWorker::Match)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OnvifDiscoveryWorker::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_OnvifDiscoveryWorker.data,
    qt_meta_data_OnvifDiscoveryWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OnvifDiscoveryWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OnvifDiscoveryWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OnvifDiscoveryWorker.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int OnvifDiscoveryWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void OnvifDiscoveryWorker::Match(const DiscoveryMatch & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_OnvifDiscovery_t {
    QByteArrayData data[18];
    char stringdata0[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OnvifDiscovery_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OnvifDiscovery_t qt_meta_stringdata_OnvifDiscovery = {
    {
QT_MOC_LITERAL(0, 0, 14), // "OnvifDiscovery"
QT_MOC_LITERAL(1, 15, 5), // "Match"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 14), // "DiscoveryMatch"
QT_MOC_LITERAL(4, 37, 6), // "rMatch"
QT_MOC_LITERAL(5, 44, 8), // "NewMatch"
QT_MOC_LITERAL(6, 53, 14), // "MatchesChanged"
QT_MOC_LITERAL(7, 68, 13), // "ActiveChanged"
QT_MOC_LITERAL(8, 82, 5), // "Start"
QT_MOC_LITERAL(9, 88, 4), // "Stop"
QT_MOC_LITERAL(10, 93, 12), // "ClearMatches"
QT_MOC_LITERAL(11, 106, 14), // "SetMatchScopes"
QT_MOC_LITERAL(12, 121, 14), // "rScopesToMatch"
QT_MOC_LITERAL(13, 136, 13), // "SetMatchTypes"
QT_MOC_LITERAL(14, 150, 13), // "rTypesToMatch"
QT_MOC_LITERAL(15, 164, 7), // "matches"
QT_MOC_LITERAL(16, 172, 21), // "QList<DiscoveryMatch>"
QT_MOC_LITERAL(17, 194, 6) // "active"

    },
    "OnvifDiscovery\0Match\0\0DiscoveryMatch\0"
    "rMatch\0NewMatch\0MatchesChanged\0"
    "ActiveChanged\0Start\0Stop\0ClearMatches\0"
    "SetMatchScopes\0rScopesToMatch\0"
    "SetMatchTypes\0rTypesToMatch\0matches\0"
    "QList<DiscoveryMatch>\0active"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OnvifDiscovery[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       2,   76, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    1,   62,    2, 0x06 /* Public */,
       6,    0,   65,    2, 0x06 /* Public */,
       7,    0,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   67,    2, 0x0a /* Public */,
       9,    0,   68,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      10,    0,   69,    2, 0x02 /* Public */,
      11,    1,   70,    2, 0x02 /* Public */,
      13,    1,   73,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,   12,
    QMetaType::Void, QMetaType::QStringList,   14,

 // properties: name, type, flags
      15, 0x80000000 | 16, 0x00495009,
      17, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
       2,
       3,

       0        // eod
};

void OnvifDiscovery::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OnvifDiscovery *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Match((*reinterpret_cast< const DiscoveryMatch(*)>(_a[1]))); break;
        case 1: _t->NewMatch((*reinterpret_cast< const DiscoveryMatch(*)>(_a[1]))); break;
        case 2: _t->MatchesChanged(); break;
        case 3: _t->ActiveChanged(); break;
        case 4: _t->Start(); break;
        case 5: _t->Stop(); break;
        case 6: _t->ClearMatches(); break;
        case 7: _t->SetMatchScopes((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 8: _t->SetMatchTypes((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DiscoveryMatch >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DiscoveryMatch >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OnvifDiscovery::*)(const DiscoveryMatch & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OnvifDiscovery::Match)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (OnvifDiscovery::*)(const DiscoveryMatch & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OnvifDiscovery::NewMatch)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (OnvifDiscovery::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OnvifDiscovery::MatchesChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (OnvifDiscovery::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OnvifDiscovery::ActiveChanged)) {
                *result = 3;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<DiscoveryMatch> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<OnvifDiscovery *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<DiscoveryMatch>*>(_v) = _t->GetMatches(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->Active(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject OnvifDiscovery::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_OnvifDiscovery.data,
    qt_meta_data_OnvifDiscovery,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OnvifDiscovery::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OnvifDiscovery::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OnvifDiscovery.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int OnvifDiscovery::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void OnvifDiscovery::Match(const DiscoveryMatch & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void OnvifDiscovery::NewMatch(const DiscoveryMatch & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void OnvifDiscovery::MatchesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void OnvifDiscovery::ActiveChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
