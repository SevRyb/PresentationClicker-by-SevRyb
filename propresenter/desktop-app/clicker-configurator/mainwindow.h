#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QPlainTextEdit>
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

    // Device area
    QGridLayout *m_deviceGridLay;
    QLineEdit *m_wifiSsidOnDevice;
    QLineEdit *m_wifiPassOnDevice;

    QLineEdit *m_propresenterIpOnDevice;
    QLineEdit *m_propresenterPortOnDevice;
    QLineEdit *m_propresenterPassOnDevice;

    // Controls area
    QGridLayout *m_controlsGridLay;
    QPushButton *m_btn0;
    QPushButton *m_btn1;
    QPlainTextEdit *m_btn0CommandTextEdit;
    QPlainTextEdit *m_btn1CommandTextEdit;

    QPushButton *m_saveToDeviceBtn;
    QPushButton *m_reloadFromDeviceBtn;
};
#endif // MAINWINDOW_H
