#ifndef QTEBUTTON_H
#define QTEBUTTON_H

#include <QPushButton>
#include <QElapsedTimer>

class QTEButton : public QPushButton
{
    Q_OBJECT
public:
    QTEButton(qint64 msTimeout, QWidget *parent = nullptr);

signals:
    void buttonTimeout();

protected:
    void paintEvent(QPaintEvent *) override;

private:
    QElapsedTimer timer;
    qint64 timeout;
    QImage image;
};

#endif // QTEBUTTON_H
