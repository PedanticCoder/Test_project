#ifndef COORDSMODEL_H
#define COORDSMODEL_H

#include <QAbstractTableModel>

class CoordsModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    CoordsModel();
    virtual ~CoordsModel();

    int rowCount(const QModelIndex &parent = {}) const override;
    int columnCount(const QModelIndex &parent = {}) const override;
    QVariant data(const QModelIndex &index = {}, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

private:
    std::vector<std::pair<int, int>> m_coordinates{{0, 0}};

    enum CoordRoles {
        XCoord = Qt::UserRole + 1,
        YCoord
    };
};

#endif // COORDSMODEL_H
