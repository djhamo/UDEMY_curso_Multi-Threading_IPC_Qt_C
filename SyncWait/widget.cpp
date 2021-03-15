#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QTime>

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    total_data = 100000;
    used_slots = 0;

    producer = new Producer(buffer, m_BUFFER_SIZE, &used_slots, total_data, &mutex, &buffer_full, &buffer_empty);

    consumer = new Consumer(buffer, m_BUFFER_SIZE, &used_slots, total_data, &mutex, &buffer_full, &buffer_empty);

    connect(producer,&QThread::finished,[](){
        qDebug() << "Producer Thread finished";
    });

    connect(consumer,&QThread::finished,[](){
        qDebug() << "Consumer Thread finished";
    });
    one_run = false;
}

Widget::~Widget()
{
    delete ui;
    delete producer;
    delete consumer;
    delete thread;
}


void Widget::on_pbStart_clicked()
{

    if(one_run) {
        if(thread->isRunning()) {
            qDebug() << "Já está rodando";
            return;
        }
    }
    one_run = true;
    qDebug() << "Start";
    thread = QThread::create([=]{
        for (int i = 0; i < 1000; i++) {
            qDebug() << "loop " << i;

            producer->start();
            consumer->start();

            producer->wait();
            consumer->wait();

            if(QThread::currentThread()->isInterruptionRequested()) {
                qDebug() << "Pedi pra parar";
                break;
            }

            thread->sleep(1);

        }
    });
    connect(thread,&QThread::started,[](){
        qDebug() << "Thread started";
    });

    connect(thread,&QThread::finished,[](){
        qDebug() << "Thread finished";
    });

    //connect(thread,&QThread::finished,thread,&QThread::deleteLater);
    thread->start();

}

void Widget::on_pbStop_clicked()
{
    qDebug() << "Stop";
    thread->exit();
    thread->requestInterruption();
    producer->requestInterruption();
    consumer->requestInterruption();
    one_run = false;
}
