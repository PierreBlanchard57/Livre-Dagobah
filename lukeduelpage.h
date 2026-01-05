#ifndef LUKEDUELPAGE_H
#define LUKEDUELPAGE_H

#include <QWidget>
#include <QMovie>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include "qtebutton.h"
#include "page.h"
#include "mainwindow.h"
#include "effectmanager.h"

namespace Ui {
class LukeDuelPage;
}

class LukeDuelPage : public Page
{
    Q_OBJECT

public:
    explicit LukeDuelPage(QWidget *parent = 0,MainWindow *mainwindow=nullptr);
    void enableSound() override;
    void disableSound()override;
    ~LukeDuelPage();

public slots:
    void showGameState(bool init = true);
    void showSuccess();
    void showFail();
    void showSaberStrike();
    void frameHook(int nframe);

    bool placeTimedButton();

protected:
    void keyPressEvent(QKeyEvent* event) override;
    void showEvent(QShowEvent* event) override;
    void hideEvent(QHideEvent *event) override;

private:
    Ui::LukeDuelPage *ui;

    QMovie movie;
    QMediaPlayer audioPlayer;
    QMediaPlayer sfxPlayer;
    QMediaPlaylist audioList;
    QTEButton* currentButton;
    EffectManager effects;

    int lastStrikeDirection;
    int numSuccessfulStrikes;
    bool initialized;
};

#endif // LUKEDUELPAGE_H
