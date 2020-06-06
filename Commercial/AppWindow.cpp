#include "AppWindow.h"

AppWindow::AppWindow(QWidget *parent)
    : QWidget(parent)
{
    m_pStopBtn = new QPushButton(tr("STOP"), this);
    m_pStopBtn->setGeometry(10, 10, 150, 25);
}

AppWindow::~AppWindow()
{
}

