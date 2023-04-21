#include "dialogcoordedit.h"
#include "ui_dialogcoordedit.h"

DialogCoordEdit::DialogCoordEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCoordEdit)
{
    ui->setupUi(this);
}

DialogCoordEdit::~DialogCoordEdit()
{
    delete ui;
}


void DialogCoordEdit::SetName(QString name)
{
    ui->lineEdit_Name->setText(name);
}


QString DialogCoordEdit::GetName()
{
    return ui->lineEdit_Name->text();
}

void DialogCoordEdit::SetCoord(double X, double Y, double Z)
{
    ui->lineEdit_Lat->setText(QString::number(X));
    ui->lineEdit_Lon->setText(QString::number(Y));
    ui->lineEdit_Height->setText(QString::number(Z));
}

void DialogCoordEdit::GetCoord(double &X, double &Y, double &Z)
{
    X = ui->lineEdit_Lat->text().toDouble();
    Y = ui->lineEdit_Lon->text().toDouble();
    Z = ui->lineEdit_Height->text().toDouble();
}
