#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QWidget>
#include <CoordsModel.h>

class QGridLayout;
class CoordsTable;

class AppWindow : public QWidget
{
    Q_OBJECT

public:
    AppWindow(QWidget *parent = nullptr);
    ~AppWindow();

private:
    QGridLayout *m_pGridLayout;
    CoordsTable *m_pCoordsTable;
    CoordsModel  m_CoordsModel;
};
#endif // APPWINDOW_H
