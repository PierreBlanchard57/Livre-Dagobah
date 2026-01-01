/********************************************************************************
** Form generated from reading UI file 'endpage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDPAGE_H
#define UI_ENDPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EndPage
{
public:
    QLabel *label;

    void setupUi(QWidget *EndPage)
    {
        if (EndPage->objectName().isEmpty())
            EndPage->setObjectName(QStringLiteral("EndPage"));
        EndPage->resize(700, 450);
        label = new QLabel(EndPage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(240, 160, 201, 151));
        QFont font;
        font.setPointSize(72);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        retranslateUi(EndPage);

        QMetaObject::connectSlotsByName(EndPage);
    } // setupUi

    void retranslateUi(QWidget *EndPage)
    {
        EndPage->setWindowTitle(QApplication::translate("EndPage", "Form", 0));
        label->setText(QApplication::translate("EndPage", "FIN", 0));
    } // retranslateUi

};

namespace Ui {
    class EndPage: public Ui_EndPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDPAGE_H
