#ifndef TERMINAL_H
#define TERMINAL_H

#include <QDialog>
#include <QSerialPort>

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

private:
    Ui::Terminal *ui;
    QSerialPort *COMPORT;
    QByteArray dataFromSerial;
};

#endif // TERMINAL_H
