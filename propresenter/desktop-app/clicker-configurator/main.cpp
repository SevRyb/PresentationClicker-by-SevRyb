#include "mainwindow.h"

#include <QApplication>
#include <QFile>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFile style_file("../stylesheet.qss");
    style_file.open(QFile::ReadOnly);
    QString style_sheet = QLatin1String(style_file.readAll());
    app.setStyleSheet(style_sheet);

    MainWindow main_window;

    main_window.setWindowTitle("Clicker Configurator");
    main_window.resize(700, 700);
    main_window.setWindowState(Qt::WindowMinimized);

    main_window.show();
    return app.exec();
}
