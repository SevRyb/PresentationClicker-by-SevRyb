
#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : oclero::qlementine::FramelessWindow(parent)
    , m_isConnected{false}
{
    setWindowTitle("Websocket Client");
    resize(500, 300);
    m_rootLay = new QGridLayout;
    m_rootWidget = new QWidget(this);
    m_rootWidget->setLayout(m_rootLay);
    setContentWidget(m_rootWidget);

    m_urlEdit = new oclero::qlementine::LineEdit(this);
    m_connectBtn = new QPushButton("Connect", this);
    m_sendBtn = new QPushButton("Send", this);
    m_dataToSendTextEdit = new QTextEdit(this);
    m_responseTextEdit = new QTextEdit(this);

    m_rootLay->addWidget(m_urlEdit, 0, 0, 1, 2);
    m_rootLay->addWidget(m_connectBtn, 1, 0);
    m_rootLay->addWidget(m_sendBtn, 1, 1);
    m_rootLay->addWidget(m_dataToSendTextEdit, 2, 0, 1, 2);
    m_rootLay->addWidget(m_responseTextEdit, 3, 0, 1, 2);

    /**/
    m_urlEdit->setPlaceholderText("ws://");
    m_urlEdit->setClearButtonEnabled(true);
    m_sendBtn->setEnabled(false);

    /* Connections */
    connect(&m_webSocket, &QWebSocket::connected, this, &MainWindow::onConnected);
    connect(&m_webSocket, &QWebSocket::disconnected, this, &MainWindow::onDisconnected);
    connect(&m_webSocket, QOverload<QAbstractSocket::SocketError>::of(&QWebSocket::error), this, &MainWindow::onError);
    connect(m_connectBtn, &QPushButton::clicked, this, [this]()
            {
                QString url = m_urlEdit->text();
                if (url.mid(0, 2) == QString("ws"))
                    m_url = url;
                else
                    m_url = "ws://" + url;
                m_webSocket.open(m_url);
            });
    connect(m_sendBtn, &QPushButton::clicked, this, [this]()
            {
                QString text = m_dataToSendTextEdit->toPlainText();
                if (text.isEmpty())
                    return;
                m_webSocket.sendTextMessage(text);
            });
}

MainWindow::~MainWindow()
{
}

void MainWindow::onConnected()
{
    m_isConnected = true;
    connect(&m_webSocket, &QWebSocket::textMessageReceived, this, &MainWindow::onMessageReceived);
    m_urlEdit->setStatus(oclero::qlementine::Status::Success);
    m_sendBtn->setEnabled(true);
    setWindowTitle("Websocket Client [" + m_url.toDisplayString() + "]");
}

void MainWindow::onMessageReceived(QString text)
{
    m_responseTextEdit->clear();
    m_responseTextEdit->setText(text);
}

void MainWindow::onDisconnected()
{
    m_isConnected = false;
    m_urlEdit->setStatus(oclero::qlementine::Status::Default);
    m_sendBtn->setEnabled(false);
    setWindowTitle("Websocket Client");
}

void MainWindow::onError(QAbstractSocket::SocketError error)
{
    m_urlEdit->setStatus(oclero::qlementine::Status::Error);
    m_sendBtn->setEnabled(false);
    setWindowTitle("Websocket Client");
}


