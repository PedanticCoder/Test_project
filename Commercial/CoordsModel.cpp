#include "CoordsModel.h"
#include "CoordsTable.h"
#include <QDebug>
#include <QAction>

CoordsModel::CoordsModel()
{
    CoordData coords;

    for(quint8 i = 0; i < 10; ++i) {
        coords[XCoord] = i;
        coords[YCoord] = rand() % 100;
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
    return ColumnCount;
}

QVariant CoordsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || m_coordinates.count() <= index.row() ||
       (role!=Qt::DisplayRole && role!=Qt::EditRole && role!=Qt::TextAlignmentRole)) {
        return {};
    }

    if(role==Qt::TextAlignmentRole)
        return Qt::AlignCenter;

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

std::pair<QVariant, QVariant> CoordsModel::getCoordinatesFromRow(quint64 row) const
{
    return std::make_pair(m_coordinates[row][XCoord],
                          m_coordinates[row][YCoord]);
}

void CoordsModel::deleteRow(quint64 row)
{
    beginResetModel(); // разобраться, как работает

    beginRemoveRows(QModelIndex(), row, row);
    m_coordinates.removeAt(row);
    endRemoveRows();

    endResetModel();
}

void CoordsModel::addRow(quint64 rowAfter)
{
    // TODO передавать данные выделенной строки в новую строку
    beginResetModel();

    int row = m_coordinates.count();
    qDebug() << "rows before insertion = " << row;
    beginInsertRows(QModelIndex(), rowAfter + 1, rowAfter + 1);
    CoordData coords;
    coords[XCoord] = 99;
    coords[YCoord] = 99;
    m_coordinates.insert(rowAfter + 1, coords);
    endInsertRows();

    endResetModel();

    row = m_coordinates.count();
//    qDebug() <<
}
