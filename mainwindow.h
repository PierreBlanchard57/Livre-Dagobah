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
    void unlockNextPage();
    bool getSoundEnabled();

private slots:
    void on_nextButtton_clicked();

    void on_prevButton_clicked();

    void on_soundButton_clicked();

private:
    Ui::MainWindow *ui;
    bool soundEnabled=true;
};

#endif // MAINWINDOW_H
