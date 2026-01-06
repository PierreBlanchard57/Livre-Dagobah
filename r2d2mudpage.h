#ifndef R2D2MUDPAGE_H
#define R2D2MUDPAGE_H

#include <QWidget>
#include <QMediaPlayer>
#include "page.h"
#include "ui_r2d2mudpage.h"
#include "effectmanager.h"
class R2D2MudPage : public Page
{
    Q_OBJECT
public:
    explicit R2D2MudPage(QWidget *parent = nullptr,MainWindow *mainwindow=nullptr);
    void enableSound() override;
    void disableSound()override;
    ~R2D2MudPage();
protected:
    void showEvent(QShowEvent *event) override;//evenement d'affichage de la page
    void hideEvent(QHideEvent *event) override;//evenement de cache de la page
private:
    Ui::R2D2MudPage *ui;
    EffectManager effects;//gestionnaire d'effets haptiques
    QMediaPlayer musicPlayer;//mediaplayer pour la musique
    QMediaPlayer soundPlayer;//mediaplayer pour le son
    bool eventFilter(QObject *watched, QEvent *event);//filtre d'evenements
    void tryFinishPage();//tenter de terminer la page en testant les conditions nécessaires
};

#endif // R2D2MUDPAGE_H
