#include "rockobject.h"

RockObject::RockObject(QObject *parent,QString name,QRect geometry) : QLabel(parent)
{
    QLabel::setPixmap(QPixmap(QString::fromUtf8("pages_p/rock_object.png")));
    QLabel::setScaledContents(true);
}
