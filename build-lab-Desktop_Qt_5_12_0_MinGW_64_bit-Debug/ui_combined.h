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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_combined
{
public:
    QTableWidget *tableWidget;
    QLabel *label;
    QPushButton *Badd;
    QPushButton *Bdelete;
    QPushButton *Bnext;

    void setupUi(QWidget *combined)
    {
        if (combined->objectName().isEmpty())
            combined->setObjectName(QString::fromUtf8("combined"));
        combined->resize(619, 406);
        tableWidget = new QTableWidget(combined);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 60, 421, 291));
        label = new QLabel(combined);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 121, 16));
        Badd = new QPushButton(combined);
        Badd->setObjectName(QString::fromUtf8("Badd"));
        Badd->setGeometry(QRect(470, 90, 93, 28));
        Bdelete = new QPushButton(combined);
        Bdelete->setObjectName(QString::fromUtf8("Bdelete"));
        Bdelete->setGeometry(QRect(470, 190, 93, 28));
        Bnext = new QPushButton(combined);
        Bnext->setObjectName(QString::fromUtf8("Bnext"));
        Bnext->setGeometry(QRect(470, 300, 93, 28));

        retranslateUi(combined);

        QMetaObject::connectSlotsByName(combined);
    } // setupUi

    void retranslateUi(QWidget *combined)
    {
        combined->setWindowTitle(QApplication::translate("combined", "Form", nullptr));
        label->setText(QApplication::translate("combined", "\345\220\210\345\271\266\344\271\213\345\220\216\347\232\204\346\225\260\346\215\256\345\272\223", nullptr));
        Badd->setText(QApplication::translate("combined", "add", nullptr));
        Bdelete->setText(QApplication::translate("combined", "delete", nullptr));
        Bnext->setText(QApplication::translate("combined", "commit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class combined: public Ui_combined {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMBINED_H
