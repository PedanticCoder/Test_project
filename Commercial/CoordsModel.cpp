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
    return static_cast<int>(m_coordinates.size());
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

    const std::pair<int, int> coords = m_coordinates.at(index.row());

    switch (role) {
        case CoordRoles::XCoord: {
            return QVariant::fromValue(coords.first);
        }
        case CoordRoles::YCoord: {
            return QVariant::fromValue(coords.second);
        }
        default: {
            return {};
        }
    }
}
