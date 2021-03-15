#ifndef PRODUCER_H
#define PRODUCER_H

#include <QThread>
#include <QSemaphore>
#include <QVector>

class Producer : public QThread
{
    Q_OBJECT
public:
    explicit Producer(QVector<int> &data_source,
                      int *buffer,
                      int BUFFER_SIZE,
                      QSemaphore *free_space,
                      QSemaphore *available_space,
                      bool *at_end,
                      QObject *parent = nullptr);

    // QThread interface
protected:
    void run() override;

private:
    QVector<int> m_data_source;
    int *m_buffer;
    int m_BUFFER_SIZE;
    QSemaphore *m_free_space; //Onde posso gravar dados
    QSemaphore *m_available_space; //Onde posso ler dados
    bool *m_at_end;
};

#endif // PRODUCER_H
