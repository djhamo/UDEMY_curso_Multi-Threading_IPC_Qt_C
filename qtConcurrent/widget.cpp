#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QThread>
#include <QtConcurrent>


Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug() << "Ui thread : " << QThread::currentThread();

    connect(&watcher,&QFutureWatcher<void>::finished,[=](){
        qDebug() << "---------------------------Computation done----------------------";


        if(!watcher.isCanceled()){

            QVector<int> resultVector = watcher.result();

            qDebug() << "Number of items in resultVector : " << resultVector.count();

            for( int i{0}; i < resultVector.count(); i++){
                qDebug() << " element [" << i << "] : " << resultVector[i];
            }

        }else{
            qDebug() << "Watcher already canceled ";
        }

    });

    //connect(&watcher, &QFutureWatcher<void>::progressValueChanged, ui->progressBar, &QProgressBar::setValue);
    connect(&watcher, &QFutureWatcher<void>::progressValueChanged,this,&Widget::currentCount);

}

Widget::~Widget()
{
    delete ui;
}

QFuture<QVector<int>> Widget::fullheavyWork()
{
    auto heavyWork = [=](){

        qDebug() << "Heavy work running in thread : " << QThread::currentThread();

        QVector<int> intVector;

        for(int i{0} ; i < 1000000001 ; i++){

            if((i%100000) == 0){
                double percentage = ((i/1000000000.0)) * 100;
                qDebug() << "Heavy work with return : " << QVariant::fromValue(percentage).toInt() ;
                intVector.push_back(QVariant::fromValue(percentage).toInt());
                emit watcher.progressValueChanged(QVariant::fromValue(percentage).toInt());
            }

        }
        return  intVector;
    };
    return QtConcurrent::run(heavyWork);
}

void Widget::on_pbStart_clicked()
{
    future = fullheavyWork();
    watcher.setFuture(future);
}

void Widget::on_pbStop_clicked()
{
    watcher.cancel();
}

void Widget::on_pbPause_clicked()
{
    watcher.pause();
}

void Widget::on_pbResume_clicked()
{
    watcher.resume();
}

void Widget::currentCount(int value)
{
    ui->progressBar->setValue(value);
}
