/****************************************************************************
** Meta object code from reading C++ file 'boluscalculator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/boluscalculator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'boluscalculator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BolusCalculator_t {
    QByteArrayData data[12];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BolusCalculator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BolusCalculator_t qt_meta_stringdata_BolusCalculator = {
    {
QT_MOC_LITERAL(0, 0, 15), // "BolusCalculator"
QT_MOC_LITERAL(1, 16, 12), // "navigateBack"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 14), // "navigateToHome"
QT_MOC_LITERAL(4, 45, 14), // "bolusDelivered"
QT_MOC_LITERAL(5, 60, 5), // "units"
QT_MOC_LITERAL(6, 66, 21), // "on_backButton_clicked"
QT_MOC_LITERAL(7, 88, 21), // "on_nextButton_clicked"
QT_MOC_LITERAL(8, 110, 21), // "on_homeButton_clicked"
QT_MOC_LITERAL(9, 132, 22), // "on_carbsButton_clicked"
QT_MOC_LITERAL(10, 155, 19), // "on_bgButton_clicked"
QT_MOC_LITERAL(11, 175, 32) // "on_viewCalculationButton_clicked"

    },
    "BolusCalculator\0navigateBack\0\0"
    "navigateToHome\0bolusDelivered\0units\0"
    "on_backButton_clicked\0on_nextButton_clicked\0"
    "on_homeButton_clicked\0on_carbsButton_clicked\0"
    "on_bgButton_clicked\0"
    "on_viewCalculationButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BolusCalculator[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    1,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   64,    2, 0x08 /* Private */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BolusCalculator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BolusCalculator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->navigateBack(); break;
        case 1: _t->navigateToHome(); break;
        case 2: _t->bolusDelivered((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->on_backButton_clicked(); break;
        case 4: _t->on_nextButton_clicked(); break;
        case 5: _t->on_homeButton_clicked(); break;
        case 6: _t->on_carbsButton_clicked(); break;
        case 7: _t->on_bgButton_clicked(); break;
        case 8: _t->on_viewCalculationButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BolusCalculator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BolusCalculator::navigateBack)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BolusCalculator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BolusCalculator::navigateToHome)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BolusCalculator::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BolusCalculator::bolusDelivered)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BolusCalculator::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_BolusCalculator.data,
    qt_meta_data_BolusCalculator,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BolusCalculator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BolusCalculator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BolusCalculator.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int BolusCalculator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void BolusCalculator::navigateBack()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BolusCalculator::navigateToHome()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void BolusCalculator::bolusDelivered(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
