/*
#include <qapplication.h>
#include <qmainwindow.h>

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    QMainWindow* window = new QMainWindow();
    app.setMainWidget(window);
    window->show();
    return app.exec();
}
*/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
