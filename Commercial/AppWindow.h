#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QWidget>
#include <QPushButton>

class AppWindow : public QWidget
{
    Q_OBJECT

public:
    AppWindow(QWidget *parent = nullptr);
    ~AppWindow();

private:
    QPushButton *m_pStartBtn;
    QPushButton *m_pStopBtn;

};
#endif // APPWINDOW_H
