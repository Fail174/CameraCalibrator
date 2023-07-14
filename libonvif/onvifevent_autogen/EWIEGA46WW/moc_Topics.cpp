/****************************************************************************
** Meta object code from reading C++ file 'Topics.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Topics.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Topics.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SimpleItem_t {
    QByteArrayData data[5];
    char stringdata0[42];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SimpleItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SimpleItem_t qt_meta_stringdata_SimpleItem = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SimpleItem"
QT_MOC_LITERAL(1, 11, 4), // "name"
QT_MOC_LITERAL(2, 16, 5), // "value"
QT_MOC_LITERAL(3, 22, 4), // "type"
QT_MOC_LITERAL(4, 27, 14) // "SimpleItemType"

    },
    "SimpleItem\0name\0value\0type\0SimpleItemType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SimpleItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       3,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       4,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095001,
       2, QMetaType::QVariant, 0x00095001,
       3, 0x80000000 | 4, 0x00095009,

       0        // eod
};

void SimpleItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        auto *_t = reinterpret_cast<SimpleItem *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->GetName(); break;
        case 1: *reinterpret_cast< QVariant*>(_v) = _t->GetValue(); break;
        case 2: *reinterpret_cast< SimpleItemType*>(_v) = _t->GetType(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject SimpleItem::staticMetaObject = { {
    nullptr,
    qt_meta_stringdata_SimpleItem.data,
    qt_meta_data_SimpleItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };

struct qt_meta_stringdata_Topic_t {
    QByteArrayData data[1];
    char stringdata0[6];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Topic_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Topic_t qt_meta_stringdata_Topic = {
    {
QT_MOC_LITERAL(0, 0, 5) // "Topic"

    },
    "Topic"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Topic[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       4,       // flags
       0,       // signalCount

       0        // eod
};

QT_INIT_METAOBJECT const QMetaObject Topic::staticMetaObject = { {
    nullptr,
    qt_meta_stringdata_Topic.data,
    qt_meta_data_Topic,
    nullptr,
    nullptr,
    nullptr
} };

QT_WARNING_POP
QT_END_MOC_NAMESPACE
