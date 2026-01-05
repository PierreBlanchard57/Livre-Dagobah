#ifndef LUKETRAINPAGE_H
#define LUKETRAINPAGE_H

#include <QWidget>
#include <QObject>
#include <QEvent>
#include <QMediaPlayer>
#include "page.h"
#include "ui_luketrainpage.h"
#include "effectmanager.h"
class LukeTrainPage : public Page
{
    Q_OBJECT
public:
    explicit LukeTrainPage(QWidget *parent = nullptr,MainWindow *mainwindow=nullptr);
    void enableSound() override;
    void disableSound()override;
    ~LukeTrainPage();
    static const int toleratedPos=420;
protected:
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;
private:
    Ui::LukeTrainPage *ui;
    int cumulativeRocksY=190;
    bool isDragging=false;
    QPoint offset;
    EffectManager effects;

    QMediaPlayer musicPlayer;
    QMediaPlayer soundPlayer;
    bool eventFilter(QObject *watched, QEvent *event);
    void changeLukePose(const std::string &file);
    void changeRockSprite(QLabel *rock,const std::string &file);
    int determineGround(int posX,int id);
    void tryFinishPage();
    void updateRockPos();
    void unlock();
};

#endif // LUKETRAINPAGE_H
