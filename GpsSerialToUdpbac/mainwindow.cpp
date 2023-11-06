#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

QString MainWindow::getSettings(QString group, QString key) {
    QSettings settings("init.ini", QSettings::Format::IniFormat);
    return settings.value(group + "/" + key).toString();
}

void MainWindow::setSettings(QString group, QString key, QString value) {
    QSettings settings("init.ini", QSettings::Format::IniFormat);
    settings.setValue(group + "/" + key, value);
}
