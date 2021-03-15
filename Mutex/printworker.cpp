#include "printworker.h"
#include <QDebug>
#include <QTime>
#include <QMutexLocker>
/*
PrintWorker::PrintWorker(QObject *parent) : QThread(parent)
{

}
*/
PrintWorker::PrintWorker(QString name, bool *stop, PrintDevice *print_device, QObject *parent):
    QThread(parent),
    m_name(name),
    m_stop(stop),
    m_print_device(print_device)
{

}

PrintWorker::~PrintWorker()
{

}

void PrintWorker::run()
{
    while(!(* m_stop)){
        /*
        //m_mutex->lock();
        //QMutexLocker locker(m_mutex);

        if ((* m_stop)) {
            //m_mutex->unlock();
            return;
        }

        qDebug() << m_name;
        sleep(1);

        //m_mutex->unlock();
        */
        m_print_device->print(m_name);
        sleep(1);
    }

}
