#include "worker.h"
#include <QDebug>
#include <QThread>
#include <QApplication>
#include <QMetaObject>
#include <QTimer>
#include <QVariant>
#include "progressevent.h"

Worker::Worker(QObject * receiver) : m_receiver(receiver)
{
    qDebug() << "Worker constructor running in thread : " << QThread::currentThread();
}

Worker::~Worker(){
    qDebug() << "Worker destructor running in thread : " << QThread::currentThread();

}

void Worker::run()
{
    qDebug() << "Worker run method running in thread : " << QThread::currentThread();


    QTimer * timer = new QTimer();
    QObject::connect(timer,&QTimer::timeout,[](){
        qDebug() << "Time out . Running in thread : " << QThread::currentThread();
    });
    timer->setInterval(10);
    timer->start();

}
