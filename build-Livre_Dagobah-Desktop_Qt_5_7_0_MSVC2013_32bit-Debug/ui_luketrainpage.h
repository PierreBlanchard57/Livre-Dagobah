/********************************************************************************
** Form generated from reading UI file 'luketrainpage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LUKETRAINPAGE_H
#define UI_LUKETRAINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "rockobject.h"
#include <QObject>

QT_BEGIN_NAMESPACE

class Ui_LukeTrainPage
{
public:
    QLabel *label;
    QLabel *luke;
    QLabel *rockBase;
    QLabel *text1;
    RockObject *rock1;
    RockObject *rock2;
    RockObject *rock3;
    QLabel *text2;

    void setupUi(QWidget *LukeTrainPage)
    {
        if (LukeTrainPage->objectName().isEmpty())
            LukeTrainPage->setObjectName(QStringLiteral("LukeTrainPage"));
        LukeTrainPage->resize(700, 450);
        label = new QLabel(LukeTrainPage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 700, 300));
        label->setPixmap(QPixmap(QString::fromUtf8("pages_p/training.png")));
        label->setScaledContents(true);
        luke = new QLabel(LukeTrainPage);
        luke->setObjectName(QStringLiteral("luke"));
        luke->setGeometry(QRect(140, 110, 51, 111));
        luke->setPixmap(QPixmap(QString::fromUtf8("pages_p/luke_normal.png")));
        luke->setScaledContents(true);
        rockBase = new QLabel(LukeTrainPage);
        rockBase->setObjectName(QStringLiteral("rockBase"));
        rockBase->setGeometry(QRect(460, 190, 50, 30));
        rockBase->setPixmap(QPixmap(QString::fromUtf8("pages_p/rock_base.png")));
        rockBase->setScaledContents(true);
        text1 = new QLabel(LukeTrainPage);
        text1->setObjectName(QStringLiteral("text1"));
        text1->setGeometry(QRect(0, 300, 701, 71));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        text1->setFont(font);
        text1->setAutoFillBackground(false);
        text1->setStyleSheet(QStringLiteral("background-color: rgb(254, 255, 194);"));
        text1->setTextFormat(Qt::RichText);
        text1->setWordWrap(true);
        std::vector<QObject*> c1={rock2,rock3,rockBase};
        rock1 = new RockObject(LukeTrainPage,QStringLiteral("rock1"),QRect(210, 200, 40, 20),c1);
        /*rock1->setObjectName(QStringLiteral("rock1"));
        rock1->setGeometry(QRect(210, 200, 40, 20));
        rock1->setPixmap(QPixmap(QString::fromUtf8("pages_p/rock_object.png")));
        rock1->setScaledContents(true);*/
        std::vector<QObject*> c2={rock1,rock3,rockBase};
        rock2 = new RockObject(LukeTrainPage,QStringLiteral("rock2"),QRect(260, 200, 40, 20),c2);
        /*rock2->setObjectName(QStringLiteral("rock2"));
        rock2->setGeometry(QRect(260, 200, 40, 20));
        rock2->setPixmap(QPixmap(QString::fromUtf8("pages_p/rock_object.png")));
        rock2->setScaledContents(true);*/
        std::vector<QObject*> c3={rock1,rock2,rockBase};
        rock3 = new RockObject(LukeTrainPage,QStringLiteral("rock3"),QRect(320, 200, 40, 20),c3);
        /*rock3->setObjectName(QStringLiteral("rock3"));
        rock3->setGeometry(QRect(320, 200, 40, 20));
        rock3->setPixmap(QPixmap(QString::fromUtf8("pages_p/rock_object.png")));
        rock3->setScaledContents(true);*/
        text2 = new QLabel(LukeTrainPage);
        text2->setObjectName(QStringLiteral("text2"));
        text2->setGeometry(QRect(0, 370, 701, 61));
        text2->setFont(font);
        text2->setAutoFillBackground(false);
        text2->setStyleSheet(QStringLiteral("background-color: rgb(254, 255, 194);"));
        text2->setTextFormat(Qt::RichText);
        text2->setWordWrap(true);

        retranslateUi(LukeTrainPage);

        QMetaObject::connectSlotsByName(LukeTrainPage);
    } // setupUi

    void retranslateUi(QWidget *LukeTrainPage)
    {
        LukeTrainPage->setWindowTitle(QApplication::translate("LukeTrainPage", "Form", 0));
        label->setText(QString());
        luke->setText(QString());
        rockBase->setText(QString());
        text1->setText(QApplication::translate("LukeTrainPage", "Luke commence son entra\303\256nement avec Yoda. Il doit d\303\251placer trois rochers blancs \303\240 l\342\200\231aide de la Force et les empiler sur le rocher noir. ", 0));
        rock1->setText(QString());
        rock2->setText(QString());
        rock3->setText(QString());
        text2->setText(QApplication::translate("LukeTrainPage", "Pour utiliser la Force, Luke doit cliquer sur un rocher blanc avec le bouton gauche de la souris, puis maintenir le clic enfonc\303\251 tout en d\303\251pla\303\247ant la souris. Il pourra rel\303\242cher le clic pour arr\303\252ter l\342\200\231utilisation de la Force.", 0));
    } // retranslateUi

};

namespace Ui {
    class LukeTrainPage: public Ui_LukeTrainPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LUKETRAINPAGE_H
