#ifndef DATATYPES_H
#define DATATYPES_H

#include <QMap>
#include <QVector>
#include <QVariant>

typedef QVector<QVector<QVariant> > GroupsVector;

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
    GroupsVector getGroupsAsVector() const;
};

Q_DECLARE_METATYPE(AnalysisResult);

#endif // DATATYPES_H
