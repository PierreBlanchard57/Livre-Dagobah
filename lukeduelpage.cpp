#include "lukeduelpage.h"
#include "ui_lukeduelpage.h"
#include <QTimer>
#include <stdlib.h>

#define PAGE_EFFECT_SHOCKWAVE "./shockwave.ifr"
#define PAGE_EFFECT_SABER "./saber_reference_buzz.ifr"
#define PAGE_EFFECT_BLOW "./saber_blow.ifr"

LukeDuelPage::LukeDuelPage(QWidget *parent,MainWindow *mainwindow) :
    Page(parent,mainwindow),
    ui(new Ui::LukeDuelPage)
{
    currentButton = nullptr;
    initialized = false;

    ui->setupUi(this);
    audioList.addMedia(QUrl("./pages_m/duel_ongoing.wav"));
    audioList.setPlaybackMode(QMediaPlaylist::Loop);

    // la page ne se déclenche pas encore si elle n'est pas visible
    connect(&movie, &QMovie::frameChanged, this, &LukeDuelPage::frameHook);
}

void LukeDuelPage::showEvent(QShowEvent* show)
{
    if(!effects.initializeMouse(mainWindow))
        qDebug() << "No haptic mouse plugged in!";

    if (initialized)
        return;

    movie.setFileName("./pages_m/duel_enter.gif");
    ui->movieLabel->setMovie(&movie);

    audioPlayer.setMedia(QUrl("./pages_m/duel_enter.wav"));

    movie.start();
    audioPlayer.play();

    QObject* oneShot = new QObject();
    connect(&movie, &QMovie::finished, oneShot, [=](){
        oneShot->deleteLater();
        // Démarrage du jeu
        showGameState();
    });
    initialized = true;
}

void LukeDuelPage::hideEvent(QHideEvent *event)
{
    // seulement important d'arrêter le son
    audioPlayer.stop();
    sfxPlayer.stop();

    // ainsi que les effets
    effects.clearAllEffects();
}

void LukeDuelPage::frameHook(int nframe)
{
    // pas de rafraîchissement d'effets haptiques quand invisible.
    if (!isVisible())
        return;

    if (movie.fileName().contains("blow")) {
        if (nframe == 0) { // Lancement du sabre
            char const* blow[] = {"blow_left", "blow_up", "blow_right"};
            effects.pushProject(PAGE_EFFECT_BLOW, blow[lastStrikeDirection], false);
        }
        if (nframe == 4) { // Claquement de sabres
            effects.pushProject(PAGE_EFFECT_SHOCKWAVE, false);
        }
    }
    else if (movie.fileName() == "./pages_m/duel_enter.gif") {
        if (nframe == 54) // Vador apparaît dans la brume
            effects.pushProject(PAGE_EFFECT_SHOCKWAVE, false);

        if (nframe == 90) // Le sabre de Luke s'illumine
            effects.pushProject(PAGE_EFFECT_SABER, false);
    }
    else if (movie.fileName() == "./pages_m/duel_finish.gif") {
        if (nframe == 50) { // Le heaume explose
            effects.clearAllEffects();
            effects.pushProject(PAGE_EFFECT_SHOCKWAVE, false);
        }
    }
}

void LukeDuelPage::showSaberStrike()
{
    if (currentButton) {
        currentButton->deleteLater();
        currentButton = nullptr;
    }

    const char* anims[] = {
        "./pages_m/duel_blow_left.gif",
        "./pages_m/duel_blow_up.gif",
        "./pages_m/duel_blow_right.gif"
    };
    movie.setFileName(anims[lastStrikeDirection]);
    movie.start();

    sfxPlayer.setMedia(QUrl("./pages_m/duel_strike.wav"));
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
        movie.setFileName("./pages_m/duel_states.gif");
        movie.start();
    }
}

void LukeDuelPage::showSuccess()
{
    movie.setFileName("./pages_m/duel_finish.gif");
    movie.start();

    audioPlayer.setMedia(QUrl("./pages_m/duel_success.wav"));
    audioPlayer.play();
    //on débloque la page suivante
    setPageFinished();
}

void LukeDuelPage::showFail()
{
    movie.setFileName("./pages_m/duel_fail.gif");
    movie.start();

    audioPlayer.setMedia(QUrl("./pages_m/duel_echec.wav"));
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
            // il faut redémarrer le sabre aussi
            effects.pushProject(PAGE_EFFECT_SABER, false);
        });
    });

    // plus d'effets
    effects.clearAllEffects();
}

void LukeDuelPage::keyPressEvent(QKeyEvent* event)
{
    showSuccess();
}
void LukeDuelPage::enableSound(){
//a completer
}
void LukeDuelPage::disableSound(){
//a completer
}

LukeDuelPage::~LukeDuelPage()
{
    delete ui;
}
