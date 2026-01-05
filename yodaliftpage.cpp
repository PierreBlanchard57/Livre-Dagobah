#include "yodaliftpage.h"
#include "ui_yodaliftpage.h"
#include <stdlib.h>

#define YODA_LIFT_PAGE_RES "./pages_m/xwing_lift.gif"
#define PAGE_EFFECT_SHOCKWAVE "./shockwave.ifr"
#define PAGE_EFFECT_LIFT "./xwing_lift.ifr"
#define PAGE_EFFECT_BLOW "./saber_blow.ifr"

YodaLiftPage::YodaLiftPage(QWidget *parent, MainWindow *mainWindow) :
    Page(parent, mainWindow),
    ui(new Ui::YodaLiftPage)
{
    ui->setupUi(this);
    audioList.addMedia(QUrl("./pages_m/xwing_idle.wav"));
    audioList.setPlaybackMode(QMediaPlaylist::Loop);

    updateTimer.setInterval(100); // lent
    connect(&updateTimer, &QTimer::timeout, this, &YodaLiftPage::updateGameState);

    initialized = false;
    buttonSide = 0;
    currentButton = nullptr;

    connect(&movie, &QMovie::frameChanged, this, &YodaLiftPage::frameHook);
}

void YodaLiftPage::showEvent(QShowEvent *event)
{
    if(!effects.initializeMouse(mainWindow))
        qDebug() << "No haptic mouse plugged in!";

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

    effects.clearAllEffects();
}

void YodaLiftPage::showIntro(bool startMusic)
{
    movie.setFileName("./pages_m/xwing_yoda.gif");

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

    movie.setFileName("./pages_m/xwing_lapse.gif");
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

    effects.clearAllEffects();
}

void YodaLiftPage::showSuccess()
{
    updateTimer.stop();
    if (currentButton) {
        currentButton->deleteLater();
        currentButton = nullptr;
    }

    movie.setFileName("./pages_m/xwing_recover.gif");
    movie.start();

    effects.clearAllEffects();
    effects.pushProject(PAGE_EFFECT_BLOW, "blow_up", false);
}

void YodaLiftPage::frameHook(int nframe)
{
    if (!isVisible())
        return;

    if (movie.fileName() == "./pages_m/xwing_recover.gif") {
        if (nframe == 59) // Le vaisseau atterrit
            effects.pushProject(PAGE_EFFECT_SHOCKWAVE, false);
    }
    if (movie.fileName() == "./pages_m/xwing_lapse.gif") {
        if (nframe == 3) { // Le vaisseau replonge
            effects.pushProject(PAGE_EFFECT_SHOCKWAVE, false);
            effects.pushProject(PAGE_EFFECT_BLOW, "blow_up", false);
        }
    }
}

void YodaLiftPage::involveGame()
{
    audioPlayer.setMedia(QUrl("./pages_m/xwing_lift.wav"));
    audioPlayer.play();
    effects.pushProject(PAGE_EFFECT_LIFT, "Force", false);
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
void YodaLiftPage::enableSound(){
//a completer
}
void YodaLiftPage::disableSound(){
//a completer
}

YodaLiftPage::~YodaLiftPage()
{
    delete ui;
}
