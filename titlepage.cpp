#include "titlepage.h"
#include "page.h"

TitlePage::TitlePage(QWidget *parent) : Page(parent,nullptr),ui(new Ui::TitlePage)
{
    ui->setupUi(this);
    Page::setPageFinished();//C'est la page de titre alors elle est directement terminée

    audioList.addMedia(QUrl("./pages_m/menu.wav"));
    audioList.setPlaybackMode(QMediaPlaylist::Loop);
    musicPlayer.setPlaylist(&audioList);
}

void TitlePage::showEvent(QShowEvent *event)
{
    musicPlayer.play();
}

void TitlePage::hideEvent(QHideEvent *event)
{
    musicPlayer.stop();
}
