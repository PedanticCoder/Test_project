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

public slots:
    void slotCustomMenuRequested(QPoint pos);
};

#endif // COORDSTABLE_H
