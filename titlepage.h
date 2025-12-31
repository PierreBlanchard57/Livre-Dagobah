
#include <QWidget>
#include "page.h"
#include "ui_titlepage.h"

class TitlePage : public Page {
    Q_OBJECT
public:
    explicit TitlePage(QWidget *parent = nullptr);
private:
    Ui::TitlePage *ui;
};
