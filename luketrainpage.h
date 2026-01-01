#ifndef LUKETRAINPAGE_H
#define LUKETRAINPAGE_H

#include <QWidget>
#include <QObject>
#include <QEvent>
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
    const double gravity=5;
    bool eventFilter(QObject *watched, QEvent *event);
    void changeLukePose(const std::string &file);
    void unlock();
};

#endif // LUKETRAINPAGE_H
