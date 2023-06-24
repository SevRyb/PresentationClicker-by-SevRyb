
#include "mainwindow.h"

#include <oclero/qlementine.hpp>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    auto* style = new oclero::qlementine::QlementineStyle(&app);
    style->setThemeJsonPath(":/dark.json");
    QApplication::setStyle(style);

    MainWindow window;
    window.show();
    return app.exec();
}
