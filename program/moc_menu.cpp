/****************************************************************************
** Meta object code from reading C++ file 'menu.h'
**
** Created: Thu Jul 13 08:38:44 2017
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "menu.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_menu[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x08,
      20,    5,    5,    5, 0x08,
      29,    5,    5,    5, 0x08,
      49,    5,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_menu[] = {
    "menu\0\0timerUpDate()\0search()\0"
    "Button_my_clicked()\0Button_add_clicked()\0"
};

const QMetaObject menu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_menu,
      qt_meta_data_menu, 0 }
};

const QMetaObject *menu::metaObject() const
{
    return &staticMetaObject;
}

void *menu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_menu))
	return static_cast<void*>(const_cast< menu*>(this));
    return QWidget::qt_metacast(_clname);
}

int menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: timerUpDate(); break;
        case 1: search(); break;
        case 2: Button_my_clicked(); break;
        case 3: Button_add_clicked(); break;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
