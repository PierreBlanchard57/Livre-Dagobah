#include "luketrainpage.h"
#include "page.h"
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>
LukeTrainPage::LukeTrainPage(QWidget *parent,MainWindow *mainwindow) : Page(parent,mainwindow),ui(new Ui::LukeTrainPage)
{
ui->setupUi(this);
ui->rock1->installEventFilter(this);
ui->rock2->installEventFilter(this);
ui->rock3->installEventFilter(this);
}

bool LukeTrainPage::eventFilter(QObject *watched, QEvent *event){

if(watched== ui->rock1 || watched==ui->rock2 || watched==ui->rock3){
    if (event->type() == QEvent::MouseButtonPress) {
                QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
                if (mouseEvent->button() == Qt::LeftButton) {
                        qDebug() << "enfoncé";
                        changeLukePose(":/luke_force.png");
                }
            }
    if (event->type() == QEvent::MouseButtonRelease) {
                QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
                if (mouseEvent->button() == Qt::LeftButton) {
                    changeLukePose(":/luke_normal.png");
                        qDebug() << "relaché";
                }
            }
    if (event->type() == QEvent::MouseMove) {
                        qDebug() << "souris bougé!";
            }
}
return false;
}

void LukeTrainPage::changeLukePose(const std::string &file)
{

    ui->luke->setPixmap(QPixmap(QString::fromStdString(file)));
}
