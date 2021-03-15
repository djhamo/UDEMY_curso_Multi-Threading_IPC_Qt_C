#include "workerthread.h"
#include <QDebug>

WorkerThread::WorkerThread(QObject *parent) : QThread(parent)
{
    qDebug() << "Worker thread constructor running in thread : " << QThread::currentThread();
}

WorkerThread::~WorkerThread()
{
    qDebug() << "Worker thread destructor running in thread : " << QThread::currentThread();
}

void WorkerThread::run()
{
    qDebug() << "Run method of thread running in thread : " << QThread::currentThread();

    for(int i{0} ; i < 1000000001 ; i++){
        if((i%100000) == 0){
            double percentage = ((i/1000000000.0)) * 100;
            emit currentCount(QVariant::fromValue(percentage).toInt());
        }
    }

}
