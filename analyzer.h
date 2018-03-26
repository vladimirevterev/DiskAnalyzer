#ifndef ANALYZER_H
#define ANALYZER_H

#include <QObject>
#include <QThread>

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
    void analysisProgressText(const QString& text);

public slots:


};

#endif // ANAYZER_H
