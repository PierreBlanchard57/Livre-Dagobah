#include "rockobject.h"
#include "luketrainpage.h"
#include <QTimer>

const int gravity=5;//nombre de pixels de descendus en 16ms
std::vector<QObject*>collidables;//objets dont on verifiera les colilsions(autre roches,pas implémenté au profit d'une physique simplifiée)

RockObject::RockObject(QWidget *parent,QString name,QRect geometry,std::vector<QObject*>_collidables) : QLabel(parent)
{
    QLabel::setGeometry(geometry);
    QLabel::setPixmap(QPixmap(QString::fromUtf8("pages_p/rock_object.png")));
    QLabel::setScaledContents(true);
    collidables=_collidables;
    //demarrage de la boucle d'update
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &RockObject::onUpdate);
    timer->start(16);
}

//on definit si l'objet est drag ou pas et on change sa pixmap en fonction
void RockObject::setDragged(bool dragged){
    isDragged=dragged;
    if(dragged)QLabel::setPixmap(QPixmap(QString::fromUtf8("pages_p/rock_object_drag.png")));

    else QLabel::setPixmap(QPixmap(QString::fromUtf8("pages_p/rock_object.png")));
}

void RockObject::setFinalY(int y){
finalY=y;
}

bool RockObject::getPlaced(){return isPlaced;}

void RockObject::setPlaced(bool placed){
isPlaced=placed;
}

void RockObject::onUpdate(){
    //si l'objest est drag alors y vaudra 0,sinon il vaudra gravity
    int y=(!isDragged)*gravity;
    QPoint move=QLabel::pos()+QPoint(0,y);
    //si on est dans la zone finale (rocher noir),alors au max y sera finalY,sinon il sera de 200 (sol)
    if(move.x()>=LukeTrainPage::toleratedPos){
        move=QPoint(move.x(),std::min(move.y(),finalY));
    }else{
        move=QPoint(move.x(),std::min(move.y(),200));
    }
    QLabel::move(move);
}

