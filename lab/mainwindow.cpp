#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "string.h"
#include "QMessageBox"
#include "table.h"
#include "combined.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Lpassword->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    //在mainwindow被析构的时候将修改了的数据写入到数据库中
    delete ui;
}
void MainWindow::setdata(QSqlDatabase *db1, QSqlDatabase *db2){
    this->dbh = db1;
    this->dbl = db2;
}
void MainWindow::on_Blogin_clicked()
{
    QString username = ui->Laccount->text();
    QString password = ui->Lpassword->text();
    //登录验证
    if(username == user1 && password == pass1){
        this->hide();
        page1 = new table;
        page1->setdata(dbh,dbl,"S");
        page1->show();
    }
    else if(username == user2 && password == pass2){
        this->hide();
        page2 = new combined;
        page2->setdata(dbh,dbl,"S");
        page2->show();
    }
    else{
        ui->Lpassword->clear();

    }

// 分别显示两个数据库的数据
//      page1 = new table;
//      page1->setdata(dbh,dbl);
//      page1->show();

//        page2->setdata(dbh,dbl);
//        page2->show();

}
