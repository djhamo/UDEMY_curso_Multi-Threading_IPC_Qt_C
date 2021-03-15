#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSemaphore>
#include <QVector>
#include "producer.h"
#include "consumer.h"

const int BUFFER_SIZE = 6;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pbStart_clicked();

private:
    Ui::MainWindow *ui;
    Producer *producer;
    Consumer *consumer;

    QVector<int> dataSource;
    int bufferArray[BUFFER_SIZE];
    QSemaphore *free_space; //Onde posso gravar dados
    QSemaphore *av_space; //Onde posso ler dados
    bool atEnd;
};
#endif // MAINWINDOW_H
