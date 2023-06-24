#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QWebSocket>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

signals:

private slots:
    void onConnected();
    void onMsgReceived(QString l_msg);
    void onDisconnected();

private:
    QWebSocket m_webSocket;
    QUrl m_url;
};

#endif // CLIENT_H
