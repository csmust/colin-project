/****************************************************************************
** Meta object code from reading C++ file 'maindialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../maindialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maindialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainDialog_t {
    QByteArrayData data[56];
    char stringdata0[905];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainDialog_t qt_meta_stringdata_MainDialog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainDialog"
QT_MOC_LITERAL(1, 11, 9), // "SIG_close"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 14), // "SIG_uploadFile"
QT_MOC_LITERAL(4, 37, 4), // "path"
QT_MOC_LITERAL(5, 42, 3), // "dir"
QT_MOC_LITERAL(6, 46, 16), // "SIG_uploadFolder"
QT_MOC_LITERAL(7, 63, 16), // "SIG_downloadFile"
QT_MOC_LITERAL(8, 80, 6), // "fileid"
QT_MOC_LITERAL(9, 87, 18), // "SIG_downloadFolder"
QT_MOC_LITERAL(10, 106, 13), // "SIG_addFolder"
QT_MOC_LITERAL(11, 120, 4), // "name"
QT_MOC_LITERAL(12, 125, 13), // "SIG_changeDir"
QT_MOC_LITERAL(13, 139, 13), // "SIG_shareFile"
QT_MOC_LITERAL(14, 153, 12), // "QVector<int>"
QT_MOC_LITERAL(15, 166, 11), // "fileidArray"
QT_MOC_LITERAL(16, 178, 18), // "SIG_getShareByLink"
QT_MOC_LITERAL(17, 197, 4), // "code"
QT_MOC_LITERAL(18, 202, 18), // "on_pb_file_clicked"
QT_MOC_LITERAL(19, 221, 22), // "on_pb_transmit_clicked"
QT_MOC_LITERAL(20, 244, 19), // "on_pb_share_clicked"
QT_MOC_LITERAL(21, 264, 21), // "on_pb_addFile_clicked"
QT_MOC_LITERAL(22, 286, 14), // "slot_addFolder"
QT_MOC_LITERAL(23, 301, 4), // "flag"
QT_MOC_LITERAL(24, 306, 15), // "slot_uploadFile"
QT_MOC_LITERAL(25, 322, 17), // "slot_uploadFolder"
QT_MOC_LITERAL(26, 340, 17), // "slot_downloadFile"
QT_MOC_LITERAL(27, 358, 14), // "slot_shareFile"
QT_MOC_LITERAL(28, 373, 15), // "slot_deleteFile"
QT_MOC_LITERAL(29, 389, 21), // "slot_insertUploadFile"
QT_MOC_LITERAL(30, 411, 9), // "FileInfo&"
QT_MOC_LITERAL(31, 421, 4), // "info"
QT_MOC_LITERAL(32, 426, 23), // "slot_insertDownloadFile"
QT_MOC_LITERAL(33, 450, 25), // "slot_insertUploadComplete"
QT_MOC_LITERAL(34, 476, 27), // "slot_insertDownloadComplete"
QT_MOC_LITERAL(35, 504, 24), // "slot_insertShareFileInfo"
QT_MOC_LITERAL(36, 529, 4), // "size"
QT_MOC_LITERAL(37, 534, 4), // "time"
QT_MOC_LITERAL(38, 539, 9), // "shareLink"
QT_MOC_LITERAL(39, 549, 29), // "slot_updateUploadFileProgress"
QT_MOC_LITERAL(40, 579, 9), // "timestamp"
QT_MOC_LITERAL(41, 589, 3), // "pos"
QT_MOC_LITERAL(42, 593, 31), // "slot_updateDownloadFileProgress"
QT_MOC_LITERAL(43, 625, 26), // "slot_deleteUploadFileByRow"
QT_MOC_LITERAL(44, 652, 3), // "row"
QT_MOC_LITERAL(45, 656, 28), // "slot_deleteDownloadFileByRow"
QT_MOC_LITERAL(46, 685, 19), // "slot_insertFileInfo"
QT_MOC_LITERAL(47, 705, 13), // "slot_openPath"
QT_MOC_LITERAL(48, 719, 22), // "slot_deleteAllFileInfo"
QT_MOC_LITERAL(49, 742, 23), // "slot_deleteAllShareInfo"
QT_MOC_LITERAL(50, 766, 13), // "slot_getShare"
QT_MOC_LITERAL(51, 780, 25), // "on_table_file_cellClicked"
QT_MOC_LITERAL(52, 806, 6), // "column"
QT_MOC_LITERAL(53, 813, 40), // "on_table_file_customContextMe..."
QT_MOC_LITERAL(54, 854, 31), // "on_table_file_cellDoubleClicked"
QT_MOC_LITERAL(55, 886, 18) // "on_pb_prev_clicked"

    },
    "MainDialog\0SIG_close\0\0SIG_uploadFile\0"
    "path\0dir\0SIG_uploadFolder\0SIG_downloadFile\0"
    "fileid\0SIG_downloadFolder\0SIG_addFolder\0"
    "name\0SIG_changeDir\0SIG_shareFile\0"
    "QVector<int>\0fileidArray\0SIG_getShareByLink\0"
    "code\0on_pb_file_clicked\0on_pb_transmit_clicked\0"
    "on_pb_share_clicked\0on_pb_addFile_clicked\0"
    "slot_addFolder\0flag\0slot_uploadFile\0"
    "slot_uploadFolder\0slot_downloadFile\0"
    "slot_shareFile\0slot_deleteFile\0"
    "slot_insertUploadFile\0FileInfo&\0info\0"
    "slot_insertDownloadFile\0"
    "slot_insertUploadComplete\0"
    "slot_insertDownloadComplete\0"
    "slot_insertShareFileInfo\0size\0time\0"
    "shareLink\0slot_updateUploadFileProgress\0"
    "timestamp\0pos\0slot_updateDownloadFileProgress\0"
    "slot_deleteUploadFileByRow\0row\0"
    "slot_deleteDownloadFileByRow\0"
    "slot_insertFileInfo\0slot_openPath\0"
    "slot_deleteAllFileInfo\0slot_deleteAllShareInfo\0"
    "slot_getShare\0on_table_file_cellClicked\0"
    "column\0on_table_file_customContextMenuRequested\0"
    "on_table_file_cellDoubleClicked\0"
    "on_pb_prev_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      37,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  199,    2, 0x06 /* Public */,
       3,    2,  200,    2, 0x06 /* Public */,
       6,    2,  205,    2, 0x06 /* Public */,
       7,    2,  210,    2, 0x06 /* Public */,
       9,    2,  215,    2, 0x06 /* Public */,
      10,    2,  220,    2, 0x06 /* Public */,
      12,    1,  225,    2, 0x06 /* Public */,
      13,    2,  228,    2, 0x06 /* Public */,
      16,    2,  233,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    0,  238,    2, 0x08 /* Private */,
      19,    0,  239,    2, 0x08 /* Private */,
      20,    0,  240,    2, 0x08 /* Private */,
      21,    0,  241,    2, 0x08 /* Private */,
      22,    1,  242,    2, 0x08 /* Private */,
      24,    1,  245,    2, 0x08 /* Private */,
      25,    1,  248,    2, 0x08 /* Private */,
      26,    1,  251,    2, 0x08 /* Private */,
      27,    1,  254,    2, 0x08 /* Private */,
      28,    1,  257,    2, 0x08 /* Private */,
      29,    1,  260,    2, 0x08 /* Private */,
      32,    1,  263,    2, 0x08 /* Private */,
      33,    1,  266,    2, 0x08 /* Private */,
      34,    1,  269,    2, 0x08 /* Private */,
      35,    4,  272,    2, 0x08 /* Private */,
      39,    2,  281,    2, 0x08 /* Private */,
      42,    2,  286,    2, 0x08 /* Private */,
      43,    1,  291,    2, 0x08 /* Private */,
      45,    1,  294,    2, 0x08 /* Private */,
      46,    1,  297,    2, 0x08 /* Private */,
      47,    1,  300,    2, 0x08 /* Private */,
      48,    0,  303,    2, 0x08 /* Private */,
      49,    0,  304,    2, 0x08 /* Private */,
      50,    1,  305,    2, 0x08 /* Private */,
      51,    2,  308,    2, 0x08 /* Private */,
      53,    1,  313,    2, 0x08 /* Private */,
      54,    2,  316,    2, 0x08 /* Private */,
      55,    0,  321,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    8,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    8,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 14, QMetaType::QString,   15,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   17,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void, 0x80000000 | 30,   31,
    QMetaType::Void, 0x80000000 | 30,   31,
    QMetaType::Void, 0x80000000 | 30,   31,
    QMetaType::Void, 0x80000000 | 30,   31,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Int,   11,   36,   37,   38,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   40,   41,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   40,   41,
    QMetaType::Void, QMetaType::Int,   44,
    QMetaType::Void, QMetaType::Int,   44,
    QMetaType::Void, 0x80000000 | 30,   31,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   44,   52,
    QMetaType::Void, QMetaType::QPoint,   41,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   44,   52,
    QMetaType::Void,

       0        // eod
};

void MainDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_close(); break;
        case 1: _t->SIG_uploadFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->SIG_uploadFolder((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->SIG_downloadFile((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->SIG_downloadFolder((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->SIG_addFolder((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->SIG_changeDir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->SIG_shareFile((*reinterpret_cast< QVector<int>(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->SIG_getShareByLink((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->on_pb_file_clicked(); break;
        case 10: _t->on_pb_transmit_clicked(); break;
        case 11: _t->on_pb_share_clicked(); break;
        case 12: _t->on_pb_addFile_clicked(); break;
        case 13: _t->slot_addFolder((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->slot_uploadFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->slot_uploadFolder((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->slot_downloadFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->slot_shareFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->slot_deleteFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->slot_insertUploadFile((*reinterpret_cast< FileInfo(*)>(_a[1]))); break;
        case 20: _t->slot_insertDownloadFile((*reinterpret_cast< FileInfo(*)>(_a[1]))); break;
        case 21: _t->slot_insertUploadComplete((*reinterpret_cast< FileInfo(*)>(_a[1]))); break;
        case 22: _t->slot_insertDownloadComplete((*reinterpret_cast< FileInfo(*)>(_a[1]))); break;
        case 23: _t->slot_insertShareFileInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 24: _t->slot_updateUploadFileProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 25: _t->slot_updateDownloadFileProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 26: _t->slot_deleteUploadFileByRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->slot_deleteDownloadFileByRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->slot_insertFileInfo((*reinterpret_cast< FileInfo(*)>(_a[1]))); break;
        case 29: _t->slot_openPath((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->slot_deleteAllFileInfo(); break;
        case 31: _t->slot_deleteAllShareInfo(); break;
        case 32: _t->slot_getShare((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->on_table_file_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 34: _t->on_table_file_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 35: _t->on_table_file_cellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 36: _t->on_pb_prev_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainDialog::SIG_close)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainDialog::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainDialog::SIG_uploadFile)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainDialog::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainDialog::SIG_uploadFolder)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainDialog::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainDialog::SIG_downloadFile)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainDialog::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainDialog::SIG_downloadFolder)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainDialog::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainDialog::SIG_addFolder)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainDialog::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainDialog::SIG_changeDir)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainDialog::*)(QVector<int> , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainDialog::SIG_shareFile)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MainDialog::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainDialog::SIG_getShareByLink)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_MainDialog.data,
    qt_meta_data_MainDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int MainDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    }
    return _id;
}

// SIGNAL 0
void MainDialog::SIG_close()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainDialog::SIG_uploadFile(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainDialog::SIG_uploadFolder(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainDialog::SIG_downloadFile(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainDialog::SIG_downloadFolder(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainDialog::SIG_addFolder(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainDialog::SIG_changeDir(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainDialog::SIG_shareFile(QVector<int> _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainDialog::SIG_getShareByLink(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
