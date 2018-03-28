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

AnalysisResult::AnalysisResult()
{
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
        resultStream << "\"" << (type.isEmpty() ? "<empty_type>" : type) << "\": "
                     << groups.value(type).filesCount << "("
                     << groups.value(type).totalSize << ", "
                     << groups.value(type).averageSize << ")"
                     << endl;
    }
    return result;
}

GroupsVector AnalysisResult::getGroupsAsVector() const
{
    GroupsVector result;
    result.resize(groups.size());
    int i = 0;
    foreach (QString type, groups.keys())
    {
        result[i].push_back(QVariant(type.isEmpty() ? "<empty_type>" : type));
        result[i].push_back(QVariant(groups.value(type).filesCount));
        result[i].push_back(QVariant(groups.value(type).totalSize));
        result[i].push_back(QVariant(groups.value(type).averageSize));
        ++i;
    }
    return result;
}
