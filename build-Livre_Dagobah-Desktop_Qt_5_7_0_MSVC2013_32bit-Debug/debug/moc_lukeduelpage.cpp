/****************************************************************************
** Meta object code from reading C++ file 'lukeduelpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lukeduelpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lukeduelpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LukeDuelPage_t {
    QByteArrayData data[10];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LukeDuelPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LukeDuelPage_t qt_meta_stringdata_LukeDuelPage = {
    {
QT_MOC_LITERAL(0, 0, 12), // "LukeDuelPage"
QT_MOC_LITERAL(1, 13, 13), // "showGameState"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 4), // "init"
QT_MOC_LITERAL(4, 33, 11), // "showSuccess"
QT_MOC_LITERAL(5, 45, 8), // "showFail"
QT_MOC_LITERAL(6, 54, 15), // "showSaberStrike"
QT_MOC_LITERAL(7, 70, 9), // "frameHook"
QT_MOC_LITERAL(8, 80, 6), // "nframe"
QT_MOC_LITERAL(9, 87, 16) // "placeTimedButton"

    },
    "LukeDuelPage\0showGameState\0\0init\0"
    "showSuccess\0showFail\0showSaberStrike\0"
    "frameHook\0nframe\0placeTimedButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LukeDuelPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x0a /* Public */,
       1,    0,   52,    2, 0x2a /* Public | MethodCloned */,
       4,    0,   53,    2, 0x0a /* Public */,
       5,    0,   54,    2, 0x0a /* Public */,
       6,    0,   55,    2, 0x0a /* Public */,
       7,    1,   56,    2, 0x0a /* Public */,
       9,    0,   59,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Bool,

       0        // eod
};

void LukeDuelPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LukeDuelPage *_t = static_cast<LukeDuelPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showGameState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->showGameState(); break;
        case 2: _t->showSuccess(); break;
        case 3: _t->showFail(); break;
        case 4: _t->showSaberStrike(); break;
        case 5: _t->frameHook((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: { bool _r = _t->placeTimedButton();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject LukeDuelPage::staticMetaObject = {
    { &Page::staticMetaObject, qt_meta_stringdata_LukeDuelPage.data,
      qt_meta_data_LukeDuelPage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LukeDuelPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LukeDuelPage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LukeDuelPage.stringdata0))
        return static_cast<void*>(const_cast< LukeDuelPage*>(this));
    return Page::qt_metacast(_clname);
}

int LukeDuelPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Page::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
