/********************************************************************************
** Form generated from reading UI file 'yodaliftpage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YODALIFTPAGE_H
#define UI_YODALIFTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_YodaLiftPage
{
public:
    QLabel *blurbLabel;
    QLabel *movieLabel;

    void setupUi(QWidget *YodaLiftPage)
    {
        if (YodaLiftPage->objectName().isEmpty())
            YodaLiftPage->setObjectName(QStringLiteral("YodaLiftPage"));
        YodaLiftPage->resize(579, 448);
        blurbLabel = new QLabel(YodaLiftPage);
        blurbLabel->setObjectName(QStringLiteral("blurbLabel"));
        blurbLabel->setGeometry(QRect(20, 270, 541, 171));
        QFont font;
        font.setPointSize(11);
        blurbLabel->setFont(font);
        blurbLabel->setAutoFillBackground(false);
        blurbLabel->setStyleSheet(QLatin1String("background-color: rgb(255, 248, 187);\n"
"border-color: rgb(0, 0, 0);\n"
"border-style: solid;\n"
"border-width: 1px;"));
        blurbLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        blurbLabel->setWordWrap(true);
        movieLabel = new QLabel(YodaLiftPage);
        movieLabel->setObjectName(QStringLiteral("movieLabel"));
        movieLabel->setGeometry(QRect(0, 10, 581, 261));
        movieLabel->setAutoFillBackground(false);
        movieLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(YodaLiftPage);

        QMetaObject::connectSlotsByName(YodaLiftPage);
    } // setupUi

    void retranslateUi(QWidget *YodaLiftPage)
    {
        YodaLiftPage->setWindowTitle(QApplication::translate("YodaLiftPage", "Form", 0));
        blurbLabel->setText(QApplication::translate("YodaLiftPage", "<html><head/><body><p>Le Ma\303\256tre tourna son regard vers le marais. D'abord, l'eau commen\303\247a \303\240 tourbillonner sur elle m\303\252me, puis \303\240 bouillonner furieusement et, sous les yeux de Luke abasourdi, le chasseur X \303\251mergea gracieusement de sa tombe aquatique pour se diriger lentement sur la rive. Et \303\240 quelque pas de l\303\240, Yoda le minuscule guidait sans effort la course du vaisseau. Luke avait pourtant jug\303\251 cette performance d'impossible. Quelle d\303\251monstration plus \303\251clatante pourrait-il avoir de la toute puissance que la Force pouvait conf\303\251rer \303\240 ses initi\303\251s ? Aussi abasourdi mais plus prosa\303\257que, D2 salua l'\303\251v\303\250nement d'une trille de sifflements.</p></body></html>", 0));
        movieLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class YodaLiftPage: public Ui_YodaLiftPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YODALIFTPAGE_H
