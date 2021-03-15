#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include "workerthread.h"
#include <QTimer>

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

    void on_pbInfo_clicked();

    void currentCount(int value);

    void on_pbStop_clicked();

private:
    Ui::Widget *ui;
    WorkerThread *workerThread;
    QThread *thread;
};
#endif // WIDGET_H
