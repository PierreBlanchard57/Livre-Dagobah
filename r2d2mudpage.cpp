#include "r2d2mudpage.h"
#include <QDebug>
#include <QEvent>
#include <QMouseEvent>

#define LEFT 0
#define RIGHT 1
int midX;
const int maxLeftGap=100;
const int maxRightGap=100;
const int gapGrowthBySide=15;
int leftGap=5;
int rightGap=5;
int stretchDirection=LEFT;
bool isDragging=false;
QPoint lastMousePos;

R2D2MudPage::R2D2MudPage(QWidget *parent,MainWindow *mainwindow) : Page(parent,mainwindow),ui(new Ui::R2D2MudPage)
{
ui->setupUi(this);
midX=ui->r2d2->mapToGlobal(QPoint(ui->r2d2->width()/2, ui->r2d2->height()/2)).x();
ui->r2d2->installEventFilter(this);
setPageFinished();
}

bool R2D2MudPage::eventFilter(QObject *watched, QEvent *event){
    QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
if(event->type()==QEvent::MouseButtonPress){
    if (mouseEvent->button() == Qt::LeftButton) {
        isDragging=true;
        lastMousePos=ui->r2d2->parentWidget()->mapFromGlobal(mouseEvent->globalPos());
        qDebug()<<lastMousePos.x();
    }
}
if(event->type()==QEvent::MouseButtonRelease){
    if (mouseEvent->button() == Qt::LeftButton) {
        isDragging=false;
    }
}
if(event->type()==QEvent::MouseMove && isDragging){
    int currentX=ui->r2d2->parentWidget()->mapFromGlobal(mouseEvent->globalPos()).x();
    int diffX=currentX-lastMousePos.x();

    if(stretchDirection==LEFT){
        if(diffX<0 && currentX<midX-leftGap){
            rightGap=std::min(maxRightGap,rightGap+gapGrowthBySide);
            stretchDirection=RIGHT;
            qDebug()<<"rightGap="<<rightGap;
        }
        if(diffX>0 && currentX>midX+rightGap){
            //effet mur
        }
    }
    else{
        if(diffX>0 && currentX>midX+rightGap){
            leftGap=std::min(maxLeftGap,leftGap+gapGrowthBySide);
            stretchDirection=LEFT;
            qDebug()<<"leftGap="<<leftGap;
        }
        if(diffX<0 && currentX<midX-leftGap){
            //effet mur
        }
    }
    lastMousePos=ui->r2d2->parentWidget()->mapFromGlobal(mouseEvent->globalPos());
}
return false;
}
