#include <QApplication>
#include <QDebug>
#include <QMutex>
#include <QMessageBox>
#include "printworker.h"
#include "printdevice.h"
#include "incrementworker.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    bool stopFlag = false;
    PrintDevice printDevice;

    PrintWorker black("Black", &stopFlag, &printDevice),
            white("White", &stopFlag, &printDevice);

    IncrementWorker incrementWorker(&stopFlag, &printDevice);

    black.start();
    white.start();
    incrementWorker.start();

    QMessageBox::information(nullptr, "QMutex", "Thread Working. Close me to stop.");

    stopFlag = true;

    black.wait();
    white.wait();
    incrementWorker.wait();

    return 0;
}
