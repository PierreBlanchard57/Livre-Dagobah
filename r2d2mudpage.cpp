#include "r2d2mudpage.h"
#include <QDebug>
#include <QEvent>
#include <QMouseEvent>
int midX;
const int maxLeftGap=100;
const int maxRightGap=100;
int leftGap=5;
bool isDragging=false;

R2D2MudPage::R2D2MudPage(QWidget *parent,MainWindow *mainwindow) : Page(parent,mainwindow),ui(new Ui::R2D2MudPage)
{
ui->setupUi(this);
midX=ui->r2d2->pos().x()+ui->r2d2->size().width()/2;
ui->r2d2->installEventFilter(this);
setPageFinished();
}

bool R2D2MudPage::eventFilter(QObject *watched, QEvent *event){
    QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
if(event->type()==QEvent::MouseButtonPress){
    if (mouseEvent->button() == Qt::LeftButton) {
        isDragging=true;
        qDebug() << "click";
    }
}
if(event->type()==QEvent::MouseButtonRelease){
    if (mouseEvent->button() == Qt::LeftButton) {
        isDragging=false;
        qDebug() << "unclick";
    }
}
if(event->type()==QEvent::MouseMove && isDragging){
    qDebug() << "moving";
}
return false;
}
