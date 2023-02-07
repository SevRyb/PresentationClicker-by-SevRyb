#include "mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow main_window;

    main_window.setWindowTitle("Clicker Configurator");
    main_window.resize(700, 700);
    main_window.setWindowState(Qt::WindowMinimized);

    main_window.show();
    return app.exec();
}
