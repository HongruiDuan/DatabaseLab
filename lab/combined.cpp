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
    //新建对于两个安全级数据库的查询
    QString str = QString("select * from SOD");
    QSqlQuery queryH(*this->dbh);
    QSqlQuery queryL(*this->dbl);
    queryH.exec(str);
    queryL.exec(str);

    QString starship,objective,destination;
    this->cols.clear();
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
//  将读取的数据显示出来
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

//高安全级用户插入增加一条记录，直接向高安全级数据库实例中插入一条数据insert into SOD values(buying,Spying,Mars)
void combined::on_Badd_clicked()
{

    QSqlQuery queryH(*this->dbh);
    queryH.prepare("insert into SOD values(?,?,?)");
    queryH.bindValue(0,"buying");
    queryH.bindValue(1,"Spying");
    queryH.bindValue(2,"Mars");
    queryH.exec();
    readdata();
}

//高安全级用户删除一条记录
void combined::on_Bdelete_clicked()
{
    QSqlQuery queryH(*this->dbh);
    queryH.prepare("DELETE FROM faceimage WHERE Starship=? and Objective = ? and Destination = ?");
    queryH.bindValue(0,"buying");
    queryH.bindValue(1,"Spying");
    queryH.bindValue(2,"Mars");
    queryH.exec();
    readdata();
}

//双击tableview,可以更新数据
void combined::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{

}
