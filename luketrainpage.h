#ifndef LUKETRAINPAGE_H
#define LUKETRAINPAGE_H

#include <QWidget>
#include <QObject>
#include <QEvent>
#include "page.h"
#include "ui_luketrainpage.h"
#include "effectmanager.h"
class LukeTrainPage : public Page
{
    Q_OBJECT
public:
    explicit LukeTrainPage(QWidget *parent = nullptr,MainWindow *mainwindow=nullptr);
private:
    Ui::LukeTrainPage *ui;
    bool rocksPlaced[3]={};
    int rocksFinalY[3]={};
    int cumulativeRocksY=170;
    bool isDragging=false;
    const double gravity=5;
    const int toleratedPos=420;
    QPoint offset;
    EffectManager effects;
    bool eventFilter(QObject *watched, QEvent *event);
    void changeLukePose(const std::string &file);
    int determineGround(int posX,int id);
    void updateRockPos();
    void unlock();
};

#endif // LUKETRAINPAGE_H
