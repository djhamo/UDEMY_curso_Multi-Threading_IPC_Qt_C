#include <QCoreApplication>
#include <QDebug>
#include <QStringList>
#include <QDir>
#include <QTime>
#include <QFuture>
#include <QtConcurrent>
#include <QThread>

QStringList findFiles(const QString &startDir)
{
    QStringList names;
    QDir dir(startDir);

    //qDebug() << "List File method running in thread : " << QThread::currentThread();
    const auto files = dir.entryList(QDir::Files);
    for (const QString &file : files)
        names += startDir + '/' + file;

    //Chamada recursiva
    const auto subdirs =  dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
    for (const QString &subdir : subdirs)
        names += findFiles(startDir + '/' + subdir);
    return names;

}

void reduce(QStringList &result, const QStringList &w)
{
    qDebug() << "Juntando";
    for (const QString &file : w) {
        qDebug() << file;
        result += file;
    }
}

QStringList findFile3(const QString &startDir)
{
    QStringList names;
    QDir dir(startDir);
    QFuture<QStringList> future;

    qDebug() << startDir << " method running in thread : " << QThread::currentThread();
    const auto files = dir.entryList(QDir::Files);
    for (const QString &file : files) {
        qDebug() << file << "...";
        names += startDir + '/' + file;
    }

    //Chamada recursiva
    const auto subdirs =  dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
    future = QtConcurrent::mappedReduced(subdirs, findFile3, reduce);
    //future.waitForFinished();
    for (const QString &file : future.result()) {
        qDebug() << file << "...";
        names += file;
    }
    return names;

}

QStringList findFile2(const QString &startDir)
{
    QStringList names;
    QDir dir(startDir);
    QFuture<QStringList> *future = new QFuture<QStringList>();

    qDebug() << startDir << " method running in thread : " << QThread::currentThread();
    const auto files = dir.entryList(QDir::Files);
    for (const QString &file : files) {
        qDebug() << file << "...";
        names += startDir + '/' + file;
    }

    //Chamada recursiva
    const auto subdirs =  dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
    (* future) = QtConcurrent::mapped(subdirs, findFile2);
    future->waitForFinished();
    for (const QString &file : future->result()) {
        qDebug() << file << "...";
        names += file;
    }
    delete future;
    return names;

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTime time;
    time.start();

    QStringList total = findFiles("c:\\Dados");
    int timeEllapsed = time.elapsed();


    qDebug() << " Single \n files count : " << total.count() << " \n Time ellapsed : " << timeEllapsed;

    time.start();
    QStringList total2 = findFile2("c:\\Dados");

    timeEllapsed = time.elapsed();
    qDebug() << " Map Reduce \n files count : " << total2.count() << " \n Time ellapsed : " << timeEllapsed;

    return a.exec();
}
