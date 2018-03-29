#ifndef DATATYPES_H
#define DATATYPES_H

#include <QMap>
#include <QVector>
#include <QVariant>

typedef QVector<QVector<QVariant> > GroupsVector;
#define GROUPS_VECTOR_LENGTH 4

struct GroupInfo {
    int filesCount;
    int totalSize;
    int averageSize;

    GroupInfo();
    void addFile(int fileSize);
};

struct AnalysisResult {
    int foldersCount;
    int totalFilesCount;
    QMap<QString, GroupInfo> groups;

    AnalysisResult();
    QString dump();
    GroupsVector getGroupsAsVector() const;
};

Q_DECLARE_METATYPE(AnalysisResult);

#endif // DATATYPES_H
