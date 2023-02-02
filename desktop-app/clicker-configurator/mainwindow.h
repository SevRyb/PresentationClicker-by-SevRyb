#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "udpclient.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    UdpClient *m_udpClient;
};
#endif // MAINWINDOW_H
