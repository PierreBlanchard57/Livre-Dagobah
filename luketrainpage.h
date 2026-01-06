#ifndef LUKETRAINPAGE_H
#define LUKETRAINPAGE_H

#include <QWidget>
#include <QObject>
#include <QEvent>
#include <QMediaPlayer>
#include "page.h"
#include "ui_luketrainpage.h"
#include "effectmanager.h"
class LukeTrainPage : public Page
{
    Q_OBJECT
public:
    explicit LukeTrainPage(QWidget *parent = nullptr,MainWindow *mainwindow=nullptr);
    void enableSound() override;
    void disableSound()override;
    ~LukeTrainPage();
    static const int toleratedPos=420;//constante statique qui designe le x où on considere qu'on est posé sur le rocher noir
protected:
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;
private:
    Ui::LukeTrainPage *ui;
    int cumulativeRocksY=190;//valeur qui decroit au fur et à mesure que des rochers se posent sur le rocher noir pour indiquer où devra se poser le prochain rocher.
    bool isDragging=false;//est on en mode drag souris
    QPoint offset;//decalage entre l'ecran principal et le widget
    EffectManager effects;//gestionnaire d'effets haptiques

    QMediaPlayer musicPlayer;//mediaplayer pour la musique
    QMediaPlayer soundPlayer;//mediaplayer pour les sons
    bool eventFilter(QObject *watched, QEvent *event);//filtre d'evenement
    void changeLukePose(const std::string &file);//changer le pixmap de luke
    void changeRockSprite(QLabel *rock,const std::string &file);//changer le pixmap du rocher en question
    void tryFinishPage();//tenter de terminer la page en testant les conditions nécessaires
};

#endif // LUKETRAINPAGE_H
