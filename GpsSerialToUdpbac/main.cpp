#include "mainwindow.h"
#include "serialdialog.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    SerialDialog *serial = new SerialDialog();
    serial->setWindowTitle("New Serial Connection.");
    serial->show();
    if (serial->appOn) {
        w.show();
    } else {
        w.close();
    }
    return a.exec();
}
