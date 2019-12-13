#ifndef TABLE_H
#define TABLE_H
#include <QWidget>
#include <QDebug>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>


namespace Ui {
class table;
}

class table : public QWidget
{
    Q_OBJECT

public:
    explicit table(QWidget *parent = 0);
    void setdata(QSqlDatabase *db1,QSqlDatabase *db2,QString SecurityLevel);
//    void gotonext();
    QSqlDatabase * dbh;
    QSqlDatabase *dbl;
    ~table();

private slots:
//    void gotonext();
    void on_Bnext_clicked();
    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::table *ui;
    QString SecurityLevel;

};

#endif
