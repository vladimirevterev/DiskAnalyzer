#include "analyzer.h"

#include <QDebug>
#include <QDir>
#include <QDirIterator>
#include <QString>


Analyzer::Analyzer(QObject *parent): QThread(parent) {}

void Analyzer::runAnalysis() {
    QDir currentFolder(folderPath);
    if (folderPath.isEmpty() || !currentFolder.exists()) {
        setProgressText("Specified folder does not exists.");
        return;
    }

    setProgressText("Analysis of the folder \"" + folderPath + "\" started...");
    AnalysisResult result;
    QDirIterator filesIterator(folderPath, QDir::NoDotAndDotDot | QDir::Files, QDirIterator::Subdirectories);
    QDirIterator foldersIterator(folderPath, QDir::NoDotAndDotDot | QDir::Dirs); // without subdirectories
    while (filesIterator.hasNext()) {
        if (isInterruptionRequested())
        {
            setProgressText("Interruption request occured. Stop analysis.");
            return;
        }
        filesIterator.next();
        result.groups[filesIterator.fileInfo().suffix()].addFile(filesIterator.fileInfo().size());
    }
    while (foldersIterator.hasNext()) {
        if (isInterruptionRequested())
        {
            setProgressText("Interruption request occured. Stop analysis.");
            return;
        }
        foldersIterator.next();
        result.foldersCount++;
    }
    setProgressText(result.dump());
    // Send analysis data to main form
    emit analysisDone(result);
}

void Analyzer::run() {
    setProgressText("Thread " + QString::number((long long)this->thread(), 16) + " started.");
    runAnalysis();
    setProgressText("Thread " + QString::number((long long)this->thread(), 16) + " finished.");
}

void Analyzer::setProgressText(const QString& text) {
    emit analysisProgressTextSent(text);
}
