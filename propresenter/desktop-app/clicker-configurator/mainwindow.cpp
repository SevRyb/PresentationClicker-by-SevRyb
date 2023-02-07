#include "mainwindow.h"
#include "windows.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    //, m_udpClient(new UdpClient(this))
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
    m_wifiSsidOnDevice = new QLineEdit("My WiFi", m_deviceGroup);
    m_wifiPassOnDevice = new QLineEdit("qwerty123", m_deviceGroup);
    m_serverIpOnDevice = new QLineEdit("192.168.0.104", m_deviceGroup);
    m_serverPortOnDevice = new QLineEdit("1234", m_deviceGroup);
    m_saveToDeviceBtn = new QPushButton("Save", m_deviceGroup);

    m_saveToDeviceBtn->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    QLabel *status_label = new QLabel("<strong>Status: <i><font color=green>online (battery 87%)</i></strong>", m_deviceGroup);
    status_label->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);

    m_deviceGridLay->addWidget(status_label, 0, 0, 1, 3, Qt::AlignTop | Qt::AlignHCenter);
    m_deviceGridLay->addWidget(new QLabel("WiFi", m_deviceGroup), 1, 0);
    m_deviceGridLay->addWidget(new QLabel("SSID", m_deviceGroup), 2, 0);
    m_deviceGridLay->addWidget(new QLabel("Password", m_deviceGroup), 3, 0);
    m_deviceGridLay->addWidget(m_wifiSsidOnDevice, 2, 1);
    m_deviceGridLay->addWidget(m_wifiPassOnDevice, 3, 1);


    m_deviceGridLay->addWidget(new QLabel("Server", m_deviceGroup), 4, 0);
    m_deviceGridLay->addWidget(new QLabel("Local address", m_deviceGroup), 5, 0);
    m_deviceGridLay->addWidget(new QLabel("Listen port", m_deviceGroup), 6, 0);
    m_deviceGridLay->addWidget(m_serverIpOnDevice, 5, 1);
    m_deviceGridLay->addWidget(m_serverPortOnDevice, 6, 1);
    m_deviceGridLay->addWidget(m_saveToDeviceBtn, 7, 2, 1, 1);
    m_deviceGroup->setLayout(m_deviceGridLay);

    for (int i = 0; i < m_deviceGridLay->count(); ++i)
    {
      QWidget *widget = m_deviceGridLay->itemAt(i)->widget();
      if (widget != NULL)
      {
        widget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
      }
      else
      {
        // You may want to recurse, or perform different actions on layouts.
        // See gridLayout->itemAt(i)->layout()
      }
    }

    m_saveToDeviceBtn->setFixedSize(80, 50);

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



    // Connects
    //connect(m_restartServerBtn, &QPushButton::released, this, &MainWindow::onRestartServer);



}

MainWindow::~MainWindow()
{
}

void MainWindow::onRestartServer()
{

}

