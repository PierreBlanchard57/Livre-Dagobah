#ifndef ENDPAGE_H
#define ENDPAGE_H

#include <QWidget>
#include "page.h"
#include "ui_endpage.h"
class EndPage : public Page {
    Q_OBJECT
public:
    explicit EndPage(QWidget *parent = nullptr);
    void enableSound() override;
    void disableSound()override;
    ~EndPage();

private:
    Ui::EndPage *ui;
};

#endif // ENDPAGE_H
