#include "CoordsTable.h"
#include <QDebug>

CoordsTable::CoordsTable()
{
    setContextMenuPolicy(Qt::CustomContextMenu);
//    setSelectionBehavior(QAbstractItemView::SelectRows);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setEditTriggers(QAbstractItemView::DoubleClicked);

}

CoordsTable::~CoordsTable()
{

}
