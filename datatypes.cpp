#include <datatypes.h>

#include <QDebug>

GroupInfo::GroupInfo() {
    filesCount = 0;
    totalSize = 0;
    averageSize = 0;
}

void GroupInfo::add(int fileSize)
{
    filesCount++;
    totalSize += fileSize;
    averageSize = totalSize / filesCount;
}

AnalysisResult::AnalysisResult() {
    foldersCount = 0;
}

void AnalysisResult::dump()
{
    qDebug() << "Folders count: " << foldersCount;
    foreach (QString type, groups.keys()) {
        qDebug() << type << ": " << groups.value(type).filesCount << "("
                 << groups.value(type).totalSize << ", "
                 << groups.value(type).averageSize << ")";
    }
}
