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

class Ui_title
{
public:
    QLabel *label;

    void setupUi(QWidget *TitlePage)
    {
        if (TitlePage->objectName().isEmpty())
            TitlePage->setObjectName(QStringLiteral("TitlePage"));
        TitlePage->resize(400, 300);
        label = new QLabel(TitlePage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 331, 171));
        QFont font;
        font.setPointSize(36);
        label->setFont(font);

        retranslateUi(TitlePage);

        QMetaObject::connectSlotsByName(TitlePage);
    } // setupUi

    void retranslateUi(QWidget *TitlePage)
    {
        TitlePage->setWindowTitle(QApplication::translate("Form", "Form", 0));
        label->setText(QApplication::translate("Form", "Je suis un titre", 0));
    } // retranslateUi

};

namespace Ui {
    class TitlePage: public Ui_title {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLEPAGE_H
