#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QPushButton>
#include <QWidget>

class AppWindow : public QWidget
{
    Q_OBJECT

private:
    QPushButton *m_pStopBtn;

public:
    AppWindow(QWidget *parent = nullptr);
    ~AppWindow();
};
#endif // APPWINDOW_H
