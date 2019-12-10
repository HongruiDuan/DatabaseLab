#include "table.h"
#include "ui_table.h"
#include<QtSql>
#include <QSqlDatabase>
#include<QTableView>
#include <combined.h>

table::table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::table)
{
    ui->setupUi(this);

}

void table::setdata(QSqlDatabase *db1, QSqlDatabase *db2){
    this->dbh=db1;
    this->dbl=db2;
    QSqlTableModel *model1 = new QSqlTableModel(ui->tableView1,*dbh);
    model1->setTable("SOD");
    model1->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model1->select();
    ui->tableView1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView1->setShowGrid(false);
    ui->tableView1->setModel(model1);
    QSqlTableModel *model2 = new QSqlTableModel(ui->tableView2,*dbl);
    model2->setTable("SOD");
    model2->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model2->select();
    ui->tableView2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView2->setShowGrid(false);
    ui->tableView2->setModel(model2);
    this->show();
}
//void table::gotonext(){
//    combined * page2 = new combined;
//    page2->setdata(dbh,dbl);
//    this->hide();
//    page2->show();
//}

table::~table()
{
    delete ui;
}

void table::on_Bnext_clicked()
{
    combined * page2 = new combined;
    page2->setdata(dbh,dbl);
    this->hide();
    page2->show();
}
