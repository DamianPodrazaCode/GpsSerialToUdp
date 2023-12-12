/********************************************************************************
** Form generated from reading UI file 'terminal.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TERMINAL_H
#define UI_TERMINAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Terminal
{
public:
    QGridLayout *gridLayout;
    QPlainTextEdit *pte_read;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *le_extract;
    QLabel *label_3;
    QLineEdit *le_change;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_5;
    QLineEdit *le_port;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pb_send;
    QHBoxLayout *horizontalLayout;
    QCheckBox *cb_rewind;
    QCheckBox *cb_warp;
    QCheckBox *cb_autoDelete;
    QLabel *label;
    QLineEdit *le_lineCount;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pb_clear_read;
    QPushButton *pb_startStop;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *le_udpSend;
    QLineEdit *le_send;

    void setupUi(QDialog *Terminal)
    {
        if (Terminal->objectName().isEmpty())
            Terminal->setObjectName("Terminal");
        Terminal->resize(769, 561);
        gridLayout = new QGridLayout(Terminal);
        gridLayout->setObjectName("gridLayout");
        pte_read = new QPlainTextEdit(Terminal);
        pte_read->setObjectName("pte_read");
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(10);
        pte_read->setFont(font);
        pte_read->setUndoRedoEnabled(false);
        pte_read->setLineWrapMode(QPlainTextEdit::NoWrap);
        pte_read->setTextInteractionFlags(Qt::TextBrowserInteraction);

        gridLayout->addWidget(pte_read, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(Terminal);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        le_extract = new QLineEdit(Terminal);
        le_extract->setObjectName("le_extract");

        horizontalLayout_2->addWidget(le_extract);

        label_3 = new QLabel(Terminal);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        le_change = new QLineEdit(Terminal);
        le_change->setObjectName("le_change");

        horizontalLayout_2->addWidget(le_change);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        label_5 = new QLabel(Terminal);
        label_5->setObjectName("label_5");

        horizontalLayout_4->addWidget(label_5);

        le_port = new QLineEdit(Terminal);
        le_port->setObjectName("le_port");

        horizontalLayout_4->addWidget(le_port);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        pb_send = new QPushButton(Terminal);
        pb_send->setObjectName("pb_send");
        pb_send->setCheckable(true);
        pb_send->setAutoDefault(false);

        horizontalLayout_4->addWidget(pb_send);


        gridLayout->addLayout(horizontalLayout_4, 5, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        cb_rewind = new QCheckBox(Terminal);
        cb_rewind->setObjectName("cb_rewind");
        cb_rewind->setChecked(false);

        horizontalLayout->addWidget(cb_rewind);

        cb_warp = new QCheckBox(Terminal);
        cb_warp->setObjectName("cb_warp");
        cb_warp->setChecked(false);

        horizontalLayout->addWidget(cb_warp);

        cb_autoDelete = new QCheckBox(Terminal);
        cb_autoDelete->setObjectName("cb_autoDelete");
        cb_autoDelete->setChecked(true);

        horizontalLayout->addWidget(cb_autoDelete);

        label = new QLabel(Terminal);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        le_lineCount = new QLineEdit(Terminal);
        le_lineCount->setObjectName("le_lineCount");

        horizontalLayout->addWidget(le_lineCount);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pb_clear_read = new QPushButton(Terminal);
        pb_clear_read->setObjectName("pb_clear_read");
        pb_clear_read->setAutoDefault(false);

        horizontalLayout->addWidget(pb_clear_read);

        pb_startStop = new QPushButton(Terminal);
        pb_startStop->setObjectName("pb_startStop");
        pb_startStop->setCheckable(true);
        pb_startStop->setAutoDefault(false);

        horizontalLayout->addWidget(pb_startStop);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_4 = new QLabel(Terminal);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);

        le_udpSend = new QLineEdit(Terminal);
        le_udpSend->setObjectName("le_udpSend");

        horizontalLayout_3->addWidget(le_udpSend);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        le_send = new QLineEdit(Terminal);
        le_send->setObjectName("le_send");

        gridLayout->addWidget(le_send, 4, 0, 1, 1);


        retranslateUi(Terminal);

        QMetaObject::connectSlotsByName(Terminal);
    } // setupUi

    void retranslateUi(QDialog *Terminal)
    {
        Terminal->setWindowTitle(QCoreApplication::translate("Terminal", "Terminal GPS to UDP", nullptr));
        label_2->setText(QCoreApplication::translate("Terminal", "Extract -->", nullptr));
        le_extract->setText(QCoreApplication::translate("Terminal", "$GPGGA", nullptr));
        label_3->setText(QCoreApplication::translate("Terminal", "change to -->", nullptr));
        le_change->setText(QCoreApplication::translate("Terminal", "$GNGGA", nullptr));
        label_5->setText(QCoreApplication::translate("Terminal", "Port:", nullptr));
        le_port->setText(QCoreApplication::translate("Terminal", "8477", nullptr));
        pb_send->setText(QCoreApplication::translate("Terminal", "Start send", nullptr));
        cb_rewind->setText(QCoreApplication::translate("Terminal", "Auto scroll", nullptr));
        cb_warp->setText(QCoreApplication::translate("Terminal", "Warp Lines", nullptr));
        cb_autoDelete->setText(QCoreApplication::translate("Terminal", "Auto delete", nullptr));
        label->setText(QCoreApplication::translate("Terminal", "Lines count", nullptr));
        le_lineCount->setText(QCoreApplication::translate("Terminal", "20", nullptr));
        pb_clear_read->setText(QCoreApplication::translate("Terminal", "Clear", nullptr));
        pb_startStop->setText(QCoreApplication::translate("Terminal", "Stop", nullptr));
        label_4->setText(QCoreApplication::translate("Terminal", "UDP send:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Terminal: public Ui_Terminal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TERMINAL_H
