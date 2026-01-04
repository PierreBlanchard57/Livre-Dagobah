#ifndef R2D2MUDPAGE_H
#define R2D2MUDPAGE_H

#include <QWidget>
#include "page.h"
#include "ui_r2d2mudpage.h"
#include "effectmanager.h"
class R2D2MudPage : public Page
{
    Q_OBJECT
public:
    explicit R2D2MudPage(QWidget *parent = nullptr,MainWindow *mainwindow=nullptr);

private:
    Ui::R2D2MudPage *ui;
    EffectManager effects;
    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // R2D2MUDPAGE_H
