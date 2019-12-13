#ifndef COMBINED_H
#define COMBINED_H
#include "QSqlDatabase"
#include "QSql"
#include <QWidget>
#include "QVector"
#include "QTableWidgetItem"
#include "QSqlTableModel"
namespace Ui {
class combined;
class Col;
}

class Col{
public:
    Col(QString starship,QString TC_S,QString objective,QString TC_O,QString destination,QString TC_D,QString TC){
        this->starship=starship;
        this->objective = objective;
        this->destination =destination;
        this->TC_S = TC_S;
        this->TC_O = TC_O;
        this->TC_D = TC_D;
        this->TC = TC;
    }
    Col(){
            this->starship="";
            this->objective = "";
            this->destination ="";
            this->TC_S = "";
            this->TC_O = "";
            this->TC_D = "";
            this->TC = "";
    }
    void replaceO(QString obj){
        this->objective = obj;
    }
    void replaceD(QString des){
        this->destination = des;
    }
    QString starship;
    QString TC_S;
    QString objective;
    QString TC_O;
    QString destination;
    QString TC_D;
    QString TC;
};

class combined : public QWidget
{
    Q_OBJECT

public:
    explicit combined(QWidget *parent = nullptr);
    void setdata(QSqlDatabase *db1,QSqlDatabase *db2,QString sercurity);
    void readdata();
    void Tshow(QString sel);
    void Tsort(QString order);
    ~combined();

private slots:
    void on_Badd_clicked();

    void on_Bdelete_clicked();

    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);

    void on_Bselect_clicked();
    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_Bnext_clicked();

protected:
    void closeEvent(QCloseEvent *evevt);
private:
    QSqlTableModel *model;
    QVector<Col> cols;
    Ui::combined *ui;
    QSqlDatabase * dbh;
    QSqlDatabase * dbl;
    QString SecurityLevel;
    int row;
    int column;//单击tableview时更改
};

#endif // COMBINED_H
