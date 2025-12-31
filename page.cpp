#include "page.h"

Page::Page(QWidget *parent,MainWindow *mainwindow) : QWidget(parent), pageFinished(false)
{
    this->mainWindow=mainWindow;
}

void Page::setPageFinished() { pageFinished = true; }
bool Page::isPageFinished() const { return pageFinished; }
