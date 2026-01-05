#include "titlepage.h"
#include "page.h"

bool soundEnabled=true;
TitlePage::TitlePage(QWidget *parent) : Page(parent,nullptr),ui(new Ui::TitlePage)
{
    ui->setupUi(this);
    Page::setPageFinished();//C'est la page de titre alors elle est directement terminée

    if(soundEnabled){
        audioList.addMedia(QUrl("./pages_m/menu.wav"));
        audioList.setPlaybackMode(QMediaPlaylist::Loop);
        musicPlayer.setPlaylist(&audioList);
    }

}

void TitlePage::showEvent(QShowEvent *event)
{
    musicPlayer.play();
}

void TitlePage::hideEvent(QHideEvent *event)
{
    musicPlayer.stop();
}

void TitlePage::enableSound(){
musicPlayer.play();
soundEnabled=true;
}
void TitlePage::disableSound(){
    musicPlayer.stop();
    soundEnabled=false;
}
