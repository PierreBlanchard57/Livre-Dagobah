#ifndef R2D2MUDPAGE_H
#define R2D2MUDPAGE_H

#include <QWidget>
#include <QMediaPlayer>
#include "page.h"
#include "ui_r2d2mudpage.h"
#include "effectmanager.h"
class R2D2MudPage : public Page
{
    Q_OBJECT
public:
    explicit R2D2MudPage(QWidget *parent = nullptr,MainWindow *mainwindow=nullptr);
    void enableSound() override;
    void disableSound()override;
    ~R2D2MudPage();
protected:
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;
private:
    Ui::R2D2MudPage *ui;
    EffectManager effects;
    QMediaPlayer musicPlayer;
    QMediaPlayer soundPlayer;
    bool eventFilter(QObject *watched, QEvent *event);
    void tryFinishPage();
};

#endif // R2D2MUDPAGE_H
