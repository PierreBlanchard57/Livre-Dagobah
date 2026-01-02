
#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "page.h"
#include "ui_titlepage.h"

class TitlePage : public Page {
    Q_OBJECT
public:
    explicit TitlePage(QWidget *parent = nullptr);

protected:
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;

private:
    Ui::TitlePage *ui;

    QMediaPlayer musicPlayer;
    QMediaPlaylist audioList;
};
