#include "combined.h"
#include "ui_combined.h"
#include "QTableWidget"
#include "QSqlQuery"
#include "QVector"
#include "QDebug"

combined::combined(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::combined)
{
    ui->setupUi(this);
//
}
void combined::setdata(QSqlDatabase *db1, QSqlDatabase *db2)
{
    this->dbh = db1;
    this->dbl = db2;
//    QTableWidget * table = new QTableWidget(this);


    readdata();

    this->show();

}


void combined::readdata(){
    QString str = QString("select * from SOD");
    QSqlQuery queryH(*this->dbh);
    QSqlQuery queryL(*this->dbl);
    queryH.exec(str);
    queryL.exec(str);
    int Ndbh,Ndbl;
    Ndbh = queryH.size();
    Ndbl = queryL.size();

    QString starship,objective,destination;
    while(queryH.next()){
       starship = queryH.value(0).toString();
       objective = queryH.value(1).toString();
       destination  = queryH.value(2).toString();
       this->cols.append(Col(starship,QString('U'),objective,QString('S'),destination,QString('S'),QString('S')));
    }
    while(queryL.next()){
       starship = queryL.value(0).toString();
       objective = queryL.value(1).toString();
       destination  = queryL.value(2).toString();
       this->cols.append(Col(starship,QString('U'),objective,QString('S'),destination,QString('S'),QString('S')));
    }
//将读取的数据显示出来
    ui->tableWidget->setRowCount(this->cols.size());//设置行数 行数由读取的记录确定
    ui->tableWidget->setColumnCount(3);//设置列数
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"Starship"<<"objective"<<"Destination"); //设置行头
//    table->setItem(0,0,new QTableWidgetItem("item1")); //设置表格内容
    for(int i =0; i<cols.size();i++){
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(cols.at(i).starship));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(cols.at(i).objective));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(cols.at(i).destination));
     }
}
combined::~combined()
{
    delete ui;
}

void combined::on_Badd_clicked()
{

}

void combined::on_Bdelete_clicked()
{

}
