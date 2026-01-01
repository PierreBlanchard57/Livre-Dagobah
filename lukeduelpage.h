#ifndef LUKEDUELPAGE_H
#define LUKEDUELPAGE_H

#include <QWidget>
#include <QMovie>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include "qtebutton.h"
#include "page.h"

namespace Ui {
class LukeDuelPage;
}

class LukeDuelPage : public Page
{
    Q_OBJECT

public:
    explicit LukeDuelPage(QWidget *parent = 0);
    ~LukeDuelPage();

public slots:
    void showGameState(bool init = true);
    void showSuccess();
    void showFail();
    void showSaberStrike();

    bool placeTimedButton();

protected:
    void keyPressEvent(QKeyEvent* event) override;

private:
    Ui::LukeDuelPage *ui;

    QMovie movie;
    QMediaPlayer audioPlayer;
    QMediaPlayer sfxPlayer;
    QMediaPlaylist audioList;
    QTEButton* currentButton;

    int lastStrikeDirection;
    int numSuccessfulStrikes;
};

#endif // LUKEDUELPAGE_H
