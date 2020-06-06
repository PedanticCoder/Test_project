#include "AppWindow.h"

AppWindow::AppWindow(QWidget *parent)
    : QWidget(parent)
{
    m_pStartBtn = new QPushButton(tr("START"), this);
    m_pStartBtn->setGeometry(10, 10, 150, 25);
}

AppWindow::~AppWindow()
{
}

