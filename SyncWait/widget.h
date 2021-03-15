#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QWaitCondition>
#include <QMutex>
#include "consumer.h"
#include "producer.h"

const int m_BUFFER_SIZE = 6000;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pbStart_clicked();

    void on_pbStop_clicked();

private:
    Ui::Widget *ui;
    char buffer[m_BUFFER_SIZE];
    int used_slots;
    int total_data;
    QMutex mutex;
    QWaitCondition buffer_full;
    QWaitCondition buffer_empty;
    Consumer *consumer;
    Producer *producer;

    QThread *thread;
    bool one_run;
};
#endif // WIDGET_H
