/****************************************************************************
** Meta object code from reading C++ file 'accviewserv.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../accviewserv.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'accviewserv.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AccViewServ[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      28,   12,   12,   12, 0x0a,
      46,   12,   12,   12, 0x0a,
      67,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AccViewServ[] = {
    "AccViewServ\0\0on_connexion()\0"
    "on_disconnected()\0on_m_send_released()\0"
    "on_timer()\0"
};

void AccViewServ::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AccViewServ *_t = static_cast<AccViewServ *>(_o);
        switch (_id) {
        case 0: _t->on_connexion(); break;
        case 1: _t->on_disconnected(); break;
        case 2: _t->on_m_send_released(); break;
        case 3: _t->on_timer(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData AccViewServ::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AccViewServ::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AccViewServ,
      qt_meta_data_AccViewServ, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AccViewServ::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AccViewServ::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AccViewServ::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AccViewServ))
        return static_cast<void*>(const_cast< AccViewServ*>(this));
    if (!strcmp(_clname, "AccManager"))
        return static_cast< AccManager*>(const_cast< AccViewServ*>(this));
    return QDialog::qt_metacast(_clname);
}

int AccViewServ::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
