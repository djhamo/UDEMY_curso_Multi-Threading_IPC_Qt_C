#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

void counting1(int count){
    qDebug() << "Counting : thread : " <<  QThread::currentThread();
    for(int i{0} ; i < count ; i ++){
        qDebug() << "Counting : " << i ;
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pbStart_clicked()
{
    //counting1(10000);

    thread = QThread::create([]{
        counting1(10000);
    });

    connect(thread,&QThread::started,[](){
        qDebug() << "Thread started";
    });

    connect(thread, &QThread::finished, []{
        qDebug() << "Thread finished";
    });
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    thread->start();
}
