#include "client.h"

Client::Client(QObject *parent)
    : QObject{parent}
{
    m_url = QUrl("ws://192.168.1.155:20562/remote");
    connect(&m_webSocket, &QWebSocket::connected, this, &Client::onConnected);
    connect(&m_webSocket, &QWebSocket::disconnected, this, &Client::onDisconnected);
    m_webSocket.open(m_url);
    qDebug() << m_url.path() << '\n';
}

void Client::onConnected()
{
    connect(&m_webSocket, &QWebSocket::textMessageReceived, this, &Client::onMsgReceived);
    qDebug() << "Connected\n";
    m_webSocket.sendTextMessage(QStringLiteral("{\"action\":\"authenticate\",\"protocol\":\"702\",\"password\":\"control\"}"));
    m_webSocket.sendTextMessage(QStringLiteral("{\"action\": \"presentationTriggerNext\" }"));
}

void Client::onMsgReceived(QString l_msg)
{
    qDebug() << l_msg << '\n';
}

void Client::onDisconnected()
{
    qDebug() << "Disconnected\n";
}
