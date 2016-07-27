/****************************************************************************
** Meta object code from reading C++ file 'camera.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "camera.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camera.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_camera[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,
      15,    7,    7,    7, 0x05,
      25,    7,    7,    7, 0x05,
      45,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      68,   64,    7,    7, 0x0a,
      89,    7,    7,    7, 0x0a,
     104,    7,    7,    7, 0x0a,
     118,    7,    7,    7, 0x08,
     142,    7,    7,    7, 0x08,
     151,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_camera[] = {
    "camera\0\0back()\0clicked()\0camerastartsignal()\0"
    "stopcamerasignal()\0img\0show_picture(QImage)\0"
    "start_thread()\0stop_thread()\0"
    "on_pushButton_clicked()\0Daoche()\0"
    "on_pushButton_2_clicked()\0"
};

void camera::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        camera *_t = static_cast<camera *>(_o);
        switch (_id) {
        case 0: _t->back(); break;
        case 1: _t->clicked(); break;
        case 2: _t->camerastartsignal(); break;
        case 3: _t->stopcamerasignal(); break;
        case 4: _t->show_picture((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 5: _t->start_thread(); break;
        case 6: _t->stop_thread(); break;
        case 7: _t->on_pushButton_clicked(); break;
        case 8: _t->Daoche(); break;
        case 9: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData camera::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject camera::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_camera,
      qt_meta_data_camera, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &camera::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *camera::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *camera::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_camera))
        return static_cast<void*>(const_cast< camera*>(this));
    return QDialog::qt_metacast(_clname);
}

int camera::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void camera::back()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void camera::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void camera::camerastartsignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void camera::stopcamerasignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
