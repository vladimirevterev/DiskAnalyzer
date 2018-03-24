#include "analizer.h"
#include "datatypes.h"

#include <QDebug>
#include <QDir>


Analizer::Analizer(QObject *parent): QThread(parent) {}

void Analizer::runAnalize()
{
    sleep(5);
    return;
}

void Analizer::run()
{
    qDebug() << "thread started";
    runAnalize();
    qDebug() << "thread finished";
}
