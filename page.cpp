#include "page.h"
#include <QDebug>
Page::Page(QWidget *parent,MainWindow *mainwindow) : QWidget(parent), pageFinished(false)
{
    this->mainWindow=mainwindow;
}

void Page::setPageFinished() {
    pageFinished = true;
    if(mainWindow!=nullptr)mainWindow->unlockNextPage();
    else qDebug()<< "Could not unlock next page: mainWindow is null!";
                             }
bool Page::isPageFinished() const { return pageFinished; }

void Page::enableSound(){}
void Page::disableSound(){}
Page::~Page(){

}
