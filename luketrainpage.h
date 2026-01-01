#ifndef LUKETRAINPAGE_H
#define LUKETRAINPAGE_H

#include <QWidget>
#include "page.h"
#include "ui_luketrainpage.h"
class LukeTrainPage : public Page
{
    Q_OBJECT
public:
    explicit LukeTrainPage(QWidget *parent = nullptr,MainWindow *mainwindow=nullptr);
private:
    Ui::LukeTrainPage *ui;
    int rocksPlaced=0;
    bool isDragging=false;
    void unlock();
};

#endif // LUKETRAINPAGE_H
