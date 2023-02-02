#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <QPushButton>
#include "udpclient.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    UdpClient *m_udpClient;
    QGridLayout *m_mainLay;
    QGroupBox *m_deviceGroup;
    QGroupBox *m_controlsGroup;
    QGroupBox *m_serverGroup;

    // Device area

    // Controls area
    QGridLayout *m_controlsGridLay;
    QPushButton *m_btn0;
    QPushButton *m_btn1;
    QPushButton *m_btn2;
    // Server area
};
#endif // MAINWINDOW_H
