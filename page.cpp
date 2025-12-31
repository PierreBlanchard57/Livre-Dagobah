#include "page.h"

Page::Page(QWidget *parent,MainWindow *mainwindow) : QWidget(parent), pageFinished(false)
{
    this->mainWindow=mainwindow;
}

void Page::setPageFinished() { pageFinished = true; }
bool Page::isPageFinished() const { return pageFinished; }
