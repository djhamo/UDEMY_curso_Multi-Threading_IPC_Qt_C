#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include "worker.h"

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    workerThread = new WorkerThread(this);
    connect(workerThread, &WorkerThread::currentCount, this, &Widget::currentCount);

    connect(workerThread, &QThread::started, []() { qDebug() << "Thread STart";});
    connect(workerThread, &QThread::finished, []() { qDebug() << "Thread Finished";});

    thread = new QThread(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pbStart_clicked()
{
    workerThread->start();

    Worker *worker = new Worker();
    worker->moveToThread(thread);

    connect(thread,&QThread::started,worker,&Worker::doWork);

    connect(thread,&QThread::finished,[](){
        qDebug() << "Thread finished";
    });

    connect(thread,&QThread::finished,worker,&Worker::deleteLater);

    thread->start();
}

void Widget::on_pbInfo_clicked()
{
    qDebug() << "Thread  is running : " << workerThread->isRunning();
    qDebug() << "Thread  is running : " << thread->isRunning();
}

void Widget::currentCount(int value)
{
    ui->progressBar->setValue(value);
    ui->infoLabel->setText(QString::number(value));
}

void Widget::on_pbStop_clicked()
{
    thread->exit();
}
