#include "incrementworker.h"

IncrementWorker::IncrementWorker(bool *stop, PrintDevice *print_device, QObject *parent):
    QThread(parent), m_stop(stop), m_print_device(print_device)
{

}

void IncrementWorker::run()
{
    while(!(* m_stop)) {
        msleep(1500);
        m_print_device->increment();
    }
}
