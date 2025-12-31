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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class lukeTrainPage
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *unlock;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(700, 450);
        verticalLayoutWidget = new QWidget(Form);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, -10, 701, 461));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);
        label->setMinimumSize(QSize(150, 150));
        label->setPixmap(QPixmap(QString::fromUtf8(":/training.png")));
        label->setScaledContents(true);

        verticalLayout->addWidget(label);

        unlock = new QPushButton(verticalLayoutWidget);
        unlock->setObjectName(QStringLiteral("unlock"));

        verticalLayout->addWidget(unlock);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        label->setText(QString());
        unlock->setText(QApplication::translate("Form", "test", 0));
    } // retranslateUi

};

namespace Ui {
    class LukeTrainPage: public lukeTrainPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LUKETRAINPAGE_H
