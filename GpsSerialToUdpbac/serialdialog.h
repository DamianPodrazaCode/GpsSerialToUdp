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
    bool appOn = false;

private slots:
    void on_pb_rescan_clicked();
    void on_pb_cancel_clicked();
    void on_pb_connect_clicked();
    void on_SerialDialog_rejected();

private:
    Ui::SerialDialog *ui;
    void fill_cb_serialInfo();
    QStringList portInfoList;
};

#endif // SERIALDIALOG_H
