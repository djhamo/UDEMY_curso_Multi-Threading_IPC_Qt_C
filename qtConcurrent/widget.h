#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QFuture>
#include <QFutureWatcher>


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

    void on_pbPause_clicked();

    void on_pbResume_clicked();
    void currentCount(int value);

private:
    static QFuture<QVector<int>> fullheavyWork();
    Ui::Widget *ui;
    QFuture<QVector<int>> future;
    QFutureWatcher<QVector<int>> watcher;
};
#endif // WIDGET_H
