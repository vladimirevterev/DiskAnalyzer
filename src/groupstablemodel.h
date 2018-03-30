#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include "datatypes.h"

class GroupsTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit GroupsTableModel(QObject *parent = 0);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    GroupsVector groupsVector;

signals:

public slots:
    void update(const GroupsVector& newGroupsVector);

};

#endif // TABLEMODEL_H
