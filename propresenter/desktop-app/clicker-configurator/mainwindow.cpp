#include "mainwindow.h"
#include "windows.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    //, m_udpClient(new UdpClient(this))
{
    m_mainLay = new QGridLayout(this);

    m_deviceGroup = new QGroupBox("Device", this);
    m_controlsGroup = new QGroupBox("Controls", this);

    m_controlsGroup->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);

    m_mainLay->addWidget(m_deviceGroup, 0, 0, 1, 3);
    m_mainLay->addWidget(m_controlsGroup, 1, 0, 1, 3);

    m_saveToDeviceBtn = new QPushButton("Save", m_deviceGroup);
    //m_saveToDeviceBtn->setFixedSize(80, 50);
    m_saveToDeviceBtn->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    m_mainLay->addWidget(m_saveToDeviceBtn, 2, 2);

    setLayout(m_mainLay);

    // Device area
    m_deviceGridLay = new QGridLayout(m_deviceGroup);
    m_wifiSsidOnDevice = new QLineEdit("My WiFi", m_deviceGroup);
    m_wifiPassOnDevice = new QLineEdit("qwerty123", m_deviceGroup);
    m_propresenterIpOnDevice = new QLineEdit("192.168.0.104", m_deviceGroup);
    m_propresenterPortOnDevice = new QLineEdit("1234", m_deviceGroup);
    m_propresenterPassOnDevice = new QLineEdit("control", m_deviceGroup);


    QLabel *status_label = new QLabel("<strong>Status: <i><font color=green>online (battery 87%)</i></strong>", m_deviceGroup);
    //status_label->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);

    m_deviceGridLay->addWidget(status_label, 0, 0, 1, 3, Qt::AlignTop);
    m_deviceGridLay->addWidget(new QLabel("<strong>WiFi</strong>", m_deviceGroup), 1, 0);
    m_deviceGridLay->addWidget(new QLabel("SSID", m_deviceGroup), 2, 0);
    m_deviceGridLay->addWidget(new QLabel("Password", m_deviceGroup), 3, 0);
    m_deviceGridLay->addWidget(m_wifiSsidOnDevice, 2, 1);
    m_deviceGridLay->addWidget(m_wifiPassOnDevice, 3, 1);


    m_deviceGridLay->addWidget(new QLabel("<strong>ProPresenter</strong>", m_deviceGroup), 4, 0);
    m_deviceGridLay->addWidget(new QLabel("IP address", m_deviceGroup), 5, 0);
    m_deviceGridLay->addWidget(new QLabel("Port", m_deviceGroup), 6, 0);
    m_deviceGridLay->addWidget(new QLabel("Controller password", m_deviceGroup), 7, 0);
    m_deviceGridLay->addWidget(m_propresenterIpOnDevice, 5, 1);
    m_deviceGridLay->addWidget(m_propresenterPortOnDevice, 6, 1);
    m_deviceGridLay->addWidget(m_propresenterPassOnDevice, 7, 1);
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


    // Controls area
    m_controlsGridLay = new QGridLayout(m_controlsGroup);
    m_btn0 = new QPushButton("Button 0", m_controlsGroup);
    m_btn1 = new QPushButton("Button 1", m_controlsGroup);
    m_btn0->setFixedSize(80, 50);
    m_btn1->setFixedSize(80, 50);
    m_controlsGridLay->addWidget(m_btn0, 0, 0);
    m_controlsGridLay->addWidget(m_btn1, 0, 1);
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

