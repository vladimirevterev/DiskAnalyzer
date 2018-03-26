#include <datatypes.h>

#include <QDebug>
#include <QTextStream>

GroupInfo::GroupInfo() {
    filesCount = 0;
    totalSize = 0;
    averageSize = 0;
}

void GroupInfo::addFile(int fileSize)
{
    filesCount++;
    totalSize += fileSize;
    averageSize = totalSize / filesCount;
}

AnalysisResult::AnalysisResult() {
    foldersCount = 0;
}

QString AnalysisResult::dump()
{
    QString result;
    QTextStream resultStream(&result);
    resultStream << endl << "Analysis result:" << endl;
    resultStream << "Folders count: " << foldersCount << endl;
    resultStream <<"File group format: " << endl
                 << "<type> (<total_group_size>, <average_file_size_in_group>):" << endl;
    foreach (QString type, groups.keys())
    {
        resultStream << "\"" << type << "\": "
                     << groups.value(type).filesCount << "("
                     << groups.value(type).totalSize << ", "
                     << groups.value(type).averageSize << ")"
                     << endl;
    }
    return result;
}
