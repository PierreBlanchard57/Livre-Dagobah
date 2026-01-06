#include "luketrainpage.h"
#include "page.h"
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>
#include "rockobject.h"
LukeTrainPage::LukeTrainPage(QWidget *parent,MainWindow *mainwindow) : Page(parent,mainwindow),ui(new Ui::LukeTrainPage)
{
    ui->setupUi(this);
    //installation des filtres d'evenement des rochers pour capter les entrées sur eux
    ui->rock1->installEventFilter(this);
    ui->rock2->installEventFilter(this);
    ui->rock3->installEventFilter(this);
    if(!effects.initializeMouse(mainWindow))
        qDebug() << "No haptic mouse plugged in!";

}
LukeTrainPage::~LukeTrainPage(){
delete ui;
}

void LukeTrainPage::showEvent(QShowEvent *event)
{
    //on demande à mainwindow si le don est activé et on agit en conséquence
    if(!mainWindow->getSoundEnabled())disableSound();
    else enableSound();
    musicPlayer.setMedia(QUrl("./pages_p/train_music.wav"));
    musicPlayer.play();
}

void LukeTrainPage::hideEvent(QHideEvent *event)
{
    musicPlayer.stop();
}

bool LukeTrainPage::eventFilter(QObject *watched, QEvent *event){
    QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);

    //pression du clic gauche(1 fois/clic=>)
    if (event->type() == QEvent::MouseButtonPress) {
        if (mouseEvent->button() == Qt::LeftButton) {
            isDragging=true;
            changeLukePose("./pages_p/luke_force.png");

            //on calcule l'offset à chaque fois car la souris n'est pas toujours à la meme position
            offset=mainWindow->pos()+QPoint(40,60);

            //on active l'effet de gravité
            effects.pushProject("gravity.ifr","Compound",true);

            soundPlayer.setMedia(QUrl("./pages_p/rock_levitate.wav"));
            soundPlayer.play();
            //on cache le curseur pour renforcer l'immersion
            setCursor(Qt::BlankCursor);

            //on dit au rocher qu'il est drag
            ((RockObject *)watched)->setDragged(true);

        }
    }
    //relachement clic gauche(1 fois/clic=>arret de la force)
    if (event->type() == QEvent::MouseButtonRelease) {
        if (mouseEvent->button() == Qt::LeftButton) {
            changeLukePose("./pages_p/luke_normal.png");
            isDragging=false;
            //on nettoie tous les effets haptiques car on utilise plus la force
            effects.clearAllEffects();
            //on arrete les sons
            soundPlayer.stop();
            //on tente de finir la page
            tryFinishPage();
            //on remet le curseur
            setCursor(Qt::ArrowCursor);
            //on dit au rocher qu'il n'est plus drag
            ((RockObject *)watched)->setDragged(false);
        }
    }
        //deplacement de la souris,si drag il y a
    if (event->type() == QEvent::MouseMove && isDragging) {

        QPoint pos=mouseEvent->globalPos()-offset;
        //limitation de la position
        int posX=std::min(std::max(200,pos.x()),460);
        int posY=std::min(std::max(0,pos.y()),200);
        pos=QPoint(posX,posY);
        if(posY==200)effects.pushProject("ground.ifr","Compound",false);
        //translation du label cible
        ((QLabel*)watched)->move(pos.x(),pos.y());
        //si le rocher entre dans la zone finale...
        if(pos.x()>toleratedPos){
            RockObject *rock=((RockObject*)watched);
            //...on regarde s'il est placé,sinon on lui defini un y final
            if(!rock->getPlaced()){
                rock->setFinalY((cumulativeRocksY-=20));
                rock->setPlaced(true);
            }
        }
    }
    return false;
}
//changement de la posture de luke(pixmap) selon l'utilisation ou pas de la force
void LukeTrainPage::changeLukePose(const std::string &file)
{

    ui->luke->setPixmap(QPixmap(QString::fromStdString(file)));
}
//changement de la texture(pixamp) du rocher passé en paramètre selon qu'il est drag ou non
void LukeTrainPage::changeRockSprite(QLabel *rock,const std::string &file)
{

    rock->setPixmap(QPixmap(QString::fromStdString(file)));
}
//tentative de finir la page
void LukeTrainPage::tryFinishPage(){
    //si et seulement si la page n'est as terminé,on tente
    if(!pageFinished){
        RockObject *rock1=((RockObject*)ui->rock1);
        RockObject *rock2=((RockObject*)ui->rock2);
        RockObject *rock3=((RockObject*)ui->rock3);
        //si tous les rochers sont placés,alors c'est terminé
        if(rock1->getPlaced() && rock2->getPlaced() && rock3->getPlaced()){
            soundPlayer.stop();//on stoppe un son s'il y en a
            soundPlayer.setMedia(QUrl("./pages_p/page_success.mp3"));
            soundPlayer.play();
            ui->text1->setText("Bien joué!");
            ui->text2->setText("Luke a terminé son entrainement,vous pouvez passer à la page suivante!");
            setPageFinished();
        }
    }

}

//activer le son en le mettant à fond (100)
void LukeTrainPage::enableSound(){
soundPlayer.setVolume(100);
musicPlayer.setVolume(100);
}
//desactiver le son en le mettant au minimum (0)
void LukeTrainPage::disableSound(){
soundPlayer.setVolume(0);
musicPlayer.setVolume(0);
}

