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

    if (!COMPORT->isOpen()) {
        COMPORT->close();
        delete COMPORT;
        close();
    }

    COMPORT->flush();

    QString command = "";

    // full cold start baudrate 9600
    command = "$PMTK104*37\r\n";
    COMPORT->write(command.toLatin1());
    COMPORT->flush();
    ui->pte_read->appendPlainText("Starting GPS...");
    QApplication::processEvents();
    QThread::msleep(1000);

    // gps baudrate 115200
    command = "$PMTK251,115200*1f\r\n";
    COMPORT->write(command.toLatin1());
    COMPORT->flush();
    ui->pte_read->appendPlainText("GPS to 115200...");
    QApplication::processEvents();
    QThread::msleep(100);

    // comport bautrate 115200
    COMPORT->close();
    QThread::msleep(100);
    qInfo() << COMPORT->setBaudRate(QSerialPort::Baud115200);
    qInfo() << COMPORT->open(QSerialPort::ReadWrite);
    ui->pte_read->appendPlainText("COMPORT to 115200...");
    QApplication::processEvents();
    QThread::msleep(100);

    command = "$PMTK314,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29\r\n";
    COMPORT->write(command.toLatin1());
    COMPORT->flush();
    ui->pte_read->appendPlainText("$PMTK314 ...");
    QApplication::processEvents();
    QThread::msleep(1000);

    // zmiana częstotliwości
    // command = "$PMTK220,1000*1F\r\n"; // 1Hz
    command = "$PMTK220,500*2b\r\n"; // 1Hz
                                     // command = "$PMTK220,200*2C\r\n";  // 5Hz
                                     // command = "$PMTK220,100*2F\r\n";  // 10Hz
    COMPORT->write(command.toLatin1());
    COMPORT->flush();
    ui->pte_read->appendPlainText("change frequency...");
    QApplication::processEvents();
    QThread::msleep(1000);

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

    QString command = "";
    // full cold start baudrate 9600
    command = "$PMTK104*37\r\n";
    COMPORT->write(command.toLatin1());
    COMPORT->flush();
    QThread::msleep(1000);
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

QString Terminal::decimalToLonLat(double value) {
    double degValue = value / 100; // kropka o dwa miejsca w lewo
    int degrees = (int)degValue;   // obcięcie od prawej do kropki
    double gps = degrees + (((degValue - degrees) * 100) / 60);
    return QString::number(gps, 'f', 7);
}

void Terminal::on_le_udpSend_textChanged(const QString &arg1) {
    // coordTosend.Command = "Lat=" + coordSource.Latitude.ToString("0.000000") + " "
    // + "Lon=" + coordSource.Longitude.ToString("0.000000") + " Alt=0 StdX=0 StdY=0 StdZ";

    QString temp = arg1;
    temp.remove(0, temp.indexOf(',') + 1).remove(0, temp.indexOf(',') + 1);
    QString sMapLat = temp.left(temp.indexOf(','));
    temp.remove(0, temp.indexOf(',') + 1).remove(0, temp.indexOf(',') + 1);
    QString sMapLon = temp.left(temp.indexOf(','));
    // qInfo() << sMapLat << sMapLon;
    // qInfo() << decimalToLonLat(sMapLat.toDouble()) << decimalToLonLat(sMapLon.toDouble());
    temp = "Lat=" + decimalToLonLat(sMapLat.toDouble()) //
        + " Lon=" + decimalToLonLat(sMapLon.toDouble()) //
        + " Alt=0 StdX=0 StdY=0 StdZ";
    ui->le_send->setText(temp);

    QByteArray data = temp.toLatin1();
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
