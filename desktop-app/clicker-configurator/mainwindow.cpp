#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , m_udpClient(new UdpClient(this))
{
}

MainWindow::~MainWindow()
{
}

