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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class luketrain
{
public:
    QPushButton *unlock;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(400, 300);
        unlock = new QPushButton(Form);
        unlock->setObjectName(QStringLiteral("unlock"));
        unlock->setGeometry(QRect(150, 140, 75, 23));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        unlock->setText(QApplication::translate("Form", "unlock", 0));
    } // retranslateUi

};

namespace Ui {
    class LukeTrainPage: public luketrain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LUKETRAINPAGE_H
