#include "lukeduelpage.h"
#include "ui_lukeduelpage.h"
#include <QTimer>
#include <stdlib.h>

LukeDuelPage::LukeDuelPage(QWidget *parent) :
    Page(parent),
    ui(new Ui::LukeDuelPage)
{
    currentButton = nullptr;

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
        // Démarrage du jeu
        showGameState();
    });
}

void LukeDuelPage::showSaberStrike()
{
    if (currentButton) {
        currentButton->deleteLater();
        currentButton = nullptr;
    }

    const char* anims[] = {
        ":/pages_m/duel_blow_left.gif",
        ":/pages_m/duel_blow_up.gif",
        ":/pages_m/duel_blow_right.gif"
    };
    movie.setFileName(anims[lastStrikeDirection]);
    movie.start();

    sfxPlayer.setMedia(QUrl("qrc:/pages_m/duel_strike.wav"));
    sfxPlayer.play();

    QObject* oneShot = new QObject();
    connect(&movie, &QMovie::finished, oneShot, [=](){
        oneShot->deleteLater();
        // retour au jeu
        showGameState(false);
    });
}

bool LukeDuelPage::placeTimedButton()
{
    if (currentButton) {
        currentButton->deleteLater();
        currentButton = nullptr;
    }

    if (numSuccessfulStrikes-- <= 0) {
        showSuccess();
        setPageFinished();
        return false;
    }

    const int xOffset = 120;
    const int yOffset = 70;

    // placement du bouton de jeu (1200ms + N*ms) le temps se raccourcit au fur et à mesure des clics.
    currentButton = new QTEButton(1200 + (numSuccessfulStrikes * 100), ui->movieLabel);
    lastStrikeDirection = rand() % 3;
    switch (lastStrikeDirection) {
        case 0:
            // à gauche
            currentButton->setGeometry(xOffset, ui->movieLabel->height() - yOffset, 64, 64);
        break;
        case 1:
            // en haut
            currentButton->setGeometry(ui->movieLabel->width()>>1, yOffset, 64, 64);
        break;
        case 2:
            // à droite
            currentButton->setGeometry(ui->movieLabel->width() - xOffset, ui->movieLabel->height() - (yOffset + 20), 64, 64);
        break;
    }
    currentButton->show();

    connect(currentButton, &QTEButton::buttonTimeout, this, &LukeDuelPage::showFail);
    connect(currentButton, &QTEButton::clicked, this, &LukeDuelPage::showSaberStrike);
    return true;
}

void LukeDuelPage::showGameState(bool init)
{
    if (init) {
        // nombre arbitraire de coups à porter avant de gagner
        numSuccessfulStrikes = 10;

        // la musique doit continuer entre les coups
        audioPlayer.setPlaylist(&audioList);
        audioPlayer.play();
        currentButton = nullptr;
    }

    if (placeTimedButton()) {
        movie.setFileName(":/pages_m/duel_states.gif");
        movie.start();
    }
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
            // redémarrage du jeu
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
