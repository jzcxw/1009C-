/****************************************************************************
** Meta object code from reading C++ file 'teachereditquiz.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../teachereditquiz.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'teachereditquiz.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_teacherEditQuiz_t {
    QByteArrayData data[10];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_teacherEditQuiz_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_teacherEditQuiz_t qt_meta_stringdata_teacherEditQuiz = {
    {
QT_MOC_LITERAL(0, 0, 15), // "teacherEditQuiz"
QT_MOC_LITERAL(1, 16, 18), // "on_homeBtn_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 22), // "on_viewquizBtn_clicked"
QT_MOC_LITERAL(4, 59, 24), // "on_createquizBtn_clicked"
QT_MOC_LITERAL(5, 84, 30), // "on_viewquiz_deletequiz_clicked"
QT_MOC_LITERAL(6, 115, 29), // "on_viewquiz_addnewqns_clicked"
QT_MOC_LITERAL(7, 145, 26), // "on_chertableView_activated"
QT_MOC_LITERAL(8, 172, 5), // "index"
QT_MOC_LITERAL(9, 178, 30) // "on_chertableView_doubleClicked"

    },
    "teacherEditQuiz\0on_homeBtn_clicked\0\0"
    "on_viewquizBtn_clicked\0on_createquizBtn_clicked\0"
    "on_viewquiz_deletequiz_clicked\0"
    "on_viewquiz_addnewqns_clicked\0"
    "on_chertableView_activated\0index\0"
    "on_chertableView_doubleClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_teacherEditQuiz[] = {

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
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    1,   54,    2, 0x08 /* Private */,
       9,    1,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void, QMetaType::QModelIndex,    8,

       0        // eod
};

void teacherEditQuiz::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        teacherEditQuiz *_t = static_cast<teacherEditQuiz *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_homeBtn_clicked(); break;
        case 1: _t->on_viewquizBtn_clicked(); break;
        case 2: _t->on_createquizBtn_clicked(); break;
        case 3: _t->on_viewquiz_deletequiz_clicked(); break;
        case 4: _t->on_viewquiz_addnewqns_clicked(); break;
        case 5: _t->on_chertableView_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->on_chertableView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject teacherEditQuiz::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_teacherEditQuiz.data,
      qt_meta_data_teacherEditQuiz,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *teacherEditQuiz::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *teacherEditQuiz::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_teacherEditQuiz.stringdata0))
        return static_cast<void*>(const_cast< teacherEditQuiz*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int teacherEditQuiz::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
