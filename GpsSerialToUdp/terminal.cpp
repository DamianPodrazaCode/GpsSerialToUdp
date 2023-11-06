#include "terminal.h"
#include "ui_terminal.h"

Terminal::Terminal(QWidget *parent) : QDialog(parent), ui(new Ui::Terminal) {
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint
                   | Qt::WindowCloseButtonHint);
    udpSocket = new QUdpSocket(this);
}

Terminal::~Terminal() {
    delete ui;
}

void Terminal::start() {

    ui->pte_read->setMaximumBlockCount(ui->le_lineCount->text().toInt());

    COMPORT = new QSerialPort();
    COMPORT->setPortName(PortName);
    COMPORT->setBaudRate(BaudRate.toInt());

    if (Parity == (QString) "NoParity")
        COMPORT->setParity(QSerialPort::NoParity);
    else if (Parity == (QString) "EvenParity")
        COMPORT->setParity(QSerialPort::EvenParity);
    else if (Parity == (QString) "OddParity")
        COMPORT->setParity(QSerialPort::OddParity);
    else if (Parity == (QString) "SpaceParity")
        COMPORT->setParity(QSerialPort::SpaceParity);
    else if (Parity == (QString) "EvenParity")
        COMPORT->setParity(QSerialPort::MarkParity);

    if (DataBits == (QString) "Data5")
        COMPORT->setDataBits(QSerialPort::Data5);
    else if (DataBits == (QString) "Data6")
        COMPORT->setDataBits(QSerialPort::Data6);
    else if (DataBits == (QString) "Data7")
        COMPORT->setDataBits(QSerialPort::Data7);
    else if (DataBits == (QString) "Data8")
        COMPORT->setDataBits(QSerialPort::Data8);

    if (StopBits == (QString) "OneStop")
        COMPORT->setStopBits(QSerialPort::OneStop);
    else if (StopBits == (QString) "OneAndHalfStop")
        COMPORT->setStopBits(QSerialPort::OneAndHalfStop);
    else if (StopBits == (QString) "TwoStop")
        COMPORT->setStopBits(QSerialPort::TwoStop);

    if (FlowControl == (QString) "NoFlowControl")
        COMPORT->setFlowControl(QSerialPort::NoFlowControl);
    else if (FlowControl == (QString) "HardwareControl")
        COMPORT->setFlowControl(QSerialPort::HardwareControl);
    else if (FlowControl == (QString) "SoftwareControl")
        COMPORT->setFlowControl(QSerialPort::SoftwareControl);

    COMPORT->clearError();

    COMPORT->open(QSerialPort::ReadWrite);

    //    $PMTK220,1000*1F<CR><LF>
    //    $PMTK220, 200*2C<CR><LF>
    //    $PMTK220,100*2F<CR><LF>

    QString strSend = "$PMTK220,100*2F\r\n";
    qInfo() << strSend.toLatin1();
    COMPORT->write(strSend.toLatin1());
    COMPORT->write(strSend.toLatin1());
    COMPORT->write(strSend.toLatin1());
    COMPORT->write(strSend.toLatin1());

    if (!COMPORT->isOpen()) {
        COMPORT->close();
        delete COMPORT;
        close();
    }

    connect(COMPORT, SIGNAL(readyRead()), this, SLOT(read_data()));
}

void Terminal::read_data() {
    if (COMPORT->isOpen()) {

        while (COMPORT->bytesAvailable()) {
            dataFromSerial.append(COMPORT->readAll());
        }
        while (dataFromSerial.contains(char(10))) {
            QString lineShow = dataFromSerial.left(dataFromSerial.indexOf(char(10)));
            lineShow.replace(char(13), "");
            if (!ui->pb_startStop->isChecked()) {
                ui->pte_read->appendPlainText(lineShow);
                if (lineShow.contains(ui->le_extract->text())) {
                    if (ui->le_change->text() != "") {
                        lineShow.replace(ui->le_extract->text(), ui->le_change->text());
                        ui->le_udpSend->setText(lineShow);
                    } else {
                        ui->le_udpSend->setText(lineShow);
                    }
                }
            }
            dataFromSerial.remove(0, dataFromSerial.indexOf(char(10)) + 1);
        }
        if (ui->cb_rewind->isChecked()) {
            ui->pte_read->ensureCursorVisible();
        }
    }
}

void Terminal::on_pb_clear_read_clicked() {
    ui->pte_read->clear();
}

void Terminal::on_pb_startStop_toggled(bool checked) {
    if (checked) {
        ui->pb_startStop->setText("Start");
    } else {
        ui->pb_startStop->setText("Stop");
    }
}

void Terminal::on_Terminal_rejected() {
    COMPORT->close();
    delete COMPORT;
}

void Terminal::on_cb_autoDelete_toggled(bool checked) {
    if (checked) {
        ui->pte_read->setMaximumBlockCount(ui->le_lineCount->text().toInt());
    } else {
        ui->pte_read->setMaximumBlockCount(0);
    }
}

void Terminal::on_cb_warp_toggled(bool checked) {
    if (checked) {
        ui->pte_read->setLineWrapMode(QPlainTextEdit::WidgetWidth);
    } else {
        ui->pte_read->setLineWrapMode(QPlainTextEdit::NoWrap);
    }
}

void Terminal::on_le_lineCount_returnPressed() {
    ui->pte_read->setMaximumBlockCount(ui->le_lineCount->text().toInt());
}

void Terminal::on_le_udpSend_textChanged(const QString &arg1) {
    QByteArray data = arg1.toLatin1();
    QHostAddress ipAdress("255.255.255.255");
    uint16_t port = ui->le_port->text().toUInt();
    if (ui->pb_send->isChecked())
        udpSocket->writeDatagram(data, ipAdress, port);
}

void Terminal::on_pb_send_toggled(bool checked) {
    if (checked) {
        ui->pb_send->setText("Stop send");
    } else {
        ui->pb_send->setText("Start send");
    }
}
