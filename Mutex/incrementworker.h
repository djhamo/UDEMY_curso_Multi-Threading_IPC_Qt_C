#ifndef PRINTINCREMENT_H
#define PRINTINCREMENT_H

#include <QThread>
#include <QObject>
#include "printdevice.h"

class IncrementWorker : public QThread
{
    Q_OBJECT
public:
    explicit IncrementWorker(bool *stop, PrintDevice *print_device, QObject *parent = nullptr);


    // QThread interface
protected:
    void run() override;

private:
    bool *m_stop;
    PrintDevice *m_print_device;
};

#endif // PRINTINCREMENT_H
