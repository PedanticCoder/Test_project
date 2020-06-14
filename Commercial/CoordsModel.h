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

public:
    std::pair<QVariant, QVariant> getCoordinatesFromRow(quint64 row) const;

public slots:
    void deleteRow(quint64 row);
    void addRow(quint64 rowAfter);

private:
    enum Column {
        XCoord = 0,
        YCoord,
        ColumnCount
    };

    using CoordData = QHash<Column, QVariant>;
    using Coordinates = QList<CoordData>;
    Coordinates m_coordinates;
};

#endif // COORDSMODEL_H
