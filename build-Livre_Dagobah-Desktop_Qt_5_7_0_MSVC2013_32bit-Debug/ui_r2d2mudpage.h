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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_R2D2MudPage
{
public:

    void setupUi(QWidget *R2D2MudPage)
    {
        if (R2D2MudPage->objectName().isEmpty())
            R2D2MudPage->setObjectName(QStringLiteral("R2D2MudPage"));
        R2D2MudPage->resize(400, 300);

        retranslateUi(R2D2MudPage);

        QMetaObject::connectSlotsByName(R2D2MudPage);
    } // setupUi

    void retranslateUi(QWidget *R2D2MudPage)
    {
        R2D2MudPage->setWindowTitle(QApplication::translate("R2D2MudPage", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class R2D2MudPage: public Ui_R2D2MudPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_R2D2MUDPAGE_H
