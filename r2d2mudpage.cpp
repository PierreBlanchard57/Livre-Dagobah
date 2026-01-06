#include "r2d2mudpage.h"
#include <QDebug>
#include <QEvent>
#include <QMouseEvent>

#define LEFT 0
#define RIGHT 1
int midX;//la position en X du milieu de R2D2,servant de repère gauche/droite
const int maxLeftGap=105;//l'ecart max de gauche
const int maxRightGap=105;//l'ecart max de droite
const int gapGrowthBySide=5;//ecart lors du deplacement de la souris dans un des 2 cotés
int leftGap=5;//ecart courant coté gauche
int rightGap=5;//ecart courant coté droit
int elevationBySide=1;//quantité de mouvement vertical de R2D2 lors du mouvement de la souris vers un bors gauche ou droit
int stretchDirection=LEFT;//direction courant vers laquelle il faut bouger la souris pour creuser l'écart (alterne à chaque fois)
bool isDragging=false;//la souris est elle en train de drag R2D2?
QPoint lastMousePos;//derniere position connue de la souris

R2D2MudPage::R2D2MudPage(QWidget *parent,MainWindow *mainwindow) : Page(parent,mainwindow),ui(new Ui::R2D2MudPage)
{
    ui->setupUi(this);
    midX=ui->r2d2->mapToGlobal(QPoint(ui->r2d2->width()/2, ui->r2d2->height()/2)).x();
    //on installe un filtre d'evenement sur R2D2
    ui->r2d2->installEventFilter(this);
}
R2D2MudPage::~R2D2MudPage(){
delete ui;
}

void R2D2MudPage::showEvent(QShowEvent *event)
{
    //on demande au mainwindow si le son est activé et on agit en consequence
    if(!mainWindow->getSoundEnabled())disableSound();
    else enableSound();
    musicPlayer.setMedia(QUrl("./pages_p/mud_music.wav"));
    musicPlayer.play();
}

void R2D2MudPage::hideEvent(QHideEvent *event)
{
    musicPlayer.stop();
}

bool R2D2MudPage::eventFilter(QObject *watched, QEvent *event){
    QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
    if(event->type()==QEvent::MouseButtonPress){
        if (mouseEvent->button() == Qt::LeftButton) {
            isDragging=true;
            lastMousePos=ui->r2d2->parentWidget()->mapFromGlobal(mouseEvent->globalPos());
            effects.pushProject("mud.ifr","Compound",false);
            setCursor(Qt::BlankCursor);
        }
    }
    if(event->type()==QEvent::MouseButtonRelease){
        if (mouseEvent->button() == Qt::LeftButton) {
            isDragging=false;
            effects.clearAllEffects();
            setCursor(Qt::ArrowCursor);
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
                    soundPlayer.setMedia(QUrl("./pages_p/mud_move.wav"));
                    soundPlayer.play();
                    tryFinishPage();
                }
            }
            else{
                if(diffX>0 && currentX>midX+rightGap){
                    leftGap=std::min(maxLeftGap,leftGap+gapGrowthBySide);
                    stretchDirection=LEFT;
                    ui->r2d2->move(ui->r2d2->pos()+QPoint(0,-elevationBySide));
                    soundPlayer.setMedia(QUrl("./pages_p/mud_move.wav"));
                    soundPlayer.play();
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
        soundPlayer.stop();//on stoppe un son s'il y en a
        soundPlayer.setMedia(QUrl("./pages_p/page_success.mp3"));
        soundPlayer.play();
        ui->text->setText("Génial!");
        ui->text2->setText("R2D2 a réussi à se sortir de la vase! Il va pouvoir rejoindre Luke et vous la page suivante.");
        setPageFinished();
    }
}
void R2D2MudPage::enableSound(){
    soundPlayer.setVolume(100);
    musicPlayer.setVolume(100);
}
void R2D2MudPage::disableSound(){
    soundPlayer.setVolume(0);
    musicPlayer.setVolume(0);
}

