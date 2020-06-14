#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QWidget>
#include <CoordsModel.h>
#include <QtCharts/QtCharts>

QT_CHARTS_USE_NAMESPACE

class QGridLayout;
class CoordsTable;
class QMenu;
class QAction;

class AppWindow : public QWidget
{
    Q_OBJECT

public:
    AppWindow(QWidget *parent = nullptr);
    virtual ~AppWindow();

private:
    void setupUI();
    void setupChart();

private slots:
    void slotCustomMenuRequested(QPoint pos);
    void selectedRow();

signals:
    void rowSelectedToBeRemoved(quint64 row);
    void rowSelectedToBeInserted(quint64 row);

private:
    QGridLayout *m_pGridLayout;
    CoordsTable *m_pCoordsTable;
    CoordsModel  m_CoordsModel;
    QMenu       *m_pMenu;
    QAction     *m_pAddRow;
    QAction     *m_pDeleteRow;
    QChartView  *m_pChartView;
};
#endif // APPWINDOW_H
