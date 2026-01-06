#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
     ~MainWindow();
    void unlockNextPage();//débloque le bouton suivant (accès à la page suivante)
    bool getSoundEnabled() { return soundEnabled; }//getter de soundEnabled
    void updatePageSoundState();//met à jour l'état du son des pages

protected:
    void closeEvent(QCloseEvent *event) override;//evenement de fermeture de l'application

private slots:
    void on_nextButtton_clicked();
    void on_prevButton_clicked();
    void on_soundButton_clicked();
    void on_exitButton_clicked();
    void on_resetButton_clicked();

private:
    Ui::MainWindow *ui;
    bool soundEnabled=true;//etat du son (on ou off)

};

#endif // MAINWINDOW_H
