/****************************************************************************
** Meta object code from reading C++ file 'combined.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lab/combined.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'combined.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_combined_t {
    QByteArrayData data[13];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_combined_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_combined_t qt_meta_stringdata_combined = {
    {
QT_MOC_LITERAL(0, 0, 8), // "combined"
QT_MOC_LITERAL(1, 9, 15), // "on_Badd_clicked"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 18), // "on_Bdelete_clicked"
QT_MOC_LITERAL(4, 45, 32), // "on_tableWidget_itemDoubleClicked"
QT_MOC_LITERAL(5, 78, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(6, 96, 4), // "item"
QT_MOC_LITERAL(7, 101, 18), // "on_Bselect_clicked"
QT_MOC_LITERAL(8, 120, 26), // "on_tableView_doubleClicked"
QT_MOC_LITERAL(9, 147, 11), // "QModelIndex"
QT_MOC_LITERAL(10, 159, 5), // "index"
QT_MOC_LITERAL(11, 165, 20), // "on_tableView_clicked"
QT_MOC_LITERAL(12, 186, 16) // "on_Bnext_clicked"

    },
    "combined\0on_Badd_clicked\0\0on_Bdelete_clicked\0"
    "on_tableWidget_itemDoubleClicked\0"
    "QTableWidgetItem*\0item\0on_Bselect_clicked\0"
    "on_tableView_doubleClicked\0QModelIndex\0"
    "index\0on_tableView_clicked\0on_Bnext_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_combined[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    1,   51,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    1,   55,    2, 0x08 /* Private */,
      11,    1,   58,    2, 0x08 /* Private */,
      12,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,

       0        // eod
};

void combined::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        combined *_t = static_cast<combined *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Badd_clicked(); break;
        case 1: _t->on_Bdelete_clicked(); break;
//        case 2: _t->on_tableWidget_itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->on_Bselect_clicked(); break;
        case 4: _t->on_tableView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_tableView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->on_Bnext_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject combined::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_combined.data,
    qt_meta_data_combined,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *combined::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *combined::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_combined.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int combined::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
