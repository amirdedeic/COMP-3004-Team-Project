/****************************************************************************
** Meta object code from reading C++ file 'simulation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/simulation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simulation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Simulation_t {
    QByteArrayData data[20];
    char stringdata0[270];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Simulation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Simulation_t qt_meta_stringdata_Simulation = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Simulation"
QT_MOC_LITERAL(1, 11, 17), // "simulationUpdated"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 19), // "glucoseLevelChanged"
QT_MOC_LITERAL(4, 50, 8), // "newLevel"
QT_MOC_LITERAL(5, 59, 15), // "profilesChanged"
QT_MOC_LITERAL(6, 75, 21), // "controlIQStateChanged"
QT_MOC_LITERAL(7, 97, 7), // "enabled"
QT_MOC_LITERAL(8, 105, 20), // "controlIQModeChanged"
QT_MOC_LITERAL(9, 126, 4), // "mode"
QT_MOC_LITERAL(10, 131, 19), // "batteryLevelChanged"
QT_MOC_LITERAL(11, 151, 5), // "level"
QT_MOC_LITERAL(12, 157, 21), // "insulinOnBoardChanged"
QT_MOC_LITERAL(13, 179, 3), // "iob"
QT_MOC_LITERAL(14, 183, 19), // "insulinLevelChanged"
QT_MOC_LITERAL(15, 203, 16), // "cgmStatusChanged"
QT_MOC_LITERAL(16, 220, 6), // "active"
QT_MOC_LITERAL(17, 227, 19), // "glucoseTrendChanged"
QT_MOC_LITERAL(18, 247, 5), // "trend"
QT_MOC_LITERAL(19, 253, 16) // "updateSimulation"

    },
    "Simulation\0simulationUpdated\0\0"
    "glucoseLevelChanged\0newLevel\0"
    "profilesChanged\0controlIQStateChanged\0"
    "enabled\0controlIQModeChanged\0mode\0"
    "batteryLevelChanged\0level\0"
    "insulinOnBoardChanged\0iob\0insulinLevelChanged\0"
    "cgmStatusChanged\0active\0glucoseTrendChanged\0"
    "trend\0updateSimulation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Simulation[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    1,   70,    2, 0x06 /* Public */,
       5,    0,   73,    2, 0x06 /* Public */,
       6,    1,   74,    2, 0x06 /* Public */,
       8,    1,   77,    2, 0x06 /* Public */,
      10,    1,   80,    2, 0x06 /* Public */,
      12,    1,   83,    2, 0x06 /* Public */,
      14,    1,   86,    2, 0x06 /* Public */,
      15,    1,   89,    2, 0x06 /* Public */,
      17,    1,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    0,   95,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double,   13,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::QString,   18,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Simulation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Simulation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->simulationUpdated(); break;
        case 1: _t->glucoseLevelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->profilesChanged(); break;
        case 3: _t->controlIQStateChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->controlIQModeChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->batteryLevelChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->insulinOnBoardChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->insulinLevelChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->cgmStatusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->glucoseTrendChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->updateSimulation(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Simulation::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Simulation::simulationUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Simulation::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Simulation::glucoseLevelChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Simulation::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Simulation::profilesChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Simulation::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Simulation::controlIQStateChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Simulation::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Simulation::controlIQModeChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Simulation::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Simulation::batteryLevelChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Simulation::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Simulation::insulinOnBoardChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Simulation::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Simulation::insulinLevelChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Simulation::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Simulation::cgmStatusChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Simulation::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Simulation::glucoseTrendChanged)) {
                *result = 9;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Simulation::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Simulation.data,
    qt_meta_data_Simulation,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Simulation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Simulation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Simulation.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Simulation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Simulation::simulationUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Simulation::glucoseLevelChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Simulation::profilesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Simulation::controlIQStateChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Simulation::controlIQModeChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Simulation::batteryLevelChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Simulation::insulinOnBoardChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Simulation::insulinLevelChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Simulation::cgmStatusChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Simulation::glucoseTrendChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
