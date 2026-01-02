/********************************************************************************
** Form generated from reading UI file 'lukeduelpage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LUKEDUELPAGE_H
#define UI_LUKEDUELPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LukeDuelPage
{
public:
    QLabel *movieLabel;
    QLabel *blurbLabel;

    void setupUi(QWidget *LukeDuelPage)
    {
        if (LukeDuelPage->objectName().isEmpty())
            LukeDuelPage->setObjectName(QStringLiteral("LukeDuelPage"));
        LukeDuelPage->resize(579, 448);
        movieLabel = new QLabel(LukeDuelPage);
        movieLabel->setObjectName(QStringLiteral("movieLabel"));
        movieLabel->setGeometry(QRect(0, 10, 581, 261));
        movieLabel->setAutoFillBackground(false);
        movieLabel->setAlignment(Qt::AlignCenter);
        blurbLabel = new QLabel(LukeDuelPage);
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

        retranslateUi(LukeDuelPage);

        QMetaObject::connectSlotsByName(LukeDuelPage);
    } // setupUi

    void retranslateUi(QWidget *LukeDuelPage)
    {
        LukeDuelPage->setWindowTitle(QApplication::translate("LukeDuelPage", "Form", 0));
        movieLabel->setText(QString());
        blurbLabel->setText(QApplication::translate("LukeDuelPage", "<html><head/><body><p>De la brume jaillit la silhouette du seigneur Vador, le rigoureux entrai\303\256nement de ces derniers jours avait pr\303\251par\303\251 Luke \303\240 cette rencontre. Il n'eut aucun mal \303\240 \303\251viter la premi\303\250re attaque. En un \303\251clair, il avait bondi de c\303\264t\303\251. La Force \303\251tait en lui. Il la sentait couler dans ses membres telle une s\303\250ve puissante. Il se fendit en avant, visant l'horrible masque, et la t\303\252te casqu\303\251e du Seigneur Noir vola en l'air. Le corps de Dark Vador disparut, comme aval\303\251. Lentement, Luke baissa les yeux vers le masque qui avait atterri juste devant ses pieds. Le heaume s'\303\251tait ouvert dans sa chute, r\303\251v\303\251lant au regard incr\303\251dule du jeune homme son propre visage le fixant.</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class LukeDuelPage: public Ui_LukeDuelPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LUKEDUELPAGE_H
