
#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : oclero::qlementine::FramelessWindow(parent)
{
    m_rootLay = new QGridLayout;
    setLayout(m_rootLay);

    m_addressEdit = new QLineEdit(this);
    m_connectBtn = new QPushButton("Connect", this);
    m_sendBtn = new QPushButton("Send", this);
    m_dataToSendText = new QTextEdit(this);
    m_responseText = new QTextEdit(this);

    m_rootLay->addWidget(m_addressEdit, 0, 0);
    m_rootLay->addWidget(m_connectBtn, 1, 0);
    m_rootLay->addWidget(m_sendBtn, 1, 1);
    m_rootLay->addWidget(m_dataToSendText, 2, 0, 1, 2);
    m_rootLay->addWidget(m_responseText, 3, 0, 1, 2);
}

MainWindow::~MainWindow()
{
}


