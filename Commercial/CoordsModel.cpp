#include "CoordsModel.h"
#include <QDebug>

CoordsModel::CoordsModel()
{
}

CoordsModel::~CoordsModel()
{
}

int CoordsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
//    return static_cast<int>(m_coordinates.size());
}

int CoordsModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 2;
}

QVariant CoordsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() > rowCount(index)) {
        return {};
    }

//    const std::pair<int, int>& coords = m_coordinates.at(index.row());

//    switch (role) {
//        case CoordRoles::XCoord: {
//            return QVariant::fromValue(coords.first);
//        }
//        case CoordRoles::YCoord: {
//            return QVariant::fromValue(coords.second);
//        }
//        default: {
//            return {};
//        }
//    }

//    return m_coordinates[index.row()][Column(index.column())];
}

bool CoordsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

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
            return ("X");
        case YCoord:
            return ("Y");
        }

        return QVariant{};
}

Qt::ItemFlags CoordsModel::flags(const QModelIndex &index) const
{

}

//QHash<int, QByteArray> CoordsModel::roleNames() const
//{
//    QHash<int, QByteArray> roles;
//    roles[CoordRoles::XCoord] = "X";
//    roles[CoordRoles::YCoord] = "Y";

//    return roles;
//}
