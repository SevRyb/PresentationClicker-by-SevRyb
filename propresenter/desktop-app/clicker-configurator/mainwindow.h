#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include "udpclient.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onRestartServer();
private:
    //UdpClient *m_udpClient;
    QGridLayout *m_mainLay;
    QGroupBox *m_deviceGroup;
    QGroupBox *m_controlsGroup;
    QGroupBox *m_serverGroup;

    // Device area
    QGridLayout *m_deviceGridLay;
    QLineEdit *m_wifiSsidOnDevice;
    QLineEdit *m_wifiPassOnDevice;
    QLineEdit *m_serverIpOnDevice;
    QLineEdit *m_serverPortOnDevice;
    QPushButton *m_saveToDeviceBtn;

    // Controls area
    QGridLayout *m_controlsGridLay;
    QPushButton *m_btn0;
    QPushButton *m_btn1;
    QPushButton *m_btn2;

};
#endif // MAINWINDOW_H
