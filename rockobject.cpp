#include "rockobject.h"
#include "luketrainpage.h"
#include <QTimer>

const int gravity=5;
const int toleratedPos=420;

std::vector<QObject*>collidables;
RockObject::RockObject(QWidget *parent,QString name,QRect geometry,std::vector<QObject*>_collidables) : QLabel(parent)
{
    QLabel::setGeometry(geometry);
    QLabel::setPixmap(QPixmap(QString::fromUtf8("pages_p/rock_object.png")));
    QLabel::setScaledContents(true);
    collidables=_collidables;
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &RockObject::onUpdate);
    timer->start(16);
}

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
    int y=(!isDragged)*gravity;
    QPoint move=QLabel::pos()+QPoint(0,y);

    if(move.x()>=LukeTrainPage::toleratedPos){
        move=QPoint(move.x(),std::min(move.y(),finalY));
    }else{
        move=QPoint(move.x(),std::min(move.y(),200));
    }
    QLabel::move(move);
}

