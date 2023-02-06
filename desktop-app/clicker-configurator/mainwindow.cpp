#include "mainwindow.h"
#include "windows.h"

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


    HWND hwnd;
    uint keyCode;
    /*
    QString str;
    str = "Python";
    wchar_t* name = new wchar_t[str.length() + 1];
    str.toWCharArray(name);
    */

    //wchar_t win_name[] = L"Notepad";
    wchar_t win_name[] = L"Calculator";

    hwnd = FindWindow(win_name, 0);

    if (hwnd == NULL)
    {
        qDebug() << "HWND == NULL\n";
    }
    else
    {
        //SetForegroundWindow(hwnd);
    }
    qDebug() << "HWND == " << hwnd << '\n';


    keyCode = VK_F5; // key
    //keyCode = VK_BACK;
    //uint keyCode = PP_DATA.key;

    //PostMessage(hwnd, WM_KEYDOWN, keyCode, 0); // key down
    //PostMessage(hwnd, WM_KEYUP, keyCode, 0); // key up

    //PostMessage(hwnd, WM_CHAR, 0x32, 0);
    //PostMessage(hwnd, WM_CHAR, keyCode, 0); // key up

    //SendMessage(hwnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0);

    //SendMessage(hwnd, WM_CHAR, SC_MAXIMIZE, 0);

    wchar_t c = L'9';
    SendMessage(hwnd, WM_CHAR, c, 0);

    //SendMessage(hwnd, WM_KEYDOWN, keyCode, 0); // key down
    //SendMessage(hwnd, WM_KEYUP, keyCode, 0); // key up

//    for (int i = 0; i < 3; i++)
//    {
//        PostMessage(hwnd, WM_KEYDOWN, keyCode, 0); // key down
//        PostMessage(hwnd, WM_KEYUP, keyCode, 0); // key up
//    }






//    std::wstring text = L"Burak Hamdi TUFAN\nthecodeprogram.com";
//    //Then we are going to create a vector which will contain key inputs
//    std::vector<INPUT> vec;

//    for(auto ch : text)
//    {
//        INPUT key_input = { 0 };
//        //Make configuations of the key input
//        //We specify the every character of the text as unicode keyboard_input
//        key_input.type = INPUT_KEYBOARD;
//        key_input.ki.dwFlags = KEYEVENTF_UNICODE;
//        key_input.ki.wScan = ch;
//        vec.push_back(key_input);
//    }
//    INPUT key_input = { 0 };
//    key_input.type = INPUT_KEYBOARD;
//    key_input.ki.wVk = VK_BACK;
//    vec.push_back(key_input);
//    //Lastly we send the characters by same order
//    SendInput(vec.size(), vec.data(), sizeof(INPUT));

}

MainWindow::~MainWindow()
{
}
