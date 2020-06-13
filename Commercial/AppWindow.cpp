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
    m_pCoordsTable->setFixedWidth(width() / 3.7);
    qDebug() << "ширина tableview = " << m_pCoordsTable->width();
    m_pGridLayout->addWidget(m_pChartView, 0, 0);
    m_pGridLayout->addWidget(m_pCoordsTable, 0, 1);
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
    // TODO проверить на пустой модели, не будет ли крашиться прога
    qDebug() << "столбцов в таблице: " << m_pCoordsTable->model()->rowCount();
    quint64 rowsInTable = m_pCoordsTable->model()->rowCount();
    for(quint64 i = 0; i < rowsInTable; ++i) {
        std::pair<QVariant, QVariant> coords = m_CoordsModel.getCoordinatesFromRow(i);
        series->append(coords.first.toInt(), coords.second.toInt());
    }
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
    /* Вызов контекстного меню */
//    connect(m_pDeleteRow, &QAction::triggered, [=]{
//        QVector<QModelIndex> selectedIndexes = m_pCoordsTable->selectedIndexesWrapper().toVector();
//        if(!m_pCoordsTable->selectedIndexesWrapper().isEmpty()) {
//            qDebug() << "Первая выделенная строчка: "
//                     << selectedIndexes.at(1).row();
//        }
//    });
    connect(m_pDeleteRow,   &QAction::triggered,
            &m_CoordsModel, &CoordsModel::deleteRow);
}

AppWindow::~AppWindow()
{
}

