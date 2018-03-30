#ifndef DATATYPES_H
#define DATATYPES_H

#include <QMap>
#include <QVector>
#include <QVariant>

typedef QVector<QVector<QVariant> > GroupsVector;
#define GROUPS_VECTOR_LENGTH 4

struct GroupInfo {
    qint64 filesCount;
    qint64 totalSize;
    qint64 averageSize;

    GroupInfo();
    void addFile(qint64 fileSize);
};

struct AnalysisResult {
    qint64 subfoldersCount;
    qint64 size;
    qint64 totalFilesCount;
    QMap<QString, GroupInfo> groups;

    AnalysisResult();
    QString dump();
    GroupsVector getGroupsAsVector() const;
};

Q_DECLARE_METATYPE(AnalysisResult);

#endif // DATATYPES_H
