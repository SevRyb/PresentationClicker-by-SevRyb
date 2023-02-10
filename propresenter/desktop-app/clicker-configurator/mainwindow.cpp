#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    //, m_udpClient(new UdpClient(this))
{
    m_mainLay = new QGridLayout(this);
    m_mainLay->setContentsMargins(10, 20, 10, 20);
    m_mainLay->setSpacing(20);

    m_deviceGroup = new QGroupBox("Device", this);
    m_deviceGroup->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    m_controlsGroup = new QGroupBox("Controls", this);
    //m_controlsGroup->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);

    m_mainLay->addWidget(m_deviceGroup, 1, 0, 1, 3);
    m_mainLay->addWidget(m_controlsGroup, 2, 0, 1, 3);

    QLabel *status_label = new QLabel("<strong>Status: <i><font color=green>online (battery 87%)</i></strong>", m_deviceGroup);
    m_reloadFromDeviceBtn = new QPushButton("Reload", m_deviceGroup);
    //m_saveToDeviceBtn->setFixedSize(80, 50);
    m_reloadFromDeviceBtn->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    m_saveToDeviceBtn = new QPushButton("Save", m_deviceGroup);
    //m_saveToDeviceBtn->setFixedSize(80, 50);
    m_saveToDeviceBtn->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    m_mainLay->addWidget(status_label, 0, 0);
    m_mainLay->addWidget(m_reloadFromDeviceBtn, 0, 1);
    m_mainLay->addWidget(m_saveToDeviceBtn, 0, 2);

    setLayout(m_mainLay);

    // Device area
    m_deviceGridLay = new QGridLayout(m_deviceGroup);
    //m_deviceGridLay->setColumnStretch(2, 1);
    //m_deviceGridLay->setColumnStretch(1, 1);
    m_deviceGridLay->setContentsMargins(20, 20, 100, 20);
    m_deviceGridLay->setSpacing(10);

    m_wifiSsidOnDevice = new QLineEdit("My WiFi", m_deviceGroup);
    m_wifiPassOnDevice = new QLineEdit("qwerty123", m_deviceGroup);
    m_propresenterIpOnDevice = new QLineEdit("192.168.0.104", m_deviceGroup);
    m_propresenterPortOnDevice = new QLineEdit("1234", m_deviceGroup);
    m_propresenterPassOnDevice = new QLineEdit("control", m_deviceGroup);



    m_deviceGridLay->addWidget(new QLabel("<b>WiFi</b>", m_deviceGroup), 1, 0);
    m_deviceGridLay->addWidget(new QLabel("SSID", m_deviceGroup), 2, 0);
    m_deviceGridLay->addWidget(new QLabel("Password", m_deviceGroup), 3, 0);
    m_deviceGridLay->addWidget(m_wifiSsidOnDevice, 2, 1);
    m_deviceGridLay->addWidget(m_wifiPassOnDevice, 3, 1);


    m_deviceGridLay->addWidget(new QLabel("<strong>ProPresenter</strong>", m_deviceGroup), 4, 0);
    m_deviceGridLay->addWidget(new QLabel("IP address", m_deviceGroup), 5, 0);
    m_deviceGridLay->addWidget(new QLabel("Port", m_deviceGroup), 6, 0);
    m_deviceGridLay->addWidget(new QLabel("Password <i>(controller)</i>", m_deviceGroup), 7, 0);
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
    m_controlsGridLay->setColumnMinimumWidth(0, 200);
    m_controlsGridLay->setContentsMargins(20, 20, 100, 20);
    m_controlsGridLay->setSpacing(10);
    m_btn0 = new QPushButton("Button 0", m_controlsGroup);
    m_btn1 = new QPushButton("Button 1", m_controlsGroup);
    m_btn0->setFixedSize(80, 50);
    m_btn1->setFixedSize(80, 50);
    m_btn0CommandTextEdit = new QPlainTextEdit("{\"action\":\"presentationTriggerNext\"}", this);
    m_btn1CommandTextEdit = new QPlainTextEdit("{\"action\":\"presentationTriggerPrevious\"}", this);
    m_controlsGridLay->addWidget(new QLabel("Commands to send", this), 0, 1);
    m_controlsGridLay->addWidget(m_btn0, 1, 0);
    m_controlsGridLay->addWidget(m_btn1, 2, 0);
    m_controlsGridLay->addWidget(m_btn0CommandTextEdit, 1, 1);
    m_controlsGridLay->addWidget(m_btn1CommandTextEdit, 2, 1);
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

