#include "analizer.h"
#include <QDebug>


Analizer::Analizer(QObject *parent): QThread(parent) {}

void Analizer::runAnalize()
{
    qDebug() << "analize: " << directory;
    sleep(5);
    return;
}

void Analizer::run()
{
    qDebug() << "thread started";
    runAnalize();
    qDebug() << "thread finished";
}
