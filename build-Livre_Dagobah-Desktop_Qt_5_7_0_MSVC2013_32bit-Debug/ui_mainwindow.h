/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *pageLabel;
    QPushButton *nextButtton;
    QPushButton *prevButton;
    QWidget *pageContainer;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *soundButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(716, 586);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pageLabel = new QLabel(centralWidget);
        pageLabel->setObjectName(QStringLiteral("pageLabel"));
        pageLabel->setGeometry(QRect(510, 480, 111, 31));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        pageLabel->setFont(font);
        nextButtton = new QPushButton(centralWidget);
        nextButtton->setObjectName(QStringLiteral("nextButtton"));
        nextButtton->setGeometry(QRect(640, 470, 61, 51));
        QFont font1;
        font1.setPointSize(36);
        font1.setBold(true);
        font1.setWeight(75);
        nextButtton->setFont(font1);
        nextButtton->setAutoRepeat(false);
        nextButtton->setAutoDefault(false);
        nextButtton->setFlat(false);
        prevButton = new QPushButton(centralWidget);
        prevButton->setObjectName(QStringLiteral("prevButton"));
        prevButton->setEnabled(false);
        prevButton->setGeometry(QRect(440, 470, 61, 51));
        prevButton->setFont(font1);
        pageContainer = new QWidget(centralWidget);
        pageContainer->setObjectName(QStringLiteral("pageContainer"));
        pageContainer->setGeometry(QRect(10, 10, 700, 450));
        pageContainer->setAutoFillBackground(true);
        verticalLayoutWidget = new QWidget(pageContainer);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-1, -1, 701, 451));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        soundButton = new QPushButton(centralWidget);
        soundButton->setObjectName(QStringLiteral("soundButton"));
        soundButton->setGeometry(QRect(10, 470, 61, 51));
        soundButton->setFont(font1);
        QIcon icon;
        icon.addFile(QStringLiteral("sound_on.png"), QSize(), QIcon::Normal, QIcon::Off);
        soundButton->setIcon(icon);
        soundButton->setIconSize(QSize(32, 32));
        soundButton->setAutoRepeat(false);
        soundButton->setAutoDefault(false);
        soundButton->setFlat(false);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 716, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        nextButtton->setDefault(false);
        soundButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Le livre de Dagobah", 0));
        pageLabel->setText(QApplication::translate("MainWindow", "Page 0/0", 0));
        nextButtton->setText(QApplication::translate("MainWindow", "\342\206\222", 0));
        prevButton->setText(QApplication::translate("MainWindow", "\342\206\220", 0));
        soundButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
