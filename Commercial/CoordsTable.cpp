#include "CoordsTable.h"

CoordsTable::CoordsTable(QWidget *parent)
    : QTableView(parent)
{
    setContextMenuPolicy(Qt::CustomContextMenu);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setEditTriggers(QAbstractItemView::DoubleClicked);
    setStyleSheet("background: #7B7B7C");
}

QModelIndexList CoordsTable::selectedIndexesWrapper() const
{
    return selectedIndexes();
}

CoordsTable::~CoordsTable()
{

}
