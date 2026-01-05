#include "luketrainpage.h"
#include "page.h"
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>
#include <QTimer>
LukeTrainPage::LukeTrainPage(QWidget *parent,MainWindow *mainwindow) : Page(parent,mainwindow),ui(new Ui::LukeTrainPage)
{
    ui->setupUi(this);
    ui->rock1->installEventFilter(this);
    ui->rock2->installEventFilter(this);
    ui->rock3->installEventFilter(this);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &LukeTrainPage::updateRockPos);

    timer->start(16);
    if(!effects.initializeMouse(mainWindow))
        qDebug() << "No haptic mouse plugged in!";

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
            changeRockSprite((QLabel*)watched,"./pages_p/rock_object_drag.png");

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
            changeRockSprite((QLabel*)watched,"./pages_p/rock_object.png");
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
            if(watched==ui->rock1 && !rocksPlaced[0]){rocksPlaced[0]=true;rocksFinalY[0]=cumulativeRocksY;cumulativeRocksY-=20;}
            if(watched==ui->rock2 && !rocksPlaced[1]){rocksPlaced[1]=true;rocksFinalY[1]=cumulativeRocksY;cumulativeRocksY-=20;}
            if(watched==ui->rock3 && !rocksPlaced[2]){rocksPlaced[2]=true;rocksFinalY[2]=cumulativeRocksY;cumulativeRocksY-=20;}
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
    if(rocksPlaced[0] && rocksPlaced[1] && rocksPlaced[2]){
        soundPlayer.stop();//on stoppe un son s'il y en a
        soundPlayer.setMedia(QUrl("./pages_p/page_success.mp3"));
        soundPlayer.play();
        ui->text1->setText("Bien joué!");
        ui->text2->setText("Luke a terminé son entrainement,vous pouvez passer à la page suivante!");
        setPageFinished();
    }
}

void LukeTrainPage::updateRockPos(){
    if(!isDragging){
        QPoint pos1=ui->rock1->pos()+QPoint(0,gravity);
        ui->rock1->move(pos1.x(),std::min(determineGround(pos1.x(),0),pos1.y()));

        QPoint pos2=ui->rock2->pos()+QPoint(0,gravity);
        ui->rock2->move(pos2.x(),std::min(determineGround(pos2.x(),1),pos2.y()));

        QPoint pos3=ui->rock3->pos()+QPoint(0,gravity);
        ui->rock3->move(pos3.x(),std::min(determineGround(pos3.x(),2),pos3.y()));
    }
}
int LukeTrainPage::determineGround(int posX,int id){
    if(posX>toleratedPos){
        return rocksFinalY[id];
    }else return 200;
}
void LukeTrainPage::enableSound(){
soundPlayer.setVolume(100);
musicPlayer.setVolume(100);
}
void LukeTrainPage::disableSound(){
soundPlayer.setVolume(0);
musicPlayer.setVolume(0);
}

