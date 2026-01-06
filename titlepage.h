
#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "page.h"
#include "ui_titlepage.h"

class TitlePage : public Page {
    Q_OBJECT
public:
    explicit TitlePage(QWidget *parent = nullptr);
    void enableSound() override;
    void disableSound()override;
    ~TitlePage();

protected:
    void showEvent(QShowEvent *event) override;//evenement d'affichage de la page
    void hideEvent(QHideEvent *event) override;//evenement de cache de la page

private:
    Ui::TitlePage *ui;

    QMediaPlayer musicPlayer;//mediaplayer pour la musique
    QMediaPlaylist audioList;//mediaplaylist pour fonctionner avec le mediaplayer
};
