#ifndef TERMINAL_H
#define TERMINAL_H

#include <QDialog>
#include <QNetworkDatagram>
#include <QSerialPort>
#include <QThread>
#include <QUdpSocket>

namespace Ui {
class Terminal;
}

class Terminal : public QDialog {
    Q_OBJECT

public:
    explicit Terminal(QWidget *parent = nullptr);
    ~Terminal();

    QString PortName;
    QString BaudRate;
    QString DataBits;
    QString Direction;
    QString FlowControl;
    QString Parity;
    QString StopBits;
    void start();

private slots:
    void read_data();
    void on_pb_clear_read_clicked();
    void on_pb_startStop_toggled(bool checked);
    void on_Terminal_rejected();
    void on_cb_autoDelete_toggled(bool checked);
    void on_cb_warp_toggled(bool checked);
    void on_le_lineCount_returnPressed();
    void on_le_udpSend_textChanged(const QString &arg1);
    void on_pb_send_toggled(bool checked);

private:
    Ui::Terminal *ui;
    QSerialPort *COMPORT;
    QByteArray dataFromSerial;
    QUdpSocket *udpSocket;
    QString decimalToLonLat(double value);
};

#endif // TERMINAL_H
