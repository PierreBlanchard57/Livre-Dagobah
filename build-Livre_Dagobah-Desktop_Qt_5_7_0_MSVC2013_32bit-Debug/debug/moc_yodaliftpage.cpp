/****************************************************************************
** Meta object code from reading C++ file 'yodaliftpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../yodaliftpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'yodaliftpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_YodaLiftPage_t {
    QByteArrayData data[9];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_YodaLiftPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_YodaLiftPage_t qt_meta_stringdata_YodaLiftPage = {
    {
QT_MOC_LITERAL(0, 0, 12), // "YodaLiftPage"
QT_MOC_LITERAL(1, 13, 13), // "showGameState"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "showFail"
QT_MOC_LITERAL(4, 37, 11), // "showSuccess"
QT_MOC_LITERAL(5, 49, 9), // "showIntro"
QT_MOC_LITERAL(6, 59, 10), // "startMusic"
QT_MOC_LITERAL(7, 70, 15), // "updateGameState"
QT_MOC_LITERAL(8, 86, 11) // "involveGame"

    },
    "YodaLiftPage\0showGameState\0\0showFail\0"
    "showSuccess\0showIntro\0startMusic\0"
    "updateGameState\0involveGame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_YodaLiftPage[] = {

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
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    1,   52,    2, 0x0a /* Public */,
       5,    0,   55,    2, 0x2a /* Public | MethodCloned */,
       7,    0,   56,    2, 0x0a /* Public */,
       8,    0,   57,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void YodaLiftPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        YodaLiftPage *_t = static_cast<YodaLiftPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showGameState(); break;
        case 1: _t->showFail(); break;
        case 2: _t->showSuccess(); break;
        case 3: _t->showIntro((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->showIntro(); break;
        case 5: _t->updateGameState(); break;
        case 6: _t->involveGame(); break;
        default: ;
        }
    }
}

const QMetaObject YodaLiftPage::staticMetaObject = {
    { &Page::staticMetaObject, qt_meta_stringdata_YodaLiftPage.data,
      qt_meta_data_YodaLiftPage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *YodaLiftPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *YodaLiftPage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_YodaLiftPage.stringdata0))
        return static_cast<void*>(const_cast< YodaLiftPage*>(this));
    return Page::qt_metacast(_clname);
}

int YodaLiftPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
