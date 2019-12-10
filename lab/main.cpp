#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    //连接高安全级用户数据库
    QSqlDatabase dbh = QSqlDatabase::addDatabase("QODBC", "db1");

    dbh.setPort(1521);
    dbh.setHostName("192.168.18.15");
    dbh.setDatabaseName("UserS");

    dbh.setUserName("system");
    dbh.setPassword("DhR13871956183");

    if(!dbh.open())
    {
      qDebug()<<dbh.lastError().text();
      qDebug()<<"database open failed!";
      return false;
    }
    else qDebug()<<"high security database open success!";

    //连接低安全级用户数据库
    QSqlDatabase dbl = QSqlDatabase::addDatabase("QODBC", "db2");
    dbl.setPort(1521);
    dbl.setHostName("192.168.18.15");
    dbl.setDatabaseName("UserU");

    dbl.setUserName("system");
    dbl.setPassword("DhR13871956183");
    if(!dbl.open())
    {
      qDebug()<<dbl.lastError().text();
      qDebug()<<"database open failed!";
      return false;
    }
    else qDebug()<<"low security database open success!";
    QSqlDatabase *db1 = &dbh;
    QSqlDatabase *db2 = &dbl;
    w.setdata(db1,db2);
    w.show();

    return a.exec();
}
