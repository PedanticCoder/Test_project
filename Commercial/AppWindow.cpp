#include "AppWindow.h"
#include "CoordsModel.h"
#include "CoordsTable.h"
#include <QGridLayout>

AppWindow::AppWindow(QWidget *parent)
    : QWidget(parent)
{
    m_pGridLayout  = new QGridLayout(this);
    m_pCoordsTable = new CoordsTable;

    setFixedSize(800, 600);
    setStyleSheet("background: #121212");

    m_pCoordsTable->setModel(&m_CoordsModel);

//    QItemSelectionModel selection(&m_CoordsModel);

//    m_pCoordsTable->setSelectionModel(&selection);
    m_pCoordsTable->setStyleSheet("background: #7B7B7C");
    m_pGridLayout->setGeometry(QRect(400, 300, 350, 250));
    m_pGridLayout->addWidget(m_pCoordsTable, 0, 1);
    m_pGridLayout->setColumnStretch(0, 1);
    m_pGridLayout->setRowStretch(0, 1);
}

AppWindow::~AppWindow()
{
    delete m_pCoordsTable;
}

