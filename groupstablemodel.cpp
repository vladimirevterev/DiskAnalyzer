#include "groupstablemodel.h"

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
    // TODO: make more flexible
    return 4;
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
            return QVariant("Total size");
        case 3:
            return QVariant("Average Size");
        default:
            return QVariant();
        }
    }
    return QVariant();
}

