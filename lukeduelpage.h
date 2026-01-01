#ifndef LUKEDUELPAGE_H
#define LUKEDUELPAGE_H

#include <QWidget>
#include <QMovie>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
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

    void showGameState();
    void showSuccess();
    void showFail();

    void placeTimedButton();

protected:
    void keyPressEvent(QKeyEvent* event) override;

private:
    Ui::LukeDuelPage *ui;

    QMovie movie;
    QMediaPlayer audioPlayer;
    QMediaPlaylist audioList;

    int numSuccessfulStrikes;
};

#endif // LUKEDUELPAGE_H
