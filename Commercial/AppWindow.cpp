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
    setupChart();

    m_pCoordsTable->setStyleSheet("background: #7B7B7C");
    m_pCoordsTable->setFixedWidth(width() / 3.7);
    m_pGridLayout->addWidget(m_pChartView, 0, 0);
    m_pGridLayout->addWidget(m_pCoordsTable, 0, 1);

    m_pMenu = new QMenu(this);
    m_pMenu->setStyleSheet("background: #7B7B7C");
    m_pAddRow = new QAction(tr("Добавить"), this);
    m_pDeleteRow = new QAction(tr("Удалить"), this);
    m_pMenu->addAction(m_pAddRow);
    m_pMenu->addAction(m_pDeleteRow);

    connect(m_pCoordsTable, &CoordsTable::customContextMenuRequested,
            this,           &AppWindow::slotCustomMenuRequested);

    connect(this,           &AppWindow::rowSelectedToBeRemoved,
            &m_CoordsModel, &CoordsModel::deleteRow);

    connect(this,           &AppWindow::rowSelectedToBeInserted,
            &m_CoordsModel, &CoordsModel::addRow);

    connect(this,           &AppWindow::rowSelectedToBeRemoved,
            this,           &AppWindow::deleteSeries);

    connect(this,           &AppWindow::rowSelectedToBeInserted,
            this,           &AppWindow::addSeries);

    connect(&m_CoordsModel, &CoordsModel::seriesCoordChanged,
            this,           &AppWindow::changeSeries);
}

void AppWindow::setupChart()
{
    m_pSeries = new QLineSeries();
    // TODO проверить на пустой модели, не будет ли крашиться прога
    qDebug() << "столбцов в таблице: " << m_pCoordsTable->model()->rowCount();
    quint64 rowsInTable = m_pCoordsTable->model()->rowCount();
    for(quint64 i = 0; i < rowsInTable; ++i) {
        std::pair<QVariant, QVariant> coords = m_CoordsModel.getCoordinatesFromRow(i);
        m_pSeries->append(coords.first.toInt(),
                          coords.second.toInt());
    }
    m_pChart = new QChart();
    m_pChart->legend()->hide();
    m_pChart->addSeries(m_pSeries);
    m_pChart->createDefaultAxes();
    m_pChart->setTitle("Simple line chart example");
    m_pChartView = new QChartView(m_pChart);
    m_pChartView->chart()->setTheme(QChart::ChartThemeBlueCerulean);
    m_pChartView->setRenderHint(QPainter::Antialiasing);
}

void AppWindow::slotCustomMenuRequested(QPoint pos)
{
    if(!m_pCoordsTable->selectedIndexesWrapper().isEmpty())
        m_pMenu->popup(m_pCoordsTable->viewport()->mapToGlobal(pos));
    connect(m_pDeleteRow, &QAction::triggered,
            this,         &AppWindow::selectedRow);
    connect(m_pAddRow,    &QAction::triggered,
            this,         &AppWindow::selectedRow);
}

void AppWindow::selectedRow()
{
    QVector<QModelIndex> selectedIndexes = m_pCoordsTable->selectedIndexesWrapper().toVector();
    if(!m_pCoordsTable->selectedIndexesWrapper().isEmpty()) {
        QAction *senderPtr = qobject_cast<QAction*>(sender());
        if(senderPtr->text() == "Удалить")
            emit rowSelectedToBeRemoved(selectedIndexes.at(1).row());
        if(senderPtr->text() == "Добавить")
            emit rowSelectedToBeInserted(selectedIndexes.at(1).row());
    }
}

void AppWindow::addSeries(quint64 index)
{
    QModelIndex model_index_x = m_CoordsModel.index(index, 0, QModelIndex());
    QModelIndex model_index_y = m_CoordsModel.index(index, 1, QModelIndex());
    const qreal x_coord_data = m_CoordsModel.data(model_index_x).toInt();
    const qreal y_coord_data = m_CoordsModel.data(model_index_y).toInt();
    m_pSeries->insert(index, {x_coord_data, y_coord_data});
}

void AppWindow::changeSeries(quint64 index)
{
    deleteSeries(index);
    addSeries(index);
}

AppWindow::~AppWindow()
{
}

