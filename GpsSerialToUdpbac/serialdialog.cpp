#include "serialdialog.h"
#include "mainwindow.h"
#include "ui_serialdialog.h"

SerialDialog::SerialDialog(QWidget *parent) : QDialog(parent), ui(new Ui::SerialDialog) {
    ui->setupUi(this);
    fill_cb_serialInfo();
    ui->cb_baudrate->setCurrentText(MainWindow::getSettings("serial", "BaudRate"));
    ui->cb_databits->setCurrentText(MainWindow::getSettings("serial", "DataBits"));
    ui->cb_direction->setCurrentText(MainWindow::getSettings("serial", "Direction"));
    ui->cb_flowcontrol->setCurrentText(MainWindow::getSettings("serial", "FlowControl"));
    ui->cb_parity->setCurrentText(MainWindow::getSettings("serial", "Parity"));
    ui->cb_stopbits->setCurrentText(MainWindow::getSettings("serial", "StopBits"));
}

SerialDialog::~SerialDialog() {
    delete ui;
}

void SerialDialog::fill_cb_serialInfo() {
    ui->cb_portNr->clear();
    for (const QSerialPortInfo &portInfo : QSerialPortInfo::availablePorts()) {
        portInfoList.append(portInfo.portName() + ";" + portInfo.description() + ";" + portInfo.manufacturer() + ";"
                            + portInfo.serialNumber() + ";" + QString::number(portInfo.productIdentifier(), 16) + ";"
                            + QString::number(portInfo.vendorIdentifier(), 16) + ";" + portInfo.systemLocation());

        // sprawdzenie czyu port otwarty, jeżeli nie to dodanie do listy możliwych portów
        QSerialPort *COMPORT = new QSerialPort();
        COMPORT->setPortName(portInfo.portName());
        COMPORT->clearError();
        COMPORT->open(QSerialPort::ReadWrite);
        if (COMPORT->isOpen()) {
            ui->cb_portNr->addItem(portInfo.portName());
        }
        COMPORT->close();
        delete COMPORT;
    }
    ui->cb_portNr->model()->sort(0);
}

void SerialDialog::on_pb_rescan_clicked() {
    fill_cb_serialInfo();
}

void SerialDialog::on_pb_cancel_clicked() {
    this->close();
}

void SerialDialog::on_pb_connect_clicked() {
    if (ui->cb_portNr->count() > 0) {
        appOn = true;
        this->close();
    } else {
        QMessageBox::information(this, tr("WARNING!!!"), tr("No Serial Ports."));
        appOn = false;
        this->close();
    }
}

void SerialDialog::on_SerialDialog_rejected() {
    MainWindow::setSettings("serial", "BaudRate", ui->cb_baudrate->currentText());
    MainWindow::setSettings("serial", "DataBits", ui->cb_databits->currentText());
    MainWindow::setSettings("serial", "Direction", ui->cb_direction->currentText());
    MainWindow::setSettings("serial", "FlowControl", ui->cb_flowcontrol->currentText());
    MainWindow::setSettings("serial", "Parity", ui->cb_parity->currentText());
    MainWindow::setSettings("serial", "StopBits", ui->cb_stopbits->currentText());
}
