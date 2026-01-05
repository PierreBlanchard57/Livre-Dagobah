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
    QLabel *swampBackground;
    QLabel *text;
    QLabel *r2d2;
    QLabel *swampFront;
    QLabel *text2;

    void setupUi(QWidget *R2D2MudPage)
    {
        if (R2D2MudPage->objectName().isEmpty())
            R2D2MudPage->setObjectName(QStringLiteral("R2D2MudPage"));
        R2D2MudPage->resize(700, 450);
        swampBackground = new QLabel(R2D2MudPage);
        swampBackground->setObjectName(QStringLiteral("swampBackground"));
        swampBackground->setGeometry(QRect(0, 0, 701, 291));
        swampBackground->setPixmap(QPixmap(QString::fromUtf8("pages_p/swamp.jpg")));
        swampBackground->setScaledContents(true);
        text = new QLabel(R2D2MudPage);
        text->setObjectName(QStringLiteral("text"));
        text->setGeometry(QRect(0, 290, 701, 71));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        text->setFont(font);
        text->setStyleSheet(QStringLiteral("background-color: rgb(248, 255, 198);"));
        text->setWordWrap(true);
        r2d2 = new QLabel(R2D2MudPage);
        r2d2->setObjectName(QStringLiteral("r2d2"));
        r2d2->setGeometry(QRect(440, 200, 80, 80));
        r2d2->setPixmap(QPixmap(QString::fromUtf8("pages_p/r2d2.png")));
        r2d2->setScaledContents(true);
        swampFront = new QLabel(R2D2MudPage);
        swampFront->setObjectName(QStringLiteral("swampFront"));
        swampFront->setGeometry(QRect(0, 230, 700, 60));
        swampFront->setPixmap(QPixmap(QString::fromUtf8("pages_p/swamp_front.png")));
        swampFront->setScaledContents(true);
        text2 = new QLabel(R2D2MudPage);
        text2->setObjectName(QStringLiteral("text2"));
        text2->setGeometry(QRect(0, 350, 701, 101));
        text2->setFont(font);
        text2->setStyleSheet(QStringLiteral("background-color: rgb(248, 255, 198);"));
        text2->setWordWrap(true);

        retranslateUi(R2D2MudPage);

        QMetaObject::connectSlotsByName(R2D2MudPage);
    } // setupUi

    void retranslateUi(QWidget *R2D2MudPage)
    {
        R2D2MudPage->setWindowTitle(QApplication::translate("R2D2MudPage", "Form", 0));
        swampBackground->setText(QString());
        text->setText(QApplication::translate("R2D2MudPage", "Pendant que Luke s'entrainait, R2D2 vadroullait dans les environs et a fini par se retrouver dans une situation d\303\251licate:Il s'est embourb\303\251 dans la vase!", 0));
        r2d2->setText(QString());
        swampFront->setText(QString());
        text2->setText(QApplication::translate("R2D2MudPage", "Il essaye de se d\303\251battre pour sortir et pour cela il a besoin que l'on maintienne un clic gauche sur lui et que l'on bouge la souris autour de lui (lat\303\251ralement).Peut \303\252tre qu'avec un peu de chance il r\303\251ussira \303\240 s'extiper de ce bourbier", 0));
    } // retranslateUi

};

namespace Ui {
    class R2D2MudPage: public Ui_R2D2MudPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_R2D2MUDPAGE_H
