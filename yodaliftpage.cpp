#include "yodaliftpage.h"
#include "ui_yodaliftpage.h"
#include <stdlib.h>

#define YODA_LIFT_PAGE_RES ":/pages_m/xwing_lift.gif"

YodaLiftPage::YodaLiftPage(QWidget *parent) :
    Page(parent),
    ui(new Ui::YodaLiftPage)
{
    ui->setupUi(this);
    audioList.addMedia(QUrl("qrc:/pages_m/xwing_idle.wav"));
    audioList.setPlaybackMode(QMediaPlaylist::Loop);

    updateTimer.setInterval(100); // lent
    connect(&updateTimer, &QTimer::timeout, this, &YodaLiftPage::updateGameState);

    initialized = false;
    buttonSide = 0;
    currentButton = nullptr;
}

void YodaLiftPage::showEvent(QShowEvent *event)
{
    updateTimer.start();

    if (initialized)
        return;

    ui->movieLabel->setMovie(&movie);
    audioPlayer.setPlaylist(&audioList);
    showIntro(true);

    initialized = true;
}

void YodaLiftPage::hideEvent(QHideEvent *event)
{
    updateTimer.stop();
    audioPlayer.stop();
}

void YodaLiftPage::showIntro(bool startMusic)
{
    movie.setFileName(":/pages_m/xwing_yoda.gif");

    movie.start();
    if (startMusic)
        audioPlayer.play();

    QObject* oneShot = new QObject();
    connect(&movie, &QMovie::finished, oneShot, [=](){
        oneShot->deleteLater();
        // Démarrage du jeu
        showGameState();
    });
}

void YodaLiftPage::showFail()
{
    updateTimer.stop();
    if (currentButton) {
        currentButton->deleteLater();
        currentButton = nullptr;
    }

    movie.setFileName(":/pages_m/xwing_lapse.gif");
    movie.start();

    // sortie de la musique triomphante
    audioPlayer.setPlaylist(&audioList);
    audioPlayer.play();

    // il faut remontrer yoda puis relancer le jeu
    QObject* oneShot = new QObject();
    connect(&movie, &QMovie::finished, oneShot, [=](){
        oneShot->deleteLater();
        // Redémarrage du jeu
        showIntro();
    });
    initialized = true;
}

void YodaLiftPage::showSuccess()
{
    updateTimer.stop();
    if (currentButton) {
        currentButton->deleteLater();
        currentButton = nullptr;
    }

    movie.setFileName(":/pages_m/xwing_recover.gif");
    movie.start();
}

void YodaLiftPage::involveGame()
{
    audioPlayer.setMedia(QUrl("qrc:/pages_m/xwing_lift.wav"));
    audioPlayer.play();
}

void YodaLiftPage::placeTimedButton()
{
    if (!updateTimer.isActive())
        return;

    if (currentButton) {
        currentButton->deleteLater();
        currentButton = nullptr;

        if (!hasClickedOnce) {
            involveGame();
            hasClickedOnce = true;
        }
    }

    const int xOffset = 120;
    int yOffset = (movie.currentFrameNumber() * 2) + 80;

    // 1 sec à chaque fois
    currentButton = new QTEButton(1000, ui->movieLabel);
    switch (buttonSide) {
    case 0:
        // à gauche
        currentButton->setGeometry(xOffset, ui->movieLabel->height() - yOffset, 64, 64);
    break;
    case 1:
        // à droite
        currentButton->setGeometry(ui->movieLabel->width() - xOffset, ui->movieLabel->height() - yOffset, 64, 64);
    break;
    }
    buttonSide = !buttonSide;
    currentButton->show();

    connect(currentButton, &QTEButton::buttonTimeout, this, &YodaLiftPage::showFail);
    connect(currentButton, &QTEButton::clicked, this, &YodaLiftPage::placeTimedButton);
}

// logique appelée ~12 fois par seconde
void YodaLiftPage::updateGameState()
{
    if (movie.fileName() != YODA_LIFT_PAGE_RES)
        return;

    if (!movie.jumpToNextFrame()) {
        showSuccess();
        setPageFinished();
    }
}

void YodaLiftPage::showGameState()
{
    if (!updateTimer.isActive())
        updateTimer.start();

    movie.stop();
    movie.setFileName(YODA_LIFT_PAGE_RES);
    ui->movieLabel->setMovie(&movie);
    movie.jumpToNextFrame();

    hasClickedOnce = false;
    placeTimedButton();
}

YodaLiftPage::~YodaLiftPage()
{
    delete ui;
}
