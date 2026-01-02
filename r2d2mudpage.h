#ifndef R2D2MUDPAGE_H
#define R2D2MUDPAGE_H

#include <QWidget>
#include "page.h"
#include "ui_r2d2mudpage.h"
class R2D2MudPage : public Page
{
    Q_OBJECT
public:
    explicit R2D2MudPage(QWidget *parent = nullptr,MainWindow *mainwindow=nullptr);

private:
    Ui::R2D2MudPage *ui;
};

#endif // R2D2MUDPAGE_H
