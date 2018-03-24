#ifndef DATATYPES_H
#define DATATYPES_H

#include <QMap>

struct GroupInfo {
    int filesCount;
    int totalSize;
    int averageSize;

    GroupInfo();
    void add(int fileSize);
};

struct AnalysisResult {
    int foldersCount;
    QMap<QString, GroupInfo> groups;

    AnalysisResult();
    void dump();
};

#endif // DATATYPES_H
