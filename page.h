#ifndef PAGE_H
#define PAGE_H
#include <QWidget>
#include "mainwindow.h"
class Page : public QWidget {
    Q_OBJECT
public:


    bool isPageFinished() const;
    virtual void enableSound();
    virtual void disableSound();
    virtual ~Page();
protected:
    explicit Page(QWidget *parent = nullptr,MainWindow *mainWindow=nullptr);
    void setPageFinished();
    bool pageFinished = false;

    MainWindow *mainWindow;


};
#endif // PAGE_H
