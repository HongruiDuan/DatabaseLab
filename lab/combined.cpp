#include "combined.h"
#include "ui_combined.h"
#include "QTableWidget"
#include "QSqlQuery"
#include "QVector"
#include "QDebug"
#include<QtSql>
#include <QSqlDatabase>
#include <QCloseEvent>
//#include "Qvector"

combined::combined(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::combined)
{
    ui->setupUi(this);
//
}
void combined::setdata(QSqlDatabase *db1, QSqlDatabase *db2,QString sercurity)
{
    this->dbh = db1;
    this->dbl = db2;
    this->SecurityLevel = sercurity;
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
    QString starship,C1,objective,C2,destination,C3;
//获取初始 Rs = 所有安全级比他低的用户的D 并集
    //清空Qvector
    QVector<Col> temp;
    while(queryH.next()){
       starship = queryH.value(0).toString();
       C1 = queryH.value(1).toString();
       objective = queryH.value(2).toString();
       C2 = queryH.value(3).toString();
       destination  = queryH.value(4).toString();
       C3 = queryH.value(5).toString();
       qDebug()<<starship+" "<<C1+" "<<objective+" "<<C2+" "<<destination+" "<<C3;
       //元组安全级为每个元组
       temp.append(Col(starship,C1,objective,C2,destination,C3,QString('S')));
    }
    while(queryL.next()){
        starship = queryL.value(0).toString();
        C1 = queryL.value(1).toString();
        objective = queryL.value(2).toString();
        C2 = queryL.value(3).toString();
        destination  = queryL.value(4).toString();
        C3 = queryL.value(5).toString();
       temp.append(Col(starship,C1,objective,C2,destination,C3,QString('U')));
    }
//将c初始之后的Rs打印出来
    this->cols =temp;
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
//  将读取的数据显示出来,vector形式
//    ui->tableWidget->clear();
//    ui->tableWidget->setRowCount(this->cols.size());//设置行数 行数由读取的记录确定
//    ui->tableWidget->setColumnCount(3);//设置列数
//    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"Starship"<<"Objective"<<"Destination"); //设置行头


//    for(int i =0; i<cols.size();i++){
//            ui->tableWidget->setItem(i,0,new QTableWidgetItem(cols.at(i).starship));
//            ui->tableWidget->setItem(i,1,new QTableWidgetItem(cols.at(i).objective));
//            ui->tableWidget->setItem(i,2,new QTableWidgetItem(cols.at(i).destination));
//     }
    QString sql_del = QString("drop table RS");
    qDebug()<<"删除RS表状态"<<queryH.exec(sql_del);
    QString sql_crea=QString("create table RS(Starship varchar(20),C1 varchar(20),Objective varchar(20),C2 varchar(20),Destination varchar(20),C3 varchar(20), primary key(Starship,C1,C2,C3))");
    qDebug()<<"创建RS表状态"<<queryH.exec(sql_crea);
    for(int i=0;i<cols.size();i++){
        QString sql_ins = QString("insert into RS values('%1','%2','%3','%4','%5','%6')").arg(
                    cols[i].starship,cols[i].TC_S,cols[i].objective,cols[i].TC_O,cols[i].destination,cols[i].TC_D);
        qDebug()<<queryH.exec(sql_ins);
    }
    model = new QSqlTableModel(ui->tableView,*dbh);
    model->setTable("RS");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->hide();//隐藏行号方法

    model->select();
    ui->tableView->setModel(model);
    //必须要绑定model之后再set属性
    ui->tableView->setShowGrid(false);
    ui->tableView->setColumnHidden(1,true);
    ui->tableView->setColumnHidden(3,true);
    ui->tableView->setColumnHidden(5,true);
}
void combined:: closeEvent(QCloseEvent *evevt){
    //结束时删除虚表
    QString sql_select = "drop table RS";
    QSqlQuery queryH(*this->dbh);
//    sql_select.replace("SOD","RS");
    qDebug()<<"删除表"<<queryH.exec(sql_select);
}

//结束时不调用析构函数
combined::~combined()
{
    delete ui;
}

//高安全级用户插入增加一条记录，直接向高安全级数据库实例中插入一条数据insert into SOD values(buying,Spying,Mars)
void combined::on_Badd_clicked()
{
        int rowcount = model->rowCount();
        model->insertRow(rowcount);
        // 插入元组的各个属性值，未赋值默认为null

//        return true;
}

void combined::on_Bnext_clicked()
{
    QString S = model->index(row,0).data().toString();  // 插入元组的主键，不能为空
    QString O = model->index(row,2).data().toString();
    QString D = model->index(row,4).data().toString();
    bool flag= true;
    //遍历RS中所有元组是否有重复的
    for(int i = 0; i < cols.size(); i++){
        if(cols.at(i).starship == S
                && cols.at(i).TC_S == SecurityLevel
                && cols.at(i).TC_O == SecurityLevel && cols.at(i).TC_D == SecurityLevel)
        {
            flag=false;
        }
//                return false;
            qDebug() << "ERROR:  主键重复,插入失败";
    }
    if(flag){
        //这个地方%写反了
        QString sql = QString("insert into SOD values('%1', '%2', '%3', '%4', '%5', '%6')").arg(S, SecurityLevel, O, SecurityLevel, D, SecurityLevel);
        if(SecurityLevel == "S"){ // 对高安全级实例插入
            QSqlQuery queryH(*this->dbh);
            qDebug()<<"S插入状态"<<queryH.exec(sql);
        }
        if(SecurityLevel == "U"){ // 对低安全级实例插入
            QSqlQuery queryL(*this->dbl);
            qDebug()<<"U插入状态"<<queryL.exec(sql);
        }
        readdata();
    }

}


//高安全级用户删除一条记录
void combined::on_Bdelete_clicked()
{
    // 如果每次只删除一个元组
    // 待删除元组下标
    int i = this->row;
    qDebug()<<"delete NO."<<i;
    if(cols.at(i).TC == SecurityLevel){
        // 删除元组判断，匹配主键（主关键字及其安全级，其他属性的安全级集合）
        QString sql = QString("delete from SOD where Starship = '%1' and C1 = '%2' and C2 = '%3' and C3 = '%4'")
                .arg(model->index(i,0).data().toString(),
                     model->index(i,1).data().toString(),
                     model->index(i,3).data().toString(),
                     model->index(i,5).data().toString());
//        sql.replace('\'',"\"");
        qDebug()<<"delete sql"<<sql;
        if(SecurityLevel == "S"){
            QSqlQuery queryH(*this->dbh);
            qDebug()<<"delete S status:"<<queryH.exec(sql);
        }
        if(SecurityLevel == "U"){
            QSqlQuery queryL(*this->dbl);
            qDebug()<<"delete L status:"<<queryL.exec(sql);
        }
    }else{
        qDebug() << "ERROR: 不允许删除低安全级实例的数据";
    }
    readdata();
}
// 用户插入增加一条记录，直接向数据库实例中插入一条数据insert into SOD values(buying,Spying,Mars)
//bool combined::on_Badd_clicked(){
//    // 插入元组的各个属性值，未赋值默认为null
//    QString S = ui->Badd->value;  // 插入元组的主键，不能为空
//    QString O;
//    QString D;

//    for(int i = 0; i < cols.size(); i++){
//        if(cols.at(i).starship == S && cols.at(i).TC_S == SecurityLevel
//                && cols.at(i).TC_O == SecurityLevel && cols.at(i).TC_D == SecurityLevel)
//            return false;
//            qDebug() << "ERROR:  主键重复,插入失败";
//    }

//    QString sql = QString("insert into SOD values(1%, 2%, 3%, 4%, 5%, 6%)").arg(S, SecurityLevel, O, SecurityLevel, D, SecurityLevel);
//    if(SecurityLevel == "S"){ // 对高安全级实例插入
//        QSqlQuery queryH(*this->dbh);
//        queryH.exec(sql);
//    }
//    if(SecurityLevel == "U"){ // 对低安全级实例插入
//        QSqlQuery queryL(*this->dbl);
//        queryL.exec(sql);
//    }
//    readdata();
//    return true;
//}
// 用户执行更新
//void combined::on_Bupdate_clicked(){
//    // 如果每次只更新一个元组(更新的话一般不考虑更新主键吧，应该是的)
//    // 待更新的元组下标
//    int i;
//    // 待更新的属性值
//    QString U_O;
//    bool O_flag; // 标志属性O是否在SET子句中
//    QString U_D;
//    bool D_flag; // 标志属性D是否在SET子句中
//    QString sql_1; // 更新语句
//    QString sql_2; // 插入语句（针对Rs中TC_S = "U",TC = "U"的元组）
//    if(O_flag && D_flag){
//        sql_1 = QString("update SOD set objective = 1%, c2 = 2%, destination = 3%, c3 = 4% where ")
//                .arg(U_O, SecurityLevel, U_D, SecurityLevel);
//    }else if(O_flag && !D_flag){
//        sql_1 = QString("update SOD set objective = 1%, c2 = 2%").arg(U_O, SecurityLevel);
//    }else if(!O_flag && D_flag){
//        sql_1 = QString("update SOD set destination = 1%, c3 = 2%").arg(U_D, SecurityLevel);
//    }
//    //QString sql_2 = QString("insert into SOD values()");
//    if(SecurityLevel == "S"){
//        QSqlQuery queryH(*this->dbh);
//        // 待更新元组主关键字安全级与用户安全级相等
//        if(cols.at(i).TC_S == "S"){
//            queryH.exec(sql_1);
//        }else if(cols.at(i).TC_S == "U"){ // 待更新元组主关键字安全级小于用户安全级（即由低安全级用户创建的元组）
//            // 待更新元组来自低安全级实例（向Ds中插入元组会不会主键冲突？需要再判断一下）
//            if(cols.at(i).TC == "U"){
//                if(O_flag && D_flag){
//                    sql_2 = QString("insert into SOD values(1%, 2%, 3%, 4%, 5%, 6%)")
//                            .arg(cols.at(i).starship, cols.at(i).TC_S, U_O, SecurityLevel, U_D, SecurityLevel);
//                    for(int i = 0; i < cols.size(); i++){
//                        if(cols.at(i).TC_O == SecurityLevel && cols.at(i).TC_D == SecurityLevel)
//                            return false;
//                            qDebug() << "ERROR:  主键重复,插入失败";
//                    }
//                }else if(O_flag && !D_flag){
//                    sql_2 = QString("insert into SOD values(1%, 2%, 3%, 4%, 5%, 6%)")
//                            .arg(cols.at(i).starship, cols.at(i).TC_S, U_O, SecurityLevel, "?", cols.at(i).TC_D);
//                    for(int i = 0; i < cols.size(); i++){
//                        if(cols.at(i).TC_O == SecurityLevel)
//                            return false;
//                            qDebug() << "ERROR:  主键重复,插入失败";
//                    }
//                }else if(!O_flag && D_flag){
//                    sql_2 = QString("insert into SOD values(1%, 2%, 3%, 4%, 5%, 6%)")
//                            .arg(cols.at(i).starship, cols.at(i).TC_S, "?", cols.at(i).TC_O, U_D, SecurityLevel);
//                    for(int i = 0; i < cols.size(); i++){
//                        if(cols.at(i).TC_D == SecurityLevel)
//                            return false;
//                            qDebug() << "ERROR:  主键重复,插入失败";
//                    }
//                }
//                queryH.exec(sql_2);
//            }else if(cols.at(i).TC == "S"){ // 待更新元组来自高安全级实例（即由低安全级用户创建，由高安全级用户更新过的元组）
//                queryH.exec(sql_1);
//            }
//        }
//    }else if(SecurityLevel == "U"){
//        QSqlQuery queryL(*this->dbl);
//        queryL.exec(sql_1);
//    }
//    readdata();
//}
// //用户删除一条记录

//根据str_sel 显示数据
void combined:: Tshow(QString sel){
    QString s1 = "Starship";
    QString s2 = "Objective";
    QString s3 = "Destination";
    if(sel.contains("*")){
        qDebug()<<"show all";
        ui->tableView->setColumnHidden(0,false);
        ui->tableView->setColumnHidden(2,false);
        ui->tableView->setColumnHidden(4,false);
    }
    else{
        if(sel.contains(s1)) ui->tableView->setColumnHidden(0,false);
        if(sel.contains(s2)) ui->tableView->setColumnHidden(2,false);
        if(sel.contains(s3)) ui->tableView->setColumnHidden(4,false);
    }

}

//根据str_order 设置排序
void combined:: Tsort(QString order){

    if(order != NULL)
    {
        QString sel = order.section(' ',0,0).simplified();
        QRegExp rx("[,]");
        QStringList sections = sel.split(rx);
        for(int i =0;i<sections.size();i++)
        {
            qDebug()<<"cols in sort:"<<sections[i];
            qDebug()<<"order"<<order.section(' ',1,1);
           if(sections[i]=="Starship"){
                if(order.section(' ',1,1)=="desc"||order.section(' ',1,1)=="DESC")   model->setSort(0,Qt::DescendingOrder); //id属性，即第0列，升序排列,Qt::DescendingOrder为降序排序
                else model->setSort(0,Qt::AscendingOrder);
                model->select();
           }
           if(sections[i]=="Objective"){
               if(order.section(' ',1,1)=="desc"||order.section(' ',1,1)=="DESC")   model->setSort(2,Qt::DescendingOrder); //id属性，即第0列，升序排列,Qt::DescendingOrder为降序排序
               else model->setSort(2,Qt::AscendingOrder);
               model->select();
           }
           if(sections[i]=="Destination"){
               qDebug()<<"order by Destination";
               if(order.section(' ',1,1)=="desc"||order.section(' ',1,1)=="DESC")   model->setSort(4,Qt::DescendingOrder); //id属性，即第0列，升序排列,Qt::DescendingOrder为降序排序
               else model->setSort(4,Qt::AscendingOrder);
               model->select();
           }

        }
    }

}
//查询带条件、排序 select * from RS where Destination= 'Mars' order by Objective desc
void combined::on_Bselect_clicked()
{
    QString sql = ui->lselect->text();
    if(sql !=NULL){
        sql.replace("SOD","RS");
        qDebug()<<sql;

        //构建正则表达式，从字符串中匹配出各个部分
        QString str_sel =  sql.section(" ",1,1).trimmed();
        QString str_where = sql.section("where",1,1).trimmed().section("order by",0,0).trimmed();
        QString str_order = sql.section("where",1,1).trimmed().section("order by",1,1).trimmed();
        qDebug()<<"str_sel:"<<str_sel <<"str_where:"<<str_where <<"str_order:"<<str_order;
        str_where=str_where.trimmed();
        qDebug()<<str_where;
        model->setFilter(str_where);
        Tsort(str_order);
        ui->tableView->setModel(model);
        for(int i=0;i<6;i++){
          ui->tableView->setColumnHidden(i,true);
       \
        }
        Tshow(str_sel);
    }
    else{
        Tshow("*");
    }

}


// //双击tableview,可以更新数据
void combined::on_tableView_doubleClicked(const QModelIndex &index)
{
    qDebug()<<"table is clicked";
   //    int row = item->row();
   //    int col=item->column();
   //    qDebug()<<"table("<<row<<","<<col<<")is clicked";
   //    QString  data=item->data(row).toString();
   //    qDebug()<<data;
}

void combined::on_tableView_clicked(const QModelIndex &index)
{
    qDebug()<<"table_clicked()"<<index.row();
    this->row=index.row();
}


