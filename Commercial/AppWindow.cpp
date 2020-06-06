#include "AppWindow.h"

AppWindow::AppWindow(QWidget *parent)
    : QWidget(parent)
{
<<<<<<< HEAD
    m_pStopBtn = new QPushButton(tr("STOP"), this);
    m_pStopBtn->setGeometry(10, 10, 150, 25);
=======
    m_pStartBtn = new QPushButton(tr("START"), this);
    m_pStartBtn->setGeometry(10, 10, 150, 25);
>>>>>>> 84564f1919b3ecfe0bd3b4fcbaac88af357639c5
}

AppWindow::~AppWindow()
{
}

