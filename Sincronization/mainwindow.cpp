#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dataSource << 1 << 2 << 34 << 55 << 4 << 11 << 22 << 34 << 55 << 4 << 1 << 2 << 34 << 55 << 4 << 1 << 2 << 34 << 55 << 4 << 2222;

    atEnd = false;

    free_space = new QSemaphore(BUFFER_SIZE);
    av_space = new QSemaphore(0);

    producer = new Producer(dataSource, bufferArray, BUFFER_SIZE, free_space, av_space, &atEnd);
    consumer = new Consumer(bufferArray, BUFFER_SIZE, free_space, av_space, &atEnd);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pbStart_clicked()
{
    producer->start();
    consumer->start();

    producer->wait();
    consumer->wait();

    atEnd = false;
}
