
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <oclero/qlementine/widgets/FramelessWindow.hpp>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>

class MainWindow : public oclero::qlementine::FramelessWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QGridLayout *m_rootLay;
    QLineEdit *m_addressEdit;
    QPushButton *m_connectBtn;
    QPushButton *m_sendBtn;
    QTextEdit *m_dataToSendText;
    QTextEdit *m_responseText;
};

#endif // MAINWINDOW_H
