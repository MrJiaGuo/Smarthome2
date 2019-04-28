/****************************************************************************
** Meta object code from reading C++ file 'adcbeep.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "adcbeep.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adcbeep.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AdcBeep_t {
    QByteArrayData data[8];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdcBeep_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdcBeep_t qt_meta_stringdata_AdcBeep = {
    {
QT_MOC_LITERAL(0, 0, 7), // "AdcBeep"
QT_MOC_LITERAL(1, 8, 19), // "on_returnBt_clicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "dealDone"
QT_MOC_LITERAL(4, 38, 3), // "num"
QT_MOC_LITERAL(5, 42, 13), // "SR04_dealDone"
QT_MOC_LITERAL(6, 56, 17), // "on_firebt_clicked"
QT_MOC_LITERAL(7, 74, 17) // "on_sr04bt_clicked"

    },
    "AdcBeep\0on_returnBt_clicked\0\0dealDone\0"
    "num\0SR04_dealDone\0on_firebt_clicked\0"
    "on_sr04bt_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdcBeep[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    1,   40,    2, 0x08 /* Private */,
       5,    1,   43,    2, 0x08 /* Private */,
       6,    0,   46,    2, 0x08 /* Private */,
       7,    0,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AdcBeep::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AdcBeep *_t = static_cast<AdcBeep *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_returnBt_clicked(); break;
        case 1: _t->dealDone((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->SR04_dealDone((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_firebt_clicked(); break;
        case 4: _t->on_sr04bt_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject AdcBeep::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AdcBeep.data,
      qt_meta_data_AdcBeep,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AdcBeep::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdcBeep::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AdcBeep.stringdata0))
        return static_cast<void*>(const_cast< AdcBeep*>(this));
    return QWidget::qt_metacast(_clname);
}

int AdcBeep::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
