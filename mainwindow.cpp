#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"page.h"
#include "titlepage.h"
#include "lukeduelpage.h"
#include "luketrainpage.h"
#include "r2d2mudpage.h"
#include "endpage.h"
#include <qlayout.h>
#include <iostream>
#include <QDebug>

int currentPage=0;
const int pageNumber=6;
std::vector<Page*> pages;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //pages
    pages.push_back(new LukeTrainPage(ui->pageContainer,this));
    pages.push_back(new R2D2MudPage(ui->pageContainer,this));
    pages.push_back(new TitlePage(ui->pageContainer));
    pages.push_back(new LukeDuelPage(ui->pageContainer,this));
    pages.push_back(new TitlePage(ui->pageContainer));


    pages.push_back(new EndPage(ui->pageContainer));

    for (int i = 0; i < pages.size(); ++i) {
       pages[i]->setVisible(i == 0);
    }
    //maj du label de pages
    ui->pageLabel->setText("Page 1/"+QString::number(pageNumber));

}
void MainWindow::unlockNextPage(){
   ui->nextButtton->setEnabled(true);
}

MainWindow::~MainWindow()
{
    for (int i = 0; i < pages.size(); ++i) {
       delete pages[i];
    }
    delete ui;
}

void MainWindow::on_prevButton_clicked()
{
    if(currentPage>0){
        currentPage--;
        if(currentPage==0)ui->prevButton->setEnabled(false);
        if(currentPage==pageNumber-2)ui->nextButtton->setEnabled(true);
        else ui->nextButtton->setEnabled(pages[currentPage]->isPageFinished());
        ui->pageLabel->setText("Page "+QString::number(currentPage+1)+"/"+QString::number(pageNumber));
        pages[currentPage+1]->setVisible(false);
        pages[currentPage]->setVisible(true);
    }

}
void MainWindow::on_nextButtton_clicked()
{
    if(pageNumber>currentPage-1 && pages[currentPage]->isPageFinished()){
        currentPage++;
        if(currentPage>0)ui->prevButton->setEnabled(true);
        if(currentPage==pageNumber-1)ui->nextButtton->setEnabled(false);
        else ui->nextButtton->setEnabled(pages[currentPage]->isPageFinished());
        ui->pageLabel->setText("Page "+QString::number(currentPage+1)+"/"+QString::number(pageNumber));
        pages[currentPage-1]->setVisible(false);
        pages[currentPage]->setVisible(true);

        }

}


void MainWindow::on_soundButton_clicked()
{
    soundEnabled=!soundEnabled;
    if(soundEnabled){
        pages[currentPage]->enableSound();
        ui->soundButton->setIcon(QIcon("sound_on.png"));
    }
    else{

        pages[currentPage]->disableSound();
        ui->soundButton->setIcon(QIcon("sound_off.png"));
    }
}
bool MainWindow::getSoundEnabled(){ return soundEnabled;}
