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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_combined
{
public:
    QTableWidget *tableWidget;
    QPushButton *Badd;
    QPushButton *Bdelete;
    QPushButton *Bnext;
    QLineEdit *lselect;
    QPushButton *Bselect;

    void setupUi(QWidget *combined)
    {
        if (combined->objectName().isEmpty())
            combined->setObjectName(QString::fromUtf8("combined"));
        combined->resize(619, 406);
        tableWidget = new QTableWidget(combined);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 80, 421, 291));
        Badd = new QPushButton(combined);
        Badd->setObjectName(QString::fromUtf8("Badd"));
        Badd->setGeometry(QRect(480, 110, 93, 28));
        Bdelete = new QPushButton(combined);
        Bdelete->setObjectName(QString::fromUtf8("Bdelete"));
        Bdelete->setGeometry(QRect(480, 210, 93, 28));
        Bnext = new QPushButton(combined);
        Bnext->setObjectName(QString::fromUtf8("Bnext"));
        Bnext->setGeometry(QRect(480, 320, 93, 28));
        lselect = new QLineEdit(combined);
        lselect->setObjectName(QString::fromUtf8("lselect"));
        lselect->setGeometry(QRect(20, 30, 421, 21));
        Bselect = new QPushButton(combined);
        Bselect->setObjectName(QString::fromUtf8("Bselect"));
        Bselect->setGeometry(QRect(480, 30, 93, 28));

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
