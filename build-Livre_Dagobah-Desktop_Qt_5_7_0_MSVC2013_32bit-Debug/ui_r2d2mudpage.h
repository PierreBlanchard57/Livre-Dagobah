/********************************************************************************
** Form generated from reading UI file 'r2d2mudpage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_R2D2MUDPAGE_H
#define UI_R2D2MUDPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_R2D2MudPage
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *r2d2;
    QLabel *label_3;

    void setupUi(QWidget *R2D2MudPage)
    {
        if (R2D2MudPage->objectName().isEmpty())
            R2D2MudPage->setObjectName(QStringLiteral("R2D2MudPage"));
        R2D2MudPage->resize(700, 450);
        label = new QLabel(R2D2MudPage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 701, 291));
        label->setPixmap(QPixmap(QString::fromUtf8("pages_p/swamp.jpg")));
        label->setScaledContents(true);
        label_2 = new QLabel(R2D2MudPage);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 290, 701, 161));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(248, 255, 198);"));
        label_2->setWordWrap(true);
        r2d2 = new QLabel(R2D2MudPage);
        r2d2->setObjectName(QStringLiteral("r2d2"));
        r2d2->setGeometry(QRect(450, 210, 61, 61));
        r2d2->setPixmap(QPixmap(QString::fromUtf8("pages_p/r2d2.png")));
        r2d2->setScaledContents(true);
        label_3 = new QLabel(R2D2MudPage);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 230, 701, 61));
        label_3->setPixmap(QPixmap(QString::fromUtf8("pages_p/swamp_front.png")));
        label_3->setScaledContents(true);

        retranslateUi(R2D2MudPage);

        QMetaObject::connectSlotsByName(R2D2MudPage);
    } // setupUi

    void retranslateUi(QWidget *R2D2MudPage)
    {
        R2D2MudPage->setWindowTitle(QApplication::translate("R2D2MudPage", "Form", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("R2D2MudPage", "Pendant que Luke s'entrainait, R2D2 vadroullait dans les environs et a fini par se retrouver dans une situation d\303\251licate:Il s'est embourb\303\251 dans la vase!Il essaye de se d\303\251battre pour sortir et pour cela il a besoin que l'on maintienne un clic gauche sur lui et que l'on bouge la souris autour de lui (lat\303\251ralement).Peut \303\252tre qu'avec un peu de chance il r\303\251ussira \303\240 s'extiper de ce bourbier!", 0));
        r2d2->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class R2D2MudPage: public Ui_R2D2MudPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_R2D2MUDPAGE_H
