#include "groupstablemodel.h"

#include <QBrush>
#include <QColor>

GroupsTableModel::GroupsTableModel(QObject *parent) : QAbstractTableModel(parent)
{

}

int GroupsTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return groupsVector.size();
}

int GroupsTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return GROUPS_VECTOR_LENGTH;
}

QVariant GroupsTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    if (index.row() >= groupsVector.size() || index.row() < 0)
    {
        return QVariant();
    }

    if (role == Qt::DisplayRole)
    {
        return (QVariant(groupsVector[index.row()][index.column()]));
    }

    if (role == Qt::BackgroundRole) {
        if (!(index.row() & 1)) {
            return QBrush(QBrush(QColor(230, 230, 230, 255)));
        }
        return QVariant(QBrush(QColor(Qt::white)));
    }

    return QVariant();
}

QVariant GroupsTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
    {
        return QVariant();
    }

    if (orientation == Qt::Horizontal)
    {
        switch (section) {
        case 0:
            return QVariant("Type");
        case 1:
            return QVariant("Count");
        case 2:
            return QVariant("Total Size (bytes)");
        case 3:
            return QVariant("Average File Size (bytes)");
        default:
            return QVariant();
        }
    }
    return QVariant();
}

void GroupsTableModel::update(const GroupsVector& newGroupsVector)
{
    beginResetModel();
    groupsVector = newGroupsVector;
    endResetModel();
}

