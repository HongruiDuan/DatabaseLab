/********************************************************************************
** Form generated from reading UI file 'table.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_H
#define UI_TABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_table
{
public:
    QLabel *label;
    QTableView *tableView1;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTableView *tableView2;
    QLabel *label_2;
    QPushButton *Bnext;

    void setupUi(QWidget *table)
    {
        if (table->objectName().isEmpty())
            table->setObjectName(QString::fromUtf8("table"));
        table->resize(902, 315);
        label = new QLabel(table);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 30, 151, 16));
        tableView1 = new QTableView(table);
        tableView1->setObjectName(QString::fromUtf8("tableView1"));
        tableView1->setGeometry(QRect(10, 60, 371, 241));
        pushButton = new QPushButton(table);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(790, 160, 93, 28));
        pushButton_2 = new QPushButton(table);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(790, 70, 93, 28));
        tableView2 = new QTableView(table);
        tableView2->setObjectName(QString::fromUtf8("tableView2"));
        tableView2->setGeometry(QRect(400, 60, 371, 241));
        label_2 = new QLabel(table);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(510, 30, 151, 16));
        Bnext = new QPushButton(table);
        Bnext->setObjectName(QString::fromUtf8("Bnext"));
        Bnext->setGeometry(QRect(790, 260, 93, 28));

        retranslateUi(table);

        QMetaObject::connectSlotsByName(table);
    } // setupUi

    void retranslateUi(QWidget *table)
    {
        table->setWindowTitle(QApplication::translate("table", "Form", nullptr));
        label->setText(QApplication::translate("table", "UserS \346\225\260\346\215\256\345\272\223\344\270\255\347\232\204\346\225\260\346\215\256", nullptr));
        pushButton->setText(QApplication::translate("table", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("table", "PushButton", nullptr));
        label_2->setText(QApplication::translate("table", "UserU \346\225\260\346\215\256\345\272\223\344\270\255\347\232\204\346\225\260\346\215\256", nullptr));
        Bnext->setText(QApplication::translate("table", "\344\270\213\344\270\200\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class table: public Ui_table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_H
