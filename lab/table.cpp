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

void table::setdata(QSqlDatabase *db1, QSqlDatabase *db2,QString sercuritylevel){
    this->dbh=db1;
    this->dbl=db2;

    QSqlTableModel *model = new QSqlTableModel(ui->tableView,*dbl);
    model->setTable("SOD");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setShowGrid(false);

    ui->tableView->setColumnHidden(1,0);
    ui->tableView->setColumnWidth(3,0);
    ui->tableView->setColumnWidth(5,0);
    ui->tableView->setModel(model);
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
//    page2->setdata(dbh,dbl);
//    this->hide();
//    page2->show();
}

void table::on_tableView_doubleClicked(const QModelIndex &index)
{

}
