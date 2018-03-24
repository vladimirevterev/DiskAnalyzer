#include "analyzer.h"
#include "datatypes.h"

#include <QDebug>
#include <QDir>
#include <QDirIterator>


Analyzer::Analyzer(QObject *parent): QThread(parent) {}

void Analyzer::runAnalysis() {
    QDir currentFolder(folderPath);
    if (folderPath.isEmpty() || !currentFolder.exists()) {
        qDebug() << "Specified folder does not exists.";
        return;
    }

    AnalysisResult result;
    QDirIterator filesIterator(folderPath, QDir::NoDotAndDotDot | QDir::Files, QDirIterator::Subdirectories);
    QDirIterator foldersIterator(folderPath, QDir::NoDotAndDotDot | QDir::Dirs); // without subdirectories
    while (filesIterator.hasNext()) {
        if (isInterruptionRequested()) {
            qDebug() << "Interruption request occured. Stop analysis.";
            return;
        }
        filesIterator.next();
        result.groups[filesIterator.fileInfo().suffix()].addFile(filesIterator.fileInfo().size());
    }
    while (foldersIterator.hasNext()) {
        if (isInterruptionRequested()) {
            qDebug() << "Interruption request occured. Stop analysis.";
            return;
        }
        foldersIterator.next();
        result.foldersCount++;
    }
    result.dump();
}

void Analyzer::run() {
    qDebug() << "Thread " << this->currentThreadId() << "started.";
    runAnalysis();
    qDebug() << "Thread " << this->currentThreadId() << "finished.";
}
