#ifndef DATATYPES_H
#define DATATYPES_H

#include <QMap>
#include <QVector>
#include <QVariant>

struct GroupInfo {
    int filesCount;
    int totalSize;
    int averageSize;

    GroupInfo();
    void addFile(int fileSize);
};

struct AnalysisResult {
    int foldersCount;
    QMap<QString, GroupInfo> groups;

    AnalysisResult();
    QString dump();
    QVector<QVector<QVariant> > getGroupsAsVector();
};

#endif // DATATYPES_H
