#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QPushButton>
#include <QWidget>
#include <QPushButton>

class AppWindow : public QWidget
{
    Q_OBJECT

private:
    QPushButton *m_pStopBtn;

public:
    AppWindow(QWidget *parent = nullptr);
    ~AppWindow();

private:
    QPushButton *m_pStartBtn;

};
#endif // APPWINDOW_H
