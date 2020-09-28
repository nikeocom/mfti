#include "pointgenerator.h"

#include <QRandomGenerator>
#include <QMutexLocker>

PointGenerator::PointGenerator(qint32 highest)
    : QThread(),
      m_highest(highest),
      m_paused(false)
{

}

void PointGenerator::pause()
{
    QMutexLocker guard(&m_locker);
    m_paused = true;
}

void PointGenerator::play()
{
    if (isRunning() && m_paused) {
        QMutexLocker guard(&m_locker);
        m_paused = false;
        m_condition.wakeAll();
    } else {
        start();
    }
}

void PointGenerator::stop()
{
    if (m_paused) {
        QMutexLocker guard(&m_locker);
        m_paused = false;
        m_condition.wakeAll();
    }
    requestInterruption();
}

void PointGenerator::run()
{
    forever  {
        m_locker.lock();
        if (m_paused) {
            m_condition.wait(&m_locker);
        }
        m_locker.unlock();

        if (!isInterruptionRequested()) {
            auto point = QPoint(QRandomGenerator::global()->bounded(m_highest),
                                QRandomGenerator::global()->bounded(m_highest));
            emit generatedPoint(point);
        } else {
            return;
        }

        sleep(1);
    }
}
