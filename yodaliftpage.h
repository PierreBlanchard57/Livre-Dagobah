#ifndef YODALIFTPAGE_H
#define YODALIFTPAGE_H

#include <QWidget>
#include <QMovie>
#include <QTimer>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include "effectmanager.h"
#include "qtebutton.h"
#include "page.h"

namespace Ui {
class YodaLiftPage;
}

class YodaLiftPage : public Page
{
    Q_OBJECT

public:
    explicit YodaLiftPage(QWidget *parent = 0, MainWindow *mainWindow = nullptr);
    ~YodaLiftPage();

public slots:
    void showGameState();
    void showFail();
    void showSuccess();
    void showIntro(bool startMusic = true);
    void updateGameState();
    void involveGame();
    void frameHook(int nframe);

protected:
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;

    void placeTimedButton();

private:
    Ui::YodaLiftPage *ui;

    QMovie movie;
    QMediaPlayer audioPlayer;
    QMediaPlaylist audioList;
    QTimer updateTimer;

    bool initialized;
    bool buttonSide;
    bool hasClickedOnce;
    QTEButton* currentButton;

    EffectManager effects;
};

#endif // YODALIFTPAGE_H
