#ifndef DATATYPES_H
#define DATATYPES_H

#include <QMap>

struct GroupInfo {
    int filesCount;
    int totalSize;
    int averageSize;

    GroupInfo();
};

struct AnalizeResult {
    int foldersCount;
    QMap<QString, GroupInfo> fileGroups;

    AnalizeResult();
};

#endif // DATATYPES_H
