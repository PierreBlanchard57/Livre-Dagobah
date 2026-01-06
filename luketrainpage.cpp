#include "luketrainpage.h"
#include "page.h"
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>
#include "rockobject.h"
LukeTrainPage::LukeTrainPage(QWidget *parent,MainWindow *mainwindow) : Page(parent,mainwindow),ui(new Ui::LukeTrainPage)
{
    ui->setupUi(this);
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

    if (event->type() == QEvent::MouseButtonPress) {
        if (mouseEvent->button() == Qt::LeftButton) {
            isDragging=true;
            changeLukePose("./pages_p/luke_force.png");

            offset=mainWindow->pos()+QPoint(40,60);
            effects.pushProject("gravity.ifr","Compound",true);
            soundPlayer.setMedia(QUrl("./pages_p/rock_levitate.wav"));
            soundPlayer.play();
            setCursor(Qt::BlankCursor);
            ((RockObject *)watched)->setDragged(true);

        }
    }
    if (event->type() == QEvent::MouseButtonRelease) {
        if (mouseEvent->button() == Qt::LeftButton) {
            changeLukePose("./pages_p/luke_normal.png");
            isDragging=false;
            effects.clearAllEffects();
            soundPlayer.stop();
            tryFinishPage();
            setCursor(Qt::ArrowCursor);
            ((RockObject *)watched)->setDragged(false);
        }
    }

    if (event->type() == QEvent::MouseMove && isDragging) {

        QPoint pos=mouseEvent->globalPos()-offset;
        //limitation de la position
        int posX=std::min(std::max(200,pos.x()),460);
        int posY=std::min(std::max(0,pos.y()),200);
        pos=QPoint(posX,posY);
        if(posY==200)effects.pushProject("ground.ifr","Compound",false);
        //translation du label cible
        ((QLabel*)watched)->move(pos.x(),pos.y());
        if(pos.x()>toleratedPos){
            RockObject *rock=((RockObject*)watched);
            if(!rock->getPlaced()){
                rock->setFinalY((cumulativeRocksY-=20));
                rock->setPlaced(true);
            }
        }
    }
    return false;
}

void LukeTrainPage::changeLukePose(const std::string &file)
{

    ui->luke->setPixmap(QPixmap(QString::fromStdString(file)));
}
void LukeTrainPage::changeRockSprite(QLabel *rock,const std::string &file)
{

    rock->setPixmap(QPixmap(QString::fromStdString(file)));
}
void LukeTrainPage::tryFinishPage(){
    if(!pageFinished){
        RockObject *rock1=((RockObject*)ui->rock1);
        RockObject *rock2=((RockObject*)ui->rock2);
        RockObject *rock3=((RockObject*)ui->rock3);
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


void LukeTrainPage::enableSound(){
soundPlayer.setVolume(100);
musicPlayer.setVolume(100);
}
void LukeTrainPage::disableSound(){
soundPlayer.setVolume(0);
musicPlayer.setVolume(0);
}

