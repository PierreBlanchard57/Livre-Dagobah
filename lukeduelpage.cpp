#include "lukeduelpage.h"
#include "qtebutton.h"
#include "ui_lukeduelpage.h"
#include <QTimer>
#include <stdlib.h>

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
}

void LukeDuelPage::placeTimedButton()
{
    static QTEButton* testButton = nullptr;
    if (testButton) {
        testButton->deleteLater();
        testButton = nullptr;
    }

    if (numSuccessfulStrikes-- <= 0) {
        showSuccess();
        setPageFinished();
        return;
    }

    const int xOffset = 120;
    const int yOffset = 70;

    // placement du bouton de jeu (1200ms + N*ms) le temps se raccourcit au fur et à mesure des clics.
    testButton = new QTEButton(1200 + (numSuccessfulStrikes * 100), ui->movieLabel);
    switch (rand() % 3) {
        case 0:
            // en haut
            testButton->setGeometry(ui->movieLabel->width()>>1, yOffset, 64, 64);
        break;
        case 1:
            // à gauche
            testButton->setGeometry(xOffset, ui->movieLabel->height() - yOffset, 64, 64);
        break;
        case 2:
            // à droite
            testButton->setGeometry(ui->movieLabel->width() - xOffset, ui->movieLabel->height() - (yOffset + 20), 64, 64);
        break;
    }
    testButton->show();

    connect(testButton, &QTEButton::buttonTimeout, this, &LukeDuelPage::showFail);
    connect(testButton, &QTEButton::clicked, this, &LukeDuelPage::placeTimedButton);
}

void LukeDuelPage::showGameState()
{
    // nombre arbitraire de coups à porter avant de gagner
    numSuccessfulStrikes = 10;

    movie.setFileName(":/pages_m/duel_states.gif");
    movie.start();

    audioPlayer.setPlaylist(&audioList);
    audioPlayer.play();

    placeTimedButton();
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

    QObject* oneShot = new QObject();
    connect(&movie, &QMovie::finished, oneShot, [=](){
        oneShot->deleteLater();
        // on revient au jeu
        QTimer* delay = new QTimer;
        delay->start(3000);
        delay->setSingleShot(true);
        connect(delay, &QTimer::timeout, this, [=](){
            delay->deleteLater();
            showGameState();
        });
    });
}

void LukeDuelPage::keyPressEvent(QKeyEvent* event)
{
    showSuccess();
}

LukeDuelPage::~LukeDuelPage()
{
    delete ui;
}
