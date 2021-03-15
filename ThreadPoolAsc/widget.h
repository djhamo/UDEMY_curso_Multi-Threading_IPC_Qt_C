#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots :
    void gotUpdate(int value);

private slots:
    void on_pbStart_clicked();

    void on_pbStop_clicked();

    void on_pbInfo_clicked();

public:
    bool event(QEvent *event) override;

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
