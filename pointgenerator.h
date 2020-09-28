#ifndef POINTGENERATOR_H
#define POINTGENERATOR_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QPoint>

class PointGenerator : public QThread
{
    Q_OBJECT

public:
    PointGenerator(qint32 highest);

signals:
    void generatedPoint(const QPoint &p);

public slots:
    void pause();
    void play();
    void stop();

protected:
    void run() override final;

private:
    qint32 m_highest;
    bool m_paused;

    QMutex m_locker;
    QWaitCondition m_condition;
};

#endif // POINTGENERATOR_H
