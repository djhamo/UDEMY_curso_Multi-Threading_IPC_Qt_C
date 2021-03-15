#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug() << "Widget Thread " << QThread::currentThread();
    workThread = new WorkThread(this);

    connect(workThread,&WorkThread::currentCount,this,&Widget::currentCount);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pbStart_clicked()
{
    workThread->start();
}

void Widget::on_pbPause_clicked()
{
    workThread->pause();
}

void Widget::on_pbResume_clicked()
{
    workThread->resume();
}

void Widget::currentCount(int value)
{
    ui->progressBar->setValue(value);
}
