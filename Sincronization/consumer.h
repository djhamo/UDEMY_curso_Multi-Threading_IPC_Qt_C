#ifndef CONSUMER_H
#define CONSUMER_H

#include <QThread>
#include <QSemaphore>

class Consumer : public QThread
{
    Q_OBJECT
public:
    explicit Consumer(int *buffer,
                      int BUFFER_SIZE,
                      QSemaphore *free_space,
                      QSemaphore *available_space,
                      bool *at_end,
                      QObject *parent = nullptr);

    // QThread interface
protected:
    void run() override;

private:
    int *m_buffer;
    int m_BUFFER_SIZE;
    QSemaphore *m_free_space; //Onde posso gravar dados
    QSemaphore *m_available_space; //Onde posso ler dados
    bool *m_at_end;
};

#endif // CONSUMER_H
