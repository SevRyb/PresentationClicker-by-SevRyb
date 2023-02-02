#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , m_udpClient(new UdpClient(this))
{
    m_mainLay = new QGridLayout(this);

    m_deviceGroup = new QGroupBox("Device", this);
    m_controlsGroup = new QGroupBox("Controls", this);
    m_serverGroup = new QGroupBox("Server", this);

    m_controlsGroup->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);

    m_mainLay->addWidget(m_deviceGroup, 0, 0);
    m_mainLay->addWidget(m_controlsGroup, 0, 1);
    m_mainLay->addWidget(m_serverGroup, 1, 0, 1, 2);

    setLayout(m_mainLay);


    // Controls area
    m_controlsGridLay = new QGridLayout(m_controlsGroup);
    m_btn0 = new QPushButton("Button 0", m_controlsGroup);
    m_btn1 = new QPushButton("Button 1", m_controlsGroup);
    m_btn2 = new QPushButton("Button 2", m_controlsGroup);
    m_btn0->setFixedSize(80, 50);
    m_btn1->setFixedSize(80, 50);
    m_btn2->setFixedSize(80, 50);
    m_controlsGridLay->addWidget(m_btn0, 0, 0);
    m_controlsGridLay->addWidget(m_btn1, 1, 0);
    m_controlsGridLay->addWidget(m_btn2, 2, 0);
    m_controlsGroup->setLayout(m_controlsGridLay);
}

MainWindow::~MainWindow()
{
}

