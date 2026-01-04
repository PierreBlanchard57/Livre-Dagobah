#include "r2d2mudpage.h"
#include <QDebug>
#include <QEvent>
#include <QMouseEvent>

#define LEFT 0
#define RIGHT 1
int midX;//la position en X du milieu de R2D2,servant de repère gauche/droite
const int maxLeftGap=105;//
const int maxRightGap=105;
const int gapGrowthBySide=5;
int leftGap=5;
int rightGap=5;
int elevationBySide=1;
int stretchDirection=LEFT;
bool isDragging=false;
QPoint lastMousePos;

R2D2MudPage::R2D2MudPage(QWidget *parent,MainWindow *mainwindow) : Page(parent,mainwindow),ui(new Ui::R2D2MudPage)
{
    ui->setupUi(this);
    midX=ui->r2d2->mapToGlobal(QPoint(ui->r2d2->width()/2, ui->r2d2->height()/2)).x();
    double percent=(double)((maxLeftGap-leftGap)/gapGrowthBySide)/200;
    ui->r2d2->installEventFilter(this);
}

bool R2D2MudPage::eventFilter(QObject *watched, QEvent *event){
    QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
    if(event->type()==QEvent::MouseButtonPress){
        if (mouseEvent->button() == Qt::LeftButton) {
            isDragging=true;
            lastMousePos=ui->r2d2->parentWidget()->mapFromGlobal(mouseEvent->globalPos());
            effects.pushProject("mud.ifr","Compound",false);
        }
    }
    if(event->type()==QEvent::MouseButtonRelease){
        if (mouseEvent->button() == Qt::LeftButton) {
            isDragging=false;
            effects.clearAllEffects();
        }
    }
    if(event->type()==QEvent::MouseMove && isDragging){
        if(leftGap<maxLeftGap && rightGap<maxRightGap){
            int currentX=ui->r2d2->parentWidget()->mapFromGlobal(mouseEvent->globalPos()).x();
            int diffX=currentX-lastMousePos.x();

            if(stretchDirection==LEFT){
                if(diffX<0 && currentX<midX-leftGap){
                    rightGap=std::min(maxRightGap,rightGap+gapGrowthBySide);
                    stretchDirection=RIGHT;
                    ui->r2d2->move(ui->r2d2->pos()+QPoint(0, -elevationBySide));
                    tryFinishPage();
                }
            }
            else{
                if(diffX>0 && currentX>midX+rightGap){
                    leftGap=std::min(maxLeftGap,leftGap+gapGrowthBySide);
                    stretchDirection=LEFT;
                    ui->r2d2->move(ui->r2d2->pos()+QPoint(0,-elevationBySide));
                    tryFinishPage();
                }
            }
            lastMousePos=ui->r2d2->parentWidget()->mapFromGlobal(mouseEvent->globalPos());
        }

    }
    return false;
}

/*methode pour tester si les conditions pour finir la page sont remplies et si c'est le cas
alors on marque le page comme terminée*/
void R2D2MudPage::tryFinishPage(){
    if(rightGap>=maxRightGap){
        setPageFinished();
    }
}
