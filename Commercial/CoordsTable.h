#ifndef COORDSTABLE_H
#define COORDSTABLE_H

#include <QTableView>

class CoordsTable : public QTableView
{
    Q_OBJECT

public:
    CoordsTable(QWidget *parent = nullptr);
    virtual ~CoordsTable();

public:
    QModelIndexList selectedIndexesWrapper() const;
};

#endif // COORDSTABLE_H
