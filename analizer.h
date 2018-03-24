#ifndef ANALIZER_H
#define ANALIZER_H

#include <QObject>
#include <QThread>

class Analizer : public QThread {
    Q_OBJECT

public:
    QString folderPath;

    Analizer(QObject *parent = nullptr);
    void runAnalize();
signals:

public slots:

    // QThread interface
protected:
    void run();
};

#endif // ANALIZER_H
