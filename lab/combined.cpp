#include "combined.h"
#include "ui_combined.h"
#include "QTableWidget"
#include "QSqlQuery"
#include "QVector"
#include "QDebug"
//#include "Qvector"

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
    readdata();
    this->show();
}

// 恢复算法
void combined::readdata(){
    //新建对于两个安全级数据库的查询
    QSqlQuery queryH(*this->dbh);
    QSqlQuery queryL(*this->dbl);
    QString str = QString("select * from system.SOD");

    queryH.exec(str);
    queryL.exec(str);
//    qDebug()<<queryH.exec();
//    if(!queryH.exec("select * from student")
//    {
//        qDebug()<<queryH.text();
//    }
//    qDebug()<<queryH.exec("insert into student values(0, 'first')");
//    qDebug()<<queryH.exec("select * from student");

    QString starship,C1,objective,C2,destination,C3;
//获取初始 Rs = 所有安全级比他低的用户的D 并集
    while(queryH.next()){

       starship = queryH.value(0).toString();
       C1 = queryH.value(1).toString();
       objective = queryH.value(2).toString();
       C2 = queryH.value(3).toString();
       destination  = queryH.value(4).toString();
       C3 = queryH.value(5).toString();
       qDebug()<<starship+" "<<C1+" "<<objective+" "<<C2+" "<<destination+" "<<C3;
       //元组安全级为每个元组
       this->cols.append(Col(starship,C1,objective,C2,destination,C3,QString('S')));
    }
    while(queryL.next()){
        starship = queryL.value(0).toString();
        C1 = queryL.value(1).toString();
        objective = queryL.value(2).toString();
        C2 = queryL.value(3).toString();
        destination  = queryL.value(4).toString();
        C3 = queryL.value(5).toString();
       this->cols.append(Col(starship,C1,objective,C2,destination,C3,QString('U')));
    }
//将c初始之后的Rs打印出来
    qDebug()<<"初始的Rs";
    for(int i =0;i<this->cols.size();i++){
       qDebug()<<cols[i].starship+" "<<cols[i].TC_D+" "<<cols[i].objective+" "<<cols[i].TC_O+" "<<cols[i].destination+" "<<cols[i].TC_D;
    }
//运用键删除规则垃圾回收  删除低安全级用户删除了的 在高安全级用户更新产生的多实例
    for(int i =0;i<this->cols.size();i++){
        for(int j =0;j<this->cols.size();j++){

            if(i!=j&&(cols.at(i).starship==cols.at(j).starship)&&(cols.at(i).TC_D==cols.at(j).TC_D) &&(cols.at(j).TC==cols.at(i).TC_D))
            {
                //从Rs中删除t2，同时
            }
        }
    }
//对Rs采用？替换规则 a
    for(int i =0;i<this->cols.size();i++){
        QString Starship,Objective,Destination;
        Starship = cols.at(i).starship;
        Objective = cols.at(i).objective;
        Destination = cols.at(i).destination;
        //如果元组中包含？
        if(Objective == '?')
        {
            bool flag = false;
            qDebug()<<"objective==?";
            for(int j =0;j<this->cols.size();j++){
                // cols[i]为元组t，cols[j]为元组u u更新t
                if(i!=j&&(cols.at(i).starship==cols.at(j).starship)&&(cols.at(i).TC_S==cols.at(j).TC_S)&&(cols.at(j).TC==cols.at(i).TC_O))
                {
                    cols[i].objective = cols.at(j).objective;
                    flag =true; //找到了
                }
            }
            //有？但是Rs中没有满足替换要求的元组
           if(!flag) cols[i].objective = QString("NULL");
        }
        if(Destination == '?')
        {
            bool flag=false;
            qDebug()<<"objective==?";
            for(int j =0;j<this->cols.size();j++){
                if(i!=j&&(cols.at(i).starship==cols.at(j).starship)&&(cols.at(i).TC_S==cols.at(j).TC_S)&&(cols.at(j).TC==cols.at(i).TC_D))
                {
                    cols[i].objective = cols.at(j).objective;
                }
            }

           if(!flag) cols[i].objective = QString("NULL");
        }
    }

//对Rs中满足不包含关系
    for(int i =0;i<this->cols.size();i++){
        for(int j =0;j<this->cols.size();j++){
            if(i!=j&&(cols.at(i).starship==cols.at(j).starship)&&(cols.at(i).TC_D==cols.at(j).TC_D)
               &&((cols.at(i).objective==cols.at(j).objective)||(cols.at(i).objective!="NULL"&& cols.at(j).objective=="NULL"))&&(cols.at(i).TC_O==cols.at(j).TC_O)
               &&((cols.at(i).destination==cols.at(j).destination)||(cols.at(i).objective!="NULL"&& cols.at(j).objective=="NULL"))&&(cols.at(i).TC_D==cols.at(j).TC_D)
               )//满足相等或者包含关系
            {
               //删除被包含的元组 col.remove 不会改变size()大小
                cols.remove(j);
            }
        }
    }
//将恢复之后的Rs打印出来
    for(int i =0;i<this->cols.size();i++){
        qDebug()<<cols[i].starship+" "<<cols[i].TC_D+" "<<cols[i].objective+" "<<cols[i].TC_O+" "<<cols[i].destination+" "<<cols[i].TC_D;
    }
//  将读取的数据显示出来,
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(this->cols.size());//设置行数 行数由读取的记录确定
    ui->tableWidget->setColumnCount(3);//设置列数
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"Starship"<<"Objective"<<"Destination"); //设置行头

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
    queryH.prepare("insert into SOD values(?,?,?,?,?,?)");
    queryH.bindValue(0,"buying");
    queryH.bindValue(1,"S");
    queryH.bindValue(2,"Spying");
    queryH.bindValue(3,"S");
    queryH.bindValue(4,"Mars");
    queryH.bindValue(5,"S");
    queryH.exec();

    readdata();
}

//高安全级用户删除一条记录
void combined::on_Bdelete_clicked()
{
    QSqlQuery queryH(*this->dbh);
    QString str = QString("delete from SOD where Starship = '%1' and Objective = '%2'  and Destination = '%3' ").arg('buying','Spying','Mars');
    queryH.exec(str);
    //vector如果存储的是指向对象的指针，clear不会调用到对应的析构函数。会造成内存泄漏
    for(int i =0;i<this->cols.size();i++){
        if((this->cols.at(i).starship == QString("buying")) && (this->cols.at(i).objective == QString("Spying"))){
            this->cols.remove(i);
        }
    }
    readdata();
}

//双击tableview,可以更新数据
void combined::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    qDebug()<<"table is clicked";
    int row = item->row();
    int col=item->column();
    qDebug()<<"table("<<row<<","<<col<<")is clicked";
    QString  data=item->data(row).toString();
    qDebug()<<data;
}
bool cmps(Col c1,Col c2){
    return c1.starship<c2.starship;
}
bool cmpo(Col c1,Col c2){
    return c1.objective<c2.objective;
}
bool cmpd(Col c1,Col c2){
    return c1.destination<c2.destination;
}

//查询带条件、排序
void combined::on_Bselect_clicked()
{
    QString sql_select = ui->lselect->text();
    qDebug()<<sql_select;
    QSqlQuery queryH(*this->dbh);
    //1.直接将输入的字符串传给Rs，在高安全级用户数据库里面直接建一个虚表，交给虚表执行

//    QString sql_crea=QString("create table RS(Starship vachar(20),C1 vachar(20),Objective vachar(20),C2 vachar(20),Destination vachar(20),C3 vachar(20))");
//    queryH.exec(sql_crea);
//    for(int i=0;i<cols.size();i++){
//        QString sql_ins = QString("insert into RS values('%1','%2','%3','%4','%5','%6')").arg(
//                    cols[i].starship,cols[i].TC_S,cols[i].objective,cols[i].TC_O,cols[i].destination,cols[i].TC_D);
//        queryH.exec(sql_ins);
//    }
//    sql_select.replace("SOD","RS");

    //清除原来

    //"select * from SOD where  and;"



//重新建立连接选取数据
    QSqlQuery queryH(*this->dbh);
    QSqlQuery queryL(*this->dbl);
    std::sort(this->cols.begin(),this->cols.end(),cmpo);
}
