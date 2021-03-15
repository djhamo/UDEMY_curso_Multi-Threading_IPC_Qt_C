#ifndef PRINTWORKER_H
#define PRINTWORKER_H
#include <QThread>
#include <QObject>
#include "printdevice.h"

class PrintWorker : public QThread
{
    Q_OBJECT
public:
    //explicit PrintWorker(QObject *parent = nullptr);
    explicit PrintWorker(QString name, bool *stop, PrintDevice *print_device, QObject *parent = nullptr);
    ~PrintWorker() override;
signals:


    // QThread interface
protected:
    void run() override;

private:
    QString m_name;
    bool *m_stop;
    PrintDevice *m_print_device;
};

#endif // PRINTWORKER_H
