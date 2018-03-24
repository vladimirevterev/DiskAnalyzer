#include "analyzer.h"
#include "datatypes.h"

#include <QDebug>
#include <QDir>
#include <QDirIterator>


Analyzer::Analyzer(QObject *parent): QThread(parent) {}

void Analyzer::runAnalysis() {
    QDirIterator folderIterator(folderPath, QDir::NoDotAndDotDot | QDir::Files, QDirIterator::Subdirectories);
    AnalysisResult result;

    while(folderIterator.hasNext()) {
        folderIterator.next();
        result.groups[folderIterator.fileInfo().completeSuffix()].add(folderIterator.fileInfo().size());
    }
    result.dump();
}

void Analyzer::run() {
    qDebug() << "thread " << this->currentThreadId() << "started";
    runAnalysis();
    qDebug() << "thread " << this->currentThreadId() << "finished";
}
