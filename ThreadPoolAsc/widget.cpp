#include "widget.h"
#include "ui_widget.h"
#include "worker.h"
#include "progressevent.h"
#include <QDebug>
#include <QThreadPool>

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug() << "Ui thread :" << QThread::currentThread();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::gotUpdate(int value)
{
    ui->progressBar->setValue(value);
}

void Widget::on_pbStart_clicked()
{
    Worker * worker = new Worker(this);


    QThreadPool::globalInstance()->start(worker);
}

void Widget::on_pbStop_clicked()
{


}


void Widget::on_pbInfo_clicked()
{
    qDebug() << "ThreadPool max thread count : " << QThreadPool::globalInstance()->maxThreadCount();

    qDebug()  << " Ideal thread count : " << QThread::idealThreadCount();

}

bool Widget::event(QEvent *event)
{
    if(event->type() == static_cast<QEvent::Type>(ProgressEvent::EventId)){

        ProgressEvent * progressEvent = static_cast<ProgressEvent *>(event);

        //qDebug() << "Widget , progress is : " << progressEvent->progress();

        ui->progressBar->setValue(progressEvent->progress());

        return  true;
    }

    return QWidget::event(event);

}
