#ifndef SERIALDIALOG_H
#define SERIALDIALOG_H

#include <QDialog>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QSettings>
#include <QMessageBox>

namespace Ui {
class SerialDialog;
}

class SerialDialog : public QDialog {
    Q_OBJECT

public:
    explicit SerialDialog(QWidget *parent = nullptr);
    ~SerialDialog();

private slots:
    void on_pb_rescan_clicked();

    void on_cb_baudrate_currentIndexChanged(int index);
    void on_cb_databits_currentIndexChanged(int index);
    void on_cb_direction_currentIndexChanged(int index);
    void on_cb_flowcontrol_currentIndexChanged(int index);
    void on_cb_parity_currentIndexChanged(int index);
    void on_cb_stopbits_currentIndexChanged(int index);

    void on_rb_terminal_clicked();
    void on_rb_visualization_clicked();

    void on_pb_cancel_clicked();
    void on_pb_connect_clicked();

private:
    Ui::SerialDialog *ui;
    void fill_cb_serialInfo();
    QStringList portInfoList;
    bool ConnectionType = false; // false - terminal, true - visualisation
};

#endif // SERIALDIALOG_H
