#ifndef DIALOG_H
#define DIALOG_H

#include "terminal.h"
#include <QDialog>
#include <QMessageBox>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog {
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    static QString getSettings(QString group, QString key);
    static void setSettings(QString group, QString key, QString value);

private slots:
    void on_pb_rescan_clicked();
    void on_pb_cancel_clicked();
    void on_pb_connect_clicked();
    void on_Dialog_rejected();

private:
    Ui::Dialog *ui;
    void fill_cb_serialInfo();
    QStringList portInfoList;
};
#endif // DIALOG_H
