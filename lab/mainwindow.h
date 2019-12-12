#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <table.h>
#include <combined.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setdata(QSqlDatabase *db1,QSqlDatabase *db2);
    QSqlDatabase *dbh;
    QSqlDatabase *dbl;
    ~MainWindow();

private slots:
    void on_Blogin_clicked();
private:
    Ui::MainWindow *ui;
    QString user1 = "U";
    QString pass1 = "U";
    QString user2 = "S";
    QString pass2 = "S";
    QString security;
    table * page1;
    combined * page2;
};

#endif //MAINWINDOW_H
