#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    m_btn = new QPushButton("Connect", this);
}

MainWindow::~MainWindow()
{
}

