#include "workthread.h"
#include <QDebug>
#include <QVariant>

WorkThread::WorkThread(QObject *parent) : QThread(parent)
{
    m_pause = false;
    qDebug() << "Workthread created " << QThread::currentThread();;
}

WorkThread::~WorkThread()
{
    qDebug() << "Workthread destroyed " << QThread::currentThread();;
}

void WorkThread::resume()
{
    qDebug() << "Resume " << QThread::currentThread();
    m_mutex.lock();
    m_pause = false;
    m_mutex.unlock();
    m_pause_condition.wakeAll();
}

void WorkThread::pause()
{
    qDebug() << "Pause " << QThread::currentThread();
    m_mutex.lock();
    m_pause = true;
    m_mutex.unlock();
}

void WorkThread::run()
{
    qDebug() << "Run " << QThread::currentThread();

    for(int i{0}; i < 1000000001; i++) {
        m_mutex.lock();

        if(m_pause)
            m_pause_condition.wait(&m_mutex);

        m_mutex.unlock();

        if ((i % 100000) == 0) {
            double percentage = ((i / 1000000000.0) * 100);
            emit currentCount(QVariant::fromValue(percentage).toInt());
        }
    }
}
