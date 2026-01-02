/********************************************************************************
** Form generated from reading UI file 'titlepage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLEPAGE_H
#define UI_TITLEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TitlePage
{
public:
    QLabel *label;

    void setupUi(QWidget *TitlePage)
    {
        if (TitlePage->objectName().isEmpty())
            TitlePage->setObjectName(QStringLiteral("TitlePage"));
        TitlePage->resize(700, 450);
        TitlePage->setAutoFillBackground(false);
        TitlePage->setStyleSheet(QStringLiteral("background-color: rgb(130, 130, 130);"));
        label = new QLabel(TitlePage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 700, 450));
        label->setPixmap(QPixmap(QString::fromUtf8("couverture.jpg")));

        retranslateUi(TitlePage);

        QMetaObject::connectSlotsByName(TitlePage);
    } // setupUi

    void retranslateUi(QWidget *TitlePage)
    {
        TitlePage->setWindowTitle(QApplication::translate("TitlePage", "Form", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TitlePage: public Ui_TitlePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLEPAGE_H
