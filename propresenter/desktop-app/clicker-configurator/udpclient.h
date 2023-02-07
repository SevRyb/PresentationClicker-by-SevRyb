#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QObject>
#include <QUdpSocket>

class UdpClient : public QObject
{
    Q_OBJECT
public:
    explicit UdpClient(QObject *parent = nullptr);

signals:

public slots:
    void readyRead();

private:
    QUdpSocket *m_udpSocket;
};

#endif // UDPCLIENT_H
