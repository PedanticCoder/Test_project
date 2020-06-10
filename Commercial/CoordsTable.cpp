#include "CoordsTable.h"
#include <QDebug>
#include <QMenu>
#include <QPoint>

CoordsTable::CoordsTable()
{
    setContextMenuPolicy(Qt::CustomContextMenu);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    setSelectionMode(QAbstractItemView::MultiSelection);
    setEditTriggers(QAbstractItemView::AllEditTriggers);

    connect(this, &CoordsTable::customContextMenuRequested,
            this, &CoordsTable::slotCustomMenuRequested);

}

CoordsTable::~CoordsTable()
{

}

void CoordsTable::slotCustomMenuRequested(QPoint pos)
{
    QMenu * menu = new QMenu(this);
    QAction * editDevice = new QAction(tr("Редактировать"), this);
    QAction * deleteDevice = new QAction(tr("Удалить"), this);
    menu->addAction(editDevice);
    menu->addAction(deleteDevice);
    /* Call to context menu */
    menu->popup(this->viewport()->mapToGlobal(pos));
}
