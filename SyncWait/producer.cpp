#include "producer.h"
#include <QRandomGenerator>
#include <QDebug>

Producer::Producer(char *buffer,
                   int buffer_size,
                   int *used_slots,
                   int total_data,
                   QMutex *mutex,
                   QWaitCondition *buffer_full,
                   QWaitCondition *buffer_empty,
                   QObject *parent) :
    QThread(parent),
    m_buffer(buffer),
    m_buffer_size(buffer_size),
    m_used_slots(used_slots),
    m_total_data(total_data),
    m_mutex(mutex),
    m_buffer_full(buffer_full),
    m_buffer_empty(buffer_empty)
{

}

void Producer::run()
{
    for(int i{0}; i < m_total_data; i++) {

        m_mutex->lock();
        {
            if(*m_used_slots == m_buffer_size) {
                m_buffer_full->wait(m_mutex);
            }

        }
        m_mutex->unlock();

        m_buffer[i % m_buffer_size] = "BACK"[QRandomGenerator::global()->bounded(4)];

        m_mutex->lock();
        {
            ++(*m_used_slots);
            m_buffer_empty->wakeAll();
        }
        m_mutex->unlock();

        if(this->isInterruptionRequested()) {
            qDebug() << "Pedi pra parar Producer";
            break;
        }

    }

}
