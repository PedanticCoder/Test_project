#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QWidget>

class QGridLayout;
class CoordsModel;
class CoordsTable;

class AppWindow : public QWidget
{
    Q_OBJECT

public:
    AppWindow(QWidget *parent = nullptr);
    ~AppWindow();

private:
    QGridLayout *m_pGridLayout;
    CoordsModel *m_pCoordsModel;
    CoordsTable *m_pCoordsTable;
};
#endif // APPWINDOW_H
