#include "CoordsModel.h"
#include "CoordsTable.h"
#include <QDebug>
#include <QAction>

CoordsModel::CoordsModel()
{
    CoordData coords;

    for(quint8 i = 0; i < 10; ++i) {
        coords[XCoord] = i;
        coords[YCoord] = i * 10;
        int row = m_coordinates.count();
        beginInsertRows(QModelIndex(), row, row);
        m_coordinates.append(coords);
        endInsertRows();
    }
}

CoordsModel::~CoordsModel()
{
}

int CoordsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_coordinates.count();
}

int CoordsModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 2;
}

QVariant CoordsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || m_coordinates.count() <= index.row() ||
       (role!=Qt::DisplayRole && role!=Qt::EditRole)) {
        return {};
    }
    return m_coordinates[index.row()][Column(index.column())];
}

bool CoordsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    qDebug() << "-----setData begin!-----";
    if( !index.isValid() || role != Qt::EditRole || m_coordinates.count() <= index.row() ) {
        qDebug() << "-----setData end failed!-----";
        return false;
    }

    m_coordinates[index.row()][ Column(index.column())] = value;
    emit dataChanged(index, index);

    qDebug() << "-----setData end successfully!-----";
    return true;
}

QVariant CoordsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole) {
        return QVariant{};
    }

    if(orientation == Qt::Vertical) {
        return section;
    }

    switch(section) {
        case XCoord:
            return "X";
        case YCoord:
            return "Y";
    }

    return QVariant{};
}

Qt::ItemFlags CoordsModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractTableModel::flags(index);
    if(index.isValid()) {
        flags |= Qt::ItemIsEditable;
    }

    return flags;
}

void CoordsModel::deleteRow()
{
    beginRemoveRows(QModelIndex(), 3, 3);
    m_coordinates.removeAt(3);
    endRemoveRows();
}
