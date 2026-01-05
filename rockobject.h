#ifndef ROCKOBJECT_H
#define ROCKOBJECT_H

#include <QWidget>
#include <QObject>
#include <QLabel>

class RockObject : public QLabel
{
public:
    RockObject(QWidget *parent,QString name,QRect geometry,std::vector<QObject*>_collidables);
    void setDragged(bool dragged);
    void setFinalY(int y);
    bool getPlaced();
    void setPlaced(bool placed);
private:
 void onUpdate();
 bool isDragged=false;
 bool isPlaced=false;
 int finalY=170;

};

#endif // ROCKOBJECT_H
