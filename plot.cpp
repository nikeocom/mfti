#include "plot.h"


Plot::Plot(QWidget *parent)
    : QGraphicsView(new QGraphicsScene, parent)
{
}

void Plot::drawPoint(const QPoint &point)
{
    scene()->addEllipse(QRectF(point, QSize(10, 10)), QPen(), QBrush(QColor("blue")));
    update(QRect(point, QSize(10, 10)));
}

void Plot::clear()
{
    scene()->clear();
}

void Plot::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect)

    painter->save();
    painter->setPen(QColor("green"));
    painter->drawLine(0, height() - 20, width() - 20, height() - 20);
    painter->drawLine(0, height() - 20, 0, 0);

    painter->setPen(QPen(QColor("green"), 0.2, Qt::DashDotLine));
    for (int i = 50; i < width() - 20; i += 50) {
        painter->drawLine(i, 0, i, height() - 20);
    }
    for (int i = 50; i < height() - 20; i += 50) {
        painter->drawLine(0, i, width() - 20, i);
    }
    painter->restore();
}

void Plot::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    scene()->setSceneRect(0, 0, width() - 20, height() - 20);
}


