#include "udpclient.h"

UdpClient::UdpClient(QObject *parent)
    : QObject{parent}
    , m_udpSocket(new QUdpSocket(this))
{

    // The most common way to use QUdpSocket class is
    // to bind to an address and port using bind()
    // bool QAbstractSocket::bind(const QHostAddress & address,
    //     quint16 port = 0, BindMode mode = DefaultForPlatform)
    const QHostAddress &localhost = QHostAddress("0.0.0.0");
    qDebug() << localhost.toString();
    m_udpSocket->bind(localhost, 1234);

    connect(m_udpSocket, &QUdpSocket::readyRead, this, &UdpClient::readyRead);

}

void UdpClient::readyRead()
{
    QByteArray buffer;
    buffer.resize(m_udpSocket->pendingDatagramSize());

    QHostAddress sender;
    quint16 sender_port;

    // qint64 QUdpSocket::readDatagram(char * data, qint64 maxSize,
    //                 QHostAddress * address = 0, quint16 * port = 0)
    // Receives a datagram no larger than maxSize bytes and stores it in data.
    // The sender's host address and port is stored in *address and *port
    // (unless the pointers are 0).

    m_udpSocket->readDatagram(buffer.data(), buffer.size(), &sender, &sender_port);

    qDebug() << "Message from: " << sender.toString();
    qDebug() << "Message port: " << sender_port;
    qDebug() << "Message: " << buffer;
}
