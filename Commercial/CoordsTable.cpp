#include "CoordsTable.h"
#include <QDebug>
#include <QMenu>
#include <QPoint>
#include <vector>

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
    QMenu *menu = new QMenu(this);
    QAction *addRow = new QAction(tr("Добавить"), this);
    QAction *deleteRow = new QAction(tr("Удалить"), this);
    menu->addAction(addRow);
    menu->addAction(deleteRow);
    /* Call to context menu */
    menu->popup(this->viewport()->mapToGlobal(pos));

    connect(deleteRow, &QAction::triggered, [=]{
//        std::vector<QModelIndex> selectedIndexes = selectedIndexes().toVector();
        if(!selectedIndexes().isEmpty()) {
            qDebug() << "Первая выделенная строчка: "
                     << selectedIndexes().toVector().at(1).row();
        }
    });
}
