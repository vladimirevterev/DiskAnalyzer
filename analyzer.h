#ifndef ANALYZER_H
#define ANALYZER_H

#include <QObject>
#include <QThread>

#include "datatypes.h"

class Analyzer : public QThread {
    Q_OBJECT

protected:
    void run();

private:
    void setProgressText(const QString& text);

public:
    QString folderPath;
    Analyzer(QObject *parent = 0);
    void runAnalysis();

signals:
    void analysisProgressTextSent(const QString& text);
    void analysisDone(const AnalysisResult& result);

public slots:


};

#endif // ANAYZER_H
