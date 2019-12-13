/********************************************************************************
** Form generated from reading UI file 'combined.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMBINED_H
#define UI_COMBINED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_combined
{
public:
    QPushButton *Badd;
    QPushButton *Bdelete;
    QPushButton *Bnext;
    QLineEdit *lselect;
    QPushButton *Bselect;
    QTableView *tableView;

    void setupUi(QWidget *combined)
    {
        if (combined->objectName().isEmpty())
            combined->setObjectName(QString::fromUtf8("combined"));
        combined->resize(871, 406);
        Badd = new QPushButton(combined);
        Badd->setObjectName(QString::fromUtf8("Badd"));
        Badd->setGeometry(QRect(740, 110, 93, 28));
        Bdelete = new QPushButton(combined);
        Bdelete->setObjectName(QString::fromUtf8("Bdelete"));
        Bdelete->setGeometry(QRect(740, 210, 93, 28));
        Bnext = new QPushButton(combined);
        Bnext->setObjectName(QString::fromUtf8("Bnext"));
        Bnext->setGeometry(QRect(740, 320, 93, 28));
        lselect = new QLineEdit(combined);
        lselect->setObjectName(QString::fromUtf8("lselect"));
        lselect->setGeometry(QRect(20, 30, 671, 21));
        Bselect = new QPushButton(combined);
        Bselect->setObjectName(QString::fromUtf8("Bselect"));
        Bselect->setGeometry(QRect(740, 30, 93, 28));
        tableView = new QTableView(combined);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(20, 60, 681, 311));

        retranslateUi(combined);

        QMetaObject::connectSlotsByName(combined);
    } // setupUi

    void retranslateUi(QWidget *combined)
    {
        combined->setWindowTitle(QApplication::translate("combined", "Form", nullptr));
        Badd->setText(QApplication::translate("combined", "add", nullptr));
        Bdelete->setText(QApplication::translate("combined", "delete", nullptr));
        Bnext->setText(QApplication::translate("combined", "commit", nullptr));
        Bselect->setText(QApplication::translate("combined", "select", nullptr));
    } // retranslateUi

};

namespace Ui {
    class combined: public Ui_combined {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMBINED_H
