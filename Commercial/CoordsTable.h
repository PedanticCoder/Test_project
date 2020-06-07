#ifndef COORDSTABLE_H
#define COORDSTABLE_H

#include <QTableView>
#include <QPoint>

class CoordsTable : public QTableView
{
    Q_OBJECT

public:
    CoordsTable();
    virtual ~CoordsTable();
};

#endif // COORDSTABLE_H
