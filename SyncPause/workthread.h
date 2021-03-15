#ifndef WORKTHREAD_H
#define WORKTHREAD_H

#include <QThread>
#include <QWaitCondition>
#include <QMutex>

class WorkThread : public QThread
{
    Q_OBJECT
public:
    explicit WorkThread(QObject *parent = nullptr);
    ~WorkThread() override;

signals:
    void currentCount(int value);

public slots:
    void resume();
    void pause();


    // QThread interface
protected:
    void run() override;

private:
    QMutex m_mutex;
    QWaitCondition m_pause_condition;
    bool m_pause;
};

#endif // WORKTHREAD_H
