/****************************************************************************
** Meta object code from reading C++ file 'ckernel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ckernel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ckernel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CKernel_t {
    QByteArrayData data[15];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CKernel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CKernel_t qt_meta_stringdata_CKernel = {
    {
QT_MOC_LITERAL(0, 0, 7), // "CKernel"
QT_MOC_LITERAL(1, 8, 12), // "slot_destory"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 19), // "slot_registerCommit"
QT_MOC_LITERAL(4, 42, 3), // "tel"
QT_MOC_LITERAL(5, 46, 8), // "password"
QT_MOC_LITERAL(6, 55, 4), // "name"
QT_MOC_LITERAL(7, 60, 16), // "slot_loginCommit"
QT_MOC_LITERAL(8, 77, 19), // "slot_dealClientData"
QT_MOC_LITERAL(9, 97, 7), // "lSendIP"
QT_MOC_LITERAL(10, 105, 5), // "char*"
QT_MOC_LITERAL(11, 111, 3), // "buf"
QT_MOC_LITERAL(12, 115, 4), // "nlen"
QT_MOC_LITERAL(13, 120, 16), // "slot_dealLoginRs"
QT_MOC_LITERAL(14, 137, 19) // "slot_dealRegisterRs"

    },
    "CKernel\0slot_destory\0\0slot_registerCommit\0"
    "tel\0password\0name\0slot_loginCommit\0"
    "slot_dealClientData\0lSendIP\0char*\0buf\0"
    "nlen\0slot_dealLoginRs\0slot_dealRegisterRs"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CKernel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    3,   45,    2, 0x08 /* Private */,
       7,    2,   52,    2, 0x08 /* Private */,
       8,    3,   57,    2, 0x08 /* Private */,
      13,    3,   64,    2, 0x08 /* Private */,
      14,    3,   71,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,    5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    5,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 10, QMetaType::Int,    9,   11,   12,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 10, QMetaType::Int,    9,   11,   12,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 10, QMetaType::Int,    9,   11,   12,

       0        // eod
};

void CKernel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CKernel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_destory(); break;
        case 1: _t->slot_registerCommit((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->slot_loginCommit((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->slot_dealClientData((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->slot_dealLoginRs((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: _t->slot_dealRegisterRs((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CKernel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CKernel.data,
    qt_meta_data_CKernel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CKernel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CKernel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CKernel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CKernel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
