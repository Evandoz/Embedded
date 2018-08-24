/****************************************************************************
** Meta object code from reading C++ file 'finalorder.h'
**
** Created: Thu Jul 13 08:38:43 2017
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "finalorder.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'finalorder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_finalorder[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      25,   11,   11,   11, 0x08,
      43,   38,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_finalorder[] = {
    "finalorder\0\0Button_pay()\0Button_end()\0"
    "mKey\0onBDGetKey(char)\0"
};

const QMetaObject finalorder::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_finalorder,
      qt_meta_data_finalorder, 0 }
};

const QMetaObject *finalorder::metaObject() const
{
    return &staticMetaObject;
}

void *finalorder::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_finalorder))
	return static_cast<void*>(const_cast< finalorder*>(this));
    return QWidget::qt_metacast(_clname);
}

int finalorder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Button_pay(); break;
        case 1: Button_end(); break;
        case 2: onBDGetKey((*reinterpret_cast< char(*)>(_a[1]))); break;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
