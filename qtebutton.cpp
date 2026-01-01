#include "qtebutton.h"
#include <QPainter>

#define QTEBUTTON_INNER_RADIUS 3

QTEButton::QTEButton(qint64 msTimeout, QWidget *parent)
    : QPushButton(parent)
{
    timeout = msTimeout;
    timer.start();
}

void QTEButton::paintEvent(QPaintEvent *)
{
    auto elapsed = timer.elapsed();
    if (elapsed > timeout) {
        deleteLater();
        return;
    }

    auto completion = (double)elapsed / (double)timeout;

    QPainter painter(this);
    QPen pen;
    pen.setBrush(Qt::SolidPattern);
    pen.setColor((elapsed >> 8) & 0x01? Qt::red : Qt::white);
    pen.setWidth(2);
    painter.setPen(pen);
    // anneau exterieur
    painter.drawEllipse(QPoint(width()>>1, height()>>1),
                        (1.0 - completion) * (width()>>1), (1.0 - completion) * (height()>>1));
    // anneau interieur
    if ((1.0 - completion) * (height()>>1) > QTEBUTTON_INNER_RADIUS)
        painter.drawEllipse(QPoint(width()>>1, height()>>1), QTEBUTTON_INNER_RADIUS, QTEBUTTON_INNER_RADIUS);
    //painter.fillRect(0, 0, width(), height(), Qt::GlobalColor::red);
    update(); // invalidation immédiate
}
