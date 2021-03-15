#include "producer.h"

Producer::Producer(QVector<int> &data_source,
                   int *buffer,
                   int BUFFER_SIZE,
                   QSemaphore *free_space,
                   QSemaphore *available_space,
                   bool *at_end, QObject *parent) :
    QThread(parent),
    m_data_source(data_source),
    m_buffer(buffer),
    m_BUFFER_SIZE(BUFFER_SIZE),
    m_free_space(free_space),
    m_available_space(available_space),
    m_at_end(at_end)
{

}

void Producer::run()
{

    for(int i{0}; i < m_data_source.length(); i++) {

        m_free_space->acquire();

        m_buffer[i % m_BUFFER_SIZE] = m_data_source.at(i);

        if(i == (m_data_source.length() - 1))
            *m_at_end = true;

        m_available_space->release();
    }
}
