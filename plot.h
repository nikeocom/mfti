#ifndef PLOT_H
#define PLOT_H

#include <QGraphicsView>

class Plot: public QGraphicsView
{

public:
    Plot(QWidget *parent = nullptr);

public slots:
    void drawPoint(const QPoint &point);
    void clear();

protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override final;
    void resizeEvent(QResizeEvent *event) override;

};

#endif // PLOT_H
