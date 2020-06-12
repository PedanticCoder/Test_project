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
    bool setData( const QModelIndex& index, const QVariant& value, int role ) override;
    QVariant headerData( int section, Qt::Orientation orientation, int role ) const override;
    Qt::ItemFlags flags( const QModelIndex& index ) const override;

private slots:
    void deleteRow();

private:
    enum Column {
        XCoord = 0,
        YCoord
    };

    using CoordData = QHash<Column, QVariant>;
    using Coordinates = QList<CoordData>;
    Coordinates m_coordinates;
};

#endif // COORDSMODEL_H
