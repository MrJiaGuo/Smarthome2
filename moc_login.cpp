/****************************************************************************
** Meta object code from reading C++ file 'login.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "login.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'login.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_login_t {
    QByteArrayData data[16];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_login_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_login_t qt_meta_stringdata_login = {
    {
QT_MOC_LITERAL(0, 0, 5), // "login"
QT_MOC_LITERAL(1, 6, 17), // "on_rfidbt_clicked"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "update_rfid"
QT_MOC_LITERAL(4, 37, 14), // "on_bt1_clicked"
QT_MOC_LITERAL(5, 52, 14), // "on_bt6_clicked"
QT_MOC_LITERAL(6, 67, 14), // "on_bt2_clicked"
QT_MOC_LITERAL(7, 82, 14), // "on_bt3_clicked"
QT_MOC_LITERAL(8, 97, 14), // "on_bt4_clicked"
QT_MOC_LITERAL(9, 112, 14), // "on_bt5_clicked"
QT_MOC_LITERAL(10, 127, 14), // "on_bt7_clicked"
QT_MOC_LITERAL(11, 142, 14), // "on_bt8_clicked"
QT_MOC_LITERAL(12, 157, 14), // "on_bt9_clicked"
QT_MOC_LITERAL(13, 172, 14), // "on_bt0_clicked"
QT_MOC_LITERAL(14, 187, 20), // "on_delete_bt_clicked"
QT_MOC_LITERAL(15, 208, 19) // "on_enter_bt_clicked"

    },
    "login\0on_rfidbt_clicked\0\0update_rfid\0"
    "on_bt1_clicked\0on_bt6_clicked\0"
    "on_bt2_clicked\0on_bt3_clicked\0"
    "on_bt4_clicked\0on_bt5_clicked\0"
    "on_bt7_clicked\0on_bt8_clicked\0"
    "on_bt9_clicked\0on_bt0_clicked\0"
    "on_delete_bt_clicked\0on_enter_bt_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_login[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void login::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        login *_t = static_cast<login *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_rfidbt_clicked(); break;
        case 1: _t->update_rfid(); break;
        case 2: _t->on_bt1_clicked(); break;
        case 3: _t->on_bt6_clicked(); break;
        case 4: _t->on_bt2_clicked(); break;
        case 5: _t->on_bt3_clicked(); break;
        case 6: _t->on_bt4_clicked(); break;
        case 7: _t->on_bt5_clicked(); break;
        case 8: _t->on_bt7_clicked(); break;
        case 9: _t->on_bt8_clicked(); break;
        case 10: _t->on_bt9_clicked(); break;
        case 11: _t->on_bt0_clicked(); break;
        case 12: _t->on_delete_bt_clicked(); break;
        case 13: _t->on_enter_bt_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject login::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_login.data,
      qt_meta_data_login,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *login::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *login::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_login.stringdata0))
        return static_cast<void*>(const_cast< login*>(this));
    return QWidget::qt_metacast(_clname);
}

int login::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
