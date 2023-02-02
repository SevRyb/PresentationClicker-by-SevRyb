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
    m_serverGroup->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);

    m_mainLay->addWidget(m_deviceGroup, 0, 0);
    m_mainLay->addWidget(m_controlsGroup, 0, 1);
    m_mainLay->addWidget(m_serverGroup, 1, 0, 1, 2);

    setLayout(m_mainLay);

    // Device area
    m_deviceGridLay = new QGridLayout(m_deviceGroup);
    m_serverIpOnDevice = new QLineEdit("192.168.0.104", m_deviceGroup);
    m_serverPortOnDevice = new QLineEdit("1234", m_deviceGroup);
    m_saveToDeviceBtn = new QPushButton("Save", m_deviceGroup);
    m_saveToDeviceBtn->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);

    m_deviceGridLay->addWidget(new QLabel("Status: online (battery 87%)", m_deviceGroup), 0, 0, 0, 4);
    m_deviceGridLay->addWidget(new QLabel("WiFi", m_deviceGroup), 1, 0);


    m_deviceGridLay->addWidget(new QLabel("Server", m_deviceGroup), 4, 0);
    m_deviceGridLay->addWidget(new QLabel("Local address", m_deviceGroup), 5, 0);
    m_deviceGridLay->addWidget(new QLabel("Listen port", m_deviceGroup), 6, 0);
    m_deviceGridLay->addWidget(m_serverIpOnDevice, 5, 1);
    m_deviceGridLay->addWidget(m_serverPortOnDevice, 6, 1);
    m_deviceGridLay->addWidget(m_saveToDeviceBtn, 7, 2, 2, 2);
    m_deviceGroup->setLayout(m_deviceGridLay);

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

    // Server area
    m_serverGridLay = new QGridLayout(m_serverGroup);
    m_serverIp = new QLineEdit("192.168.0.104", m_serverGroup);
    m_serverPort = new QLineEdit("1234", m_serverGroup);
    m_restartServerBtn = new QPushButton("Restart", m_serverGroup);
    m_restartServerBtn->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);
    m_serverGridLay->addWidget(new QLabel("Local address", m_serverGroup), 0, 0);
    m_serverGridLay->addWidget(new QLabel("Listen port", m_serverGroup), 1, 0);
    m_serverGridLay->addWidget(m_serverIp, 0, 1);
    m_serverGridLay->addWidget(m_serverPort, 1, 1);
    m_serverGridLay->addWidget(m_restartServerBtn, 0, 2, 2, 2);
    m_serverGroup->setLayout(m_serverGridLay);
}

MainWindow::~MainWindow()
{
}

