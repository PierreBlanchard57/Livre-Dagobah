#ifndef ROCKOBJECT_H
#define ROCKOBJECT_H

#include <QWidget>
#include <QObject>
#include <QLabel>

class RockObject : public QLabel
{
public:
    RockObject(QWidget *parent,QString name,QRect geometry,std::vector<QObject*>_collidables);
    void setDragged(bool dragged);//setter de isDragged
    void setFinalY(int y);//setter de finalY
    bool getPlaced();//getter de isPlaced
    void setPlaced(bool placed);//setter de isPlaced
private:
 void onUpdate();//boucle de mises à jour du rocher,pour la gravité par exemple
 bool isDragged=false;//le rocher est-il draggé?
 bool isPlaced=false;//le rocher est il placé?
 int finalY=170;//postion en y sur laquelle persiste le rocher en empilement

};

#endif // ROCKOBJECT_H
