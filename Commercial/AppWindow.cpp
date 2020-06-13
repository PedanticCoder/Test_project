#include "AppWindow.h"
#include "CoordsModel.h"
#include "CoordsTable.h"
#include <QGridLayout>
#include <QMenu>
#include <QAction>
#include <QDebug>

QT_CHARTS_USE_NAMESPACE

AppWindow::AppWindow(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(800, 600);
    setStyleSheet("background: #121212");

    setupUI();
}

void AppWindow::setupUI()
{
    m_pGridLayout  = new QGridLayout(this);
    m_pCoordsTable = new CoordsTable(this);

    m_pCoordsTable->setModel(&m_CoordsModel);
//    QItemSelectionModel selection(&m_CoordsModel);
//    m_pCoordsTable->setSelectionModel(&selection);
    setupChart();

    m_pCoordsTable->setStyleSheet("background: #7B7B7C");
    m_pCoordsTable->setFixedSize(width() / 2, height() / 1.25);
//    m_pGridLayout->setColumnMinimumWidth(0, m_pCoordsTable->width());
    qDebug() << "ширина tableview = " << m_pCoordsTable->width();
//    m_pGridLayout->setColumnStretch(0, 1);
//    m_pGridLayout->setRowStretch(0, 1);
    m_pGridLayout->addWidget(m_pChartView, 0, 0);
    m_pGridLayout->addWidget(m_pCoordsTable, 0, 1);
//    m_pGridLayout->setGeometry(QRect(400, 300, 350, 250));
    qDebug() << "строк в сетке = " << m_pGridLayout->rowCount();
    qDebug() << "стобцов в сетке = " << m_pGridLayout->columnCount();

    m_pMenu = new QMenu(this);
    m_pMenu->setStyleSheet("background: #7B7B7C");
    m_pAddRow = new QAction(tr("Добавить"), this);
    m_pDeleteRow = new QAction(tr("Удалить"), this);
    m_pMenu->addAction(m_pAddRow);
    m_pMenu->addAction(m_pDeleteRow);

    connect(m_pCoordsTable, &CoordsTable::customContextMenuRequested,
            this,           &AppWindow::slotCustomMenuRequested);
}

void AppWindow::setupChart()
{
    QLineSeries *series = new QLineSeries();
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Simple line chart example");
    m_pChartView = new QChartView(chart);
    m_pChartView->chart()->setTheme(QChart::ChartThemeBlueCerulean);
}

void AppWindow::slotCustomMenuRequested(QPoint pos)
{
    // TODO сделть вызов контекстного меню только под кликом над выбранными строчками?
    if(!m_pCoordsTable->selectedIndexesWrapper().isEmpty())
        m_pMenu->popup(m_pCoordsTable->viewport()->mapToGlobal(pos));
    /* Call to context menu */
    connect(m_pDeleteRow, &QAction::triggered, [=]{
        QVector<QModelIndex> selectedIndexes = m_pCoordsTable->selectedIndexesWrapper().toVector();
        if(!m_pCoordsTable->selectedIndexesWrapper().isEmpty()) {
//            qDebug() << "Первая выделенная строчка: "
//                     << selectedIndexes.at(1).row();
        }
    });
}

AppWindow::~AppWindow()
{
}

