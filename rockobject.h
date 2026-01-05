#ifndef ROCKOBJECT_H
#define ROCKOBJECT_H

#include <QWidget>
#include <QObject>

class RockObject : public QLabel
{
public:
    RockObject(QObject *parent,QString name,QRect geometry);
};

#endif // ROCKOBJECT_H
