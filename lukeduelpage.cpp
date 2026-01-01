#include "lukeduelpage.h"
#include "qtebutton.h"
#include "ui_lukeduelpage.h"

LukeDuelPage::LukeDuelPage(QWidget *parent) :
    Page(parent),
    ui(new Ui::LukeDuelPage)
{
    ui->setupUi(this);
    audioList.addMedia(QUrl("qrc:/pages_m/duel_ongoing.wav"));
    audioList.setPlaybackMode(QMediaPlaylist::Loop);

    movie.setFileName(":/pages_m/duel_enter.gif");
    ui->movieLabel->setMovie(&movie);

    audioPlayer.setMedia(QUrl("qrc:/pages_m/duel_enter.wav"));

    movie.start();
    audioPlayer.play();

    QObject* oneShot = new QObject();
    connect(&movie, &QMovie::finished, oneShot, [=](){
        oneShot->deleteLater();
        // Etat de jeu
        showGameState();
    });

    QTEButton* testButton = new QTEButton(2000, this);
    testButton->resize(64, 64);
}

void LukeDuelPage::showGameState()
{
    movie.setFileName(":/pages_m/duel_states.gif");
    movie.start();

    audioPlayer.setPlaylist(&audioList);
    audioPlayer.play();
}

void LukeDuelPage::showSuccess()
{
    movie.setFileName(":/pages_m/duel_finish.gif");
    movie.start();

    audioPlayer.setMedia(QUrl("qrc:/pages_m/duel_success.wav"));
    audioPlayer.play();
}

void LukeDuelPage::showFail()
{
    movie.setFileName(":/pages_m/duel_fail.gif");
    movie.start();

    audioPlayer.setMedia(QUrl("qrc:/pages_m/duel_echec.wav"));
    audioPlayer.play();
}

void LukeDuelPage::keyPressEvent(QKeyEvent* event)
{
    showSuccess();
}

LukeDuelPage::~LukeDuelPage()
{
    delete ui;
}
