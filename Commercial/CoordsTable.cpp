#include "CoordsTable.h"
#include <QDebug>

CoordsTable::CoordsTable()
{
    setContextMenuPolicy(Qt::CustomContextMenu);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setEditTriggers(QAbstractItemView::DoubleClicked);

//    connect(this, &QTableView::customContextMenuRequested, this, slotCustomMenuRequested(QPoint));

}

CoordsTable::~CoordsTable()
{

}

void CoordsTable::slotCustomMenuRequested(QPoint pos)
{

}
