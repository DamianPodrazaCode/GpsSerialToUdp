/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *cb_portNr;
    QPushButton *pb_rescan;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QComboBox *cb_baudrate;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QComboBox *cb_databits;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QComboBox *cb_direction;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QComboBox *cb_flowcontrol;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QComboBox *cb_parity;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QComboBox *cb_stopbits;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_cancel;
    QPushButton *pb_connect;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->setWindowModality(Qt::ApplicationModal);
        Dialog->resize(235, 371);
        gridLayout_3 = new QGridLayout(Dialog);
        gridLayout_3->setObjectName("gridLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(Dialog);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        cb_portNr = new QComboBox(Dialog);
        cb_portNr->addItem(QString());
        cb_portNr->setObjectName("cb_portNr");

        verticalLayout->addWidget(cb_portNr);

        pb_rescan = new QPushButton(Dialog);
        pb_rescan->setObjectName("pb_rescan");

        verticalLayout->addWidget(pb_rescan);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(Dialog);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        cb_baudrate = new QComboBox(groupBox_2);
        cb_baudrate->addItem(QString());
        cb_baudrate->addItem(QString());
        cb_baudrate->addItem(QString());
        cb_baudrate->addItem(QString());
        cb_baudrate->addItem(QString());
        cb_baudrate->addItem(QString());
        cb_baudrate->addItem(QString());
        cb_baudrate->addItem(QString());
        cb_baudrate->addItem(QString());
        cb_baudrate->addItem(QString());
        cb_baudrate->addItem(QString());
        cb_baudrate->addItem(QString());
        cb_baudrate->addItem(QString());
        cb_baudrate->addItem(QString());
        cb_baudrate->addItem(QString());
        cb_baudrate->addItem(QString());
        cb_baudrate->addItem(QString());
        cb_baudrate->addItem(QString());
        cb_baudrate->addItem(QString());
        cb_baudrate->setObjectName("cb_baudrate");
        cb_baudrate->setInputMethodHints(Qt::ImhDigitsOnly);
        cb_baudrate->setEditable(true);

        horizontalLayout_3->addWidget(cb_baudrate);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");

        horizontalLayout_4->addWidget(label_3);

        cb_databits = new QComboBox(groupBox_2);
        cb_databits->addItem(QString());
        cb_databits->addItem(QString());
        cb_databits->addItem(QString());
        cb_databits->addItem(QString());
        cb_databits->setObjectName("cb_databits");
        cb_databits->setInputMethodHints(Qt::ImhDigitsOnly);
        cb_databits->setEditable(false);

        horizontalLayout_4->addWidget(cb_databits);


        gridLayout_2->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");

        horizontalLayout_5->addWidget(label_4);

        cb_direction = new QComboBox(groupBox_2);
        cb_direction->addItem(QString());
        cb_direction->addItem(QString());
        cb_direction->addItem(QString());
        cb_direction->setObjectName("cb_direction");
        cb_direction->setInputMethodHints(Qt::ImhDigitsOnly);
        cb_direction->setEditable(false);

        horizontalLayout_5->addWidget(cb_direction);


        gridLayout_2->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");

        horizontalLayout_6->addWidget(label_5);

        cb_flowcontrol = new QComboBox(groupBox_2);
        cb_flowcontrol->addItem(QString());
        cb_flowcontrol->addItem(QString());
        cb_flowcontrol->addItem(QString());
        cb_flowcontrol->setObjectName("cb_flowcontrol");
        cb_flowcontrol->setInputMethodHints(Qt::ImhDigitsOnly);
        cb_flowcontrol->setEditable(false);

        horizontalLayout_6->addWidget(cb_flowcontrol);


        gridLayout_2->addLayout(horizontalLayout_6, 3, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");

        horizontalLayout_7->addWidget(label_6);

        cb_parity = new QComboBox(groupBox_2);
        cb_parity->addItem(QString());
        cb_parity->addItem(QString());
        cb_parity->addItem(QString());
        cb_parity->addItem(QString());
        cb_parity->addItem(QString());
        cb_parity->setObjectName("cb_parity");
        cb_parity->setInputMethodHints(Qt::ImhDigitsOnly);
        cb_parity->setEditable(false);

        horizontalLayout_7->addWidget(cb_parity);


        gridLayout_2->addLayout(horizontalLayout_7, 4, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");

        horizontalLayout_8->addWidget(label_7);

        cb_stopbits = new QComboBox(groupBox_2);
        cb_stopbits->addItem(QString());
        cb_stopbits->addItem(QString());
        cb_stopbits->addItem(QString());
        cb_stopbits->setObjectName("cb_stopbits");
        cb_stopbits->setInputMethodHints(Qt::ImhDigitsOnly);
        cb_stopbits->setEditable(false);

        horizontalLayout_8->addWidget(cb_stopbits);


        gridLayout_2->addLayout(horizontalLayout_8, 5, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pb_cancel = new QPushButton(Dialog);
        pb_cancel->setObjectName("pb_cancel");

        horizontalLayout_2->addWidget(pb_cancel);

        pb_connect = new QPushButton(Dialog);
        pb_connect->setObjectName("pb_connect");

        horizontalLayout_2->addWidget(pb_connect);


        gridLayout_3->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Serial Connection.", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Serial Port:", nullptr));
        cb_portNr->setItemText(0, QCoreApplication::translate("Dialog", "COM", nullptr));

        pb_rescan->setText(QCoreApplication::translate("Dialog", "ReScan", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Dialog", "Options", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "BaudRate", nullptr));
        cb_baudrate->setItemText(0, QCoreApplication::translate("Dialog", "600", nullptr));
        cb_baudrate->setItemText(1, QCoreApplication::translate("Dialog", "1200", nullptr));
        cb_baudrate->setItemText(2, QCoreApplication::translate("Dialog", "2400", nullptr));
        cb_baudrate->setItemText(3, QCoreApplication::translate("Dialog", "4800", nullptr));
        cb_baudrate->setItemText(4, QCoreApplication::translate("Dialog", "9600", nullptr));
        cb_baudrate->setItemText(5, QCoreApplication::translate("Dialog", "14400", nullptr));
        cb_baudrate->setItemText(6, QCoreApplication::translate("Dialog", "19200", nullptr));
        cb_baudrate->setItemText(7, QCoreApplication::translate("Dialog", "28800", nullptr));
        cb_baudrate->setItemText(8, QCoreApplication::translate("Dialog", "38400", nullptr));
        cb_baudrate->setItemText(9, QCoreApplication::translate("Dialog", "56000", nullptr));
        cb_baudrate->setItemText(10, QCoreApplication::translate("Dialog", "57600", nullptr));
        cb_baudrate->setItemText(11, QCoreApplication::translate("Dialog", "115200", nullptr));
        cb_baudrate->setItemText(12, QCoreApplication::translate("Dialog", "128000", nullptr));
        cb_baudrate->setItemText(13, QCoreApplication::translate("Dialog", "256000", nullptr));
        cb_baudrate->setItemText(14, QCoreApplication::translate("Dialog", "230400", nullptr));
        cb_baudrate->setItemText(15, QCoreApplication::translate("Dialog", "460800", nullptr));
        cb_baudrate->setItemText(16, QCoreApplication::translate("Dialog", "921600", nullptr));
        cb_baudrate->setItemText(17, QCoreApplication::translate("Dialog", "1000000", nullptr));
        cb_baudrate->setItemText(18, QCoreApplication::translate("Dialog", "2000000", nullptr));

        label_3->setText(QCoreApplication::translate("Dialog", "DataBits", nullptr));
        cb_databits->setItemText(0, QCoreApplication::translate("Dialog", "5", nullptr));
        cb_databits->setItemText(1, QCoreApplication::translate("Dialog", "6", nullptr));
        cb_databits->setItemText(2, QCoreApplication::translate("Dialog", "7", nullptr));
        cb_databits->setItemText(3, QCoreApplication::translate("Dialog", "8", nullptr));

        label_4->setText(QCoreApplication::translate("Dialog", "Direction", nullptr));
        cb_direction->setItemText(0, QCoreApplication::translate("Dialog", "Input ", nullptr));
        cb_direction->setItemText(1, QCoreApplication::translate("Dialog", "Output", nullptr));
        cb_direction->setItemText(2, QCoreApplication::translate("Dialog", "AllDirections", nullptr));

        label_5->setText(QCoreApplication::translate("Dialog", "FlowControl", nullptr));
        cb_flowcontrol->setItemText(0, QCoreApplication::translate("Dialog", "NoFlowControl", nullptr));
        cb_flowcontrol->setItemText(1, QCoreApplication::translate("Dialog", "HardwareControl", nullptr));
        cb_flowcontrol->setItemText(2, QCoreApplication::translate("Dialog", "SoftwareControl", nullptr));

        label_6->setText(QCoreApplication::translate("Dialog", "Parity", nullptr));
        cb_parity->setItemText(0, QCoreApplication::translate("Dialog", "NoParity", nullptr));
        cb_parity->setItemText(1, QCoreApplication::translate("Dialog", "EvenParity", nullptr));
        cb_parity->setItemText(2, QCoreApplication::translate("Dialog", "OddParity", nullptr));
        cb_parity->setItemText(3, QCoreApplication::translate("Dialog", "SpaceParity", nullptr));
        cb_parity->setItemText(4, QCoreApplication::translate("Dialog", "MarkParity", nullptr));

        label_7->setText(QCoreApplication::translate("Dialog", "StopBits", nullptr));
        cb_stopbits->setItemText(0, QCoreApplication::translate("Dialog", "OneStop", nullptr));
        cb_stopbits->setItemText(1, QCoreApplication::translate("Dialog", "OneAndHalfStop", nullptr));
        cb_stopbits->setItemText(2, QCoreApplication::translate("Dialog", "TwoStop", nullptr));

        pb_cancel->setText(QCoreApplication::translate("Dialog", "Cancel", nullptr));
        pb_connect->setText(QCoreApplication::translate("Dialog", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
