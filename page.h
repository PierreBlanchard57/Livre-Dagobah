#ifndef PAGE_H
#define PAGE_H
#include <QWidget>
#include "mainwindow.h"
class Page : public QWidget {
    Q_OBJECT
public:


    bool isPageFinished() const;//getter de pageFinished
    virtual void enableSound();//activer le don de la page
    virtual void disableSound();//desactiver le son de la page
    virtual ~Page();
protected:
    explicit Page(QWidget *parent = nullptr,MainWindow *mainWindow=nullptr);
    void setPageFinished();//setter de pageFinished
    bool pageFinished = false;//etat fini/en cours de la page

    MainWindow *mainWindow;//pointeur sur l'objet mainwindow de l'application pour pouvoir lui demander des choses sur l'ui principale


};
#endif // PAGE_H
