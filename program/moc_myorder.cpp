/****************************************************************************
** Meta object code from reading C++ file 'myorder.h'
**
** Created: Thu Jul 13 08:38:45 2017
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "myorder.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myorder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_myorder[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      33,    8,    8,    8, 0x08,
      42,    8,    8,    8, 0x08,
      58,    8,    8,    8, 0x08,
      74,    8,    8,    8, 0x08,
      91,    8,    8,    8, 0x08,
     106,    8,    8,    8, 0x08,
     127,  122,    8,    8, 0x08,
     150,  144,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_myorder[] = {
    "myorder\0\0Button_return_clicked()\0"
    "search()\0Button_delete()\0Button_modify()\0"
    "Button_refresh()\0Button_clear()\0"
    "Button_submit()\0mKey\0onBDGetKey(char)\0"
    "index\0RowClicked(QModelIndex)\0"
};

const QMetaObject myorder::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_myorder,
      qt_meta_data_myorder, 0 }
};

const QMetaObject *myorder::metaObject() const
{
    return &staticMetaObject;
}

void *myorder::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_myorder))
	return static_cast<void*>(const_cast< myorder*>(this));
    return QWidget::qt_metacast(_clname);
}

int myorder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Button_return_clicked(); break;
        case 1: search(); break;
        case 2: Button_delete(); break;
        case 3: Button_modify(); break;
        case 4: Button_refresh(); break;
        case 5: Button_clear(); break;
        case 6: Button_submit(); break;
        case 7: onBDGetKey((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 8: RowClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
