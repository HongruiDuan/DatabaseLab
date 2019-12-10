#ifndef COMBINED_H
#define COMBINED_H
#include "QSqlDatabase"
#include "QSql"
#include <QWidget>
#include "QVector"

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
    void setdata(QSqlDatabase *db1,QSqlDatabase *db2);
    void readdata();
    ~combined();

private slots:
    void on_Badd_clicked();

    void on_Bdelete_clicked();

private:
    QVector<Col> cols;
    Ui::combined *ui;
    QSqlDatabase * dbh;
    QSqlDatabase * dbl;
};

#endif // COMBINED_H