#ifndef ANALYZER_H
#define ANALYZER_H

#include <QObject>
#include <QThread>

class Analyzer : public QThread {
    Q_OBJECT

public:
    QString folderPath;

    Analyzer(QObject *parent = nullptr);
    void runAnalysis();
signals:

public slots:

    // QThread interface
protected:
    void run();
};

#endif // ANAYZER_H
