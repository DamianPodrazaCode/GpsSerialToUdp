#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog) {
    ui->setupUi(this);

    fill_cb_serialInfo();
    ui->cb_baudrate->setCurrentText(getSettings("serial", "BaudRate"));
    ui->cb_databits->setCurrentText(getSettings("serial", "DataBits"));
    ui->cb_direction->setCurrentText(getSettings("serial", "Direction"));
    ui->cb_flowcontrol->setCurrentText(getSettings("serial", "FlowControl"));
    ui->cb_parity->setCurrentText(getSettings("serial", "Parity"));
    ui->cb_stopbits->setCurrentText(getSettings("serial", "StopBits"));
}

Dialog::~Dialog() {
    delete ui;
}

QString Dialog::getSettings(QString group, QString key) {
    QSettings settings("init.ini", QSettings::Format::IniFormat);
    return settings.value(group + "/" + key).toString();
}

void Dialog::setSettings(QString group, QString key, QString value) {
    QSettings settings("init.ini", QSettings::Format::IniFormat);
    settings.setValue(group + "/" + key, value);
}

void Dialog::on_pb_rescan_clicked() {
    fill_cb_serialInfo();
}

void Dialog::on_pb_cancel_clicked() {
    this->close();
}

void Dialog::on_pb_connect_clicked() {
    if (ui->cb_portNr->count() > 0) {
        Terminal *term = new Terminal();
        term->PortName = ui->cb_portNr->currentText();
        term->BaudRate = ui->cb_baudrate->currentText();
        term->DataBits = ui->cb_databits->currentText();
        term->Direction = ui->cb_direction->currentText();
        term->FlowControl = ui->cb_flowcontrol->currentText();
        term->Parity = ui->cb_parity->currentText();
        term->StopBits = ui->cb_stopbits->currentText();
        term->start();
        term->show();
        this->close();
    } else {
        QMessageBox::information(this, tr("WARNING!!!"), tr("No Serial Ports."));
        this->close();
    }
}

void Dialog::on_Dialog_rejected() {
    setSettings("serial", "BaudRate", ui->cb_baudrate->currentText());
    setSettings("serial", "DataBits", ui->cb_databits->currentText());
    setSettings("serial", "Direction", ui->cb_direction->currentText());
    setSettings("serial", "FlowControl", ui->cb_flowcontrol->currentText());
    setSettings("serial", "Parity", ui->cb_parity->currentText());
    setSettings("serial", "StopBits", ui->cb_stopbits->currentText());
}

void Dialog::fill_cb_serialInfo() {
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
