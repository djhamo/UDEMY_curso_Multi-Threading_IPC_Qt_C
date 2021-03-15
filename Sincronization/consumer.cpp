#include "consumer.h"
#include <QDebug>

Consumer::Consumer(int *buffer,
                   int BUFFER_SIZE,
                   QSemaphore *free_space,
                   QSemaphore *available_space,
                   bool *at_end, QObject *parent) :
    QThread(parent),
    m_buffer(buffer),
    m_BUFFER_SIZE(BUFFER_SIZE),
    m_free_space(free_space),
    m_available_space(available_space),
    m_at_end(at_end)
{

}

void Consumer::run()
{
    int i = 0;

    while (!(* m_at_end) || m_available_space->available()) {
        m_available_space->acquire();

        qDebug() << "[" << i << "] " << m_buffer[i];

        i = ((i + 1) % (m_BUFFER_SIZE));

        m_free_space->release();
    }

}
