#ifndef PAGE_H
#define PAGE_H
#include <QWidget>
#include "mainwindow.h"
class Page : public QWidget {
    Q_OBJECT
public:


    bool isPageFinished() const;
protected:
    explicit Page(QWidget *parent = nullptr,MainWindow *mainWindow=nullptr);
    void setPageFinished();
    MainWindow *mainWindow;
private:

    bool pageFinished = false;
};
#endif // PAGE_H
