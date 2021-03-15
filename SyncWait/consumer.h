#ifndef CONSUMER_H
#define CONSUMER_H
#include <QWaitCondition>
#include <QMutex>

#include <QThread>

class Consumer : public QThread
{
    Q_OBJECT
public:
    explicit Consumer(char *buffer,
                      int buffer_size,
                      int *used_slots,
                      int total_data,
                      QMutex *mutex,
                      QWaitCondition *buffer_full,
                      QWaitCondition *buffer_empty,
                      QObject *parent = nullptr);

signals:

protected:
    void run() override;

private:
    char *m_buffer;
    int m_buffer_size;
    int *m_used_slots;
    int m_total_data;
    QMutex *m_mutex;
    QWaitCondition *m_buffer_full;
    QWaitCondition *m_buffer_empty;
};

#endif // CONSUMER_H
