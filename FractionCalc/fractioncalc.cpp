#include "fractioncalc.h"
#include "ui_fractioncalc.h"
#include "myLib/fraction.h"

int flag = 0;

double LNum = 0;
double LDenom = 0;
double RNum = 0;
double RDenom = 0;

int tp = 0;
int btm = 0;

FractionCalc::FractionCalc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FractionCalc)
{
    ui->setupUi(this);
}

FractionCalc::~FractionCalc()
{
    delete ui;
}

QString FractionCalc::valid(QString str){
    for (int i =0;i<str.size();i++) {
        if (str[i].isDigit()){
            return str;
        } else if (str[i] == '-') {
            return str;
        }   else {
            ui->errorMessage->setText("***Please Check Your Input***");
            refresh();
        }
    }
}

void FractionCalc::refresh(){

    flag = 0;
    ui->Sign->setText("");
    ui->displaySign->setText("");

    double LNum = 0;
    ui->displayLNum->setText("");

    double LDenom = 0;
    ui->displayLDenom->setText("");

    double RNum = 0;
    ui->displayRNum->setText("");

    double RDenom = 0;
    ui->displayRDenom->setText("");
    ui->resNum->setText("");
    ui->resDenom->setText("");

    ui->Ldenom->clear();
    ui->Lnum->clear();
    ui->Rdenom->clear();
    ui->Rnum->clear();
}


void FractionCalc::on_exit_clicked()
{
    close();
}


void FractionCalc::on_add_clicked()
{
    flag = 1;
    ui->Sign->setText("+");
    ui->displaySign->setText("+");
}


void FractionCalc::on_subtract_clicked()
{
    flag = 2;
    ui->Sign->setText("-");
    ui->displaySign->setText("-");
}


void FractionCalc::on_multiply_clicked()
{
    flag = 3;
    ui->Sign->setText("x");
    ui->displaySign->setText("x");
}


void FractionCalc::on_divide_clicked()
{
    flag = 4;
    ui->Sign->setText("/");
    ui->displaySign->setText("/");
}


void FractionCalc::on_Lnum_editingFinished()
{
    QString arg1 = ui->Lnum->text();
    valid(arg1);
    int temp_Lnum = arg1.toInt();
    LNum = temp_Lnum;
    ui->displayLNum->setText(QString::number(LNum));
}


void FractionCalc::on_Ldenom_editingFinished()
{
    QString arg2 = ui->Ldenom->text();
    valid(arg2);
    int temp_Ldenom = arg2.toInt();
    if (arg2 == "0" ) {
        ui->errorMessage->setText("***Denominator Cannot Be Zero***");
        refresh();
    } else {LDenom = temp_Ldenom;}
    ui->displayLDenom->setText(QString::number(LDenom));
}

void FractionCalc::on_Rnum_editingFinished()
{
    QString arg3 = ui->Rnum->text();
    valid(arg3);
    int temp_Rnum = arg3.toInt();
    RNum = temp_Rnum;
    ui->displayRNum->setText(QString::number(RNum));

}


void FractionCalc::on_Rdenom_editingFinished()
{
    QString arg4 = ui->Rdenom->text();
    valid(arg4);
    int temp_Rdenom = arg4.toInt();
    if (arg4 == "0" ) {
        ui->errorMessage->setText("***Denominator Cannot Be Zero***");
        refresh();
    } else {RDenom = temp_Rdenom;}
    ui->displayRDenom->setText(QString::number(RDenom));


}



void FractionCalc::on_equal_clicked()
{

    Fraction num1 = Fraction(LNum, LDenom);
    Fraction num2 = Fraction(RNum, RDenom);

    switch(flag) {
    case 1:
    {
        Fraction ans (num1.numerator() * num2.denominator()
                      + num2.numerator() * num1.denominator(),
                      num1.denominator() * num2.denominator());
        if (((ans.numerator()) == 0) | ((ans.denominator()) == 1)) {
            ui->resNum->setText(QString::number(ans.numerator()));
        } else {
            ui->resNum->setText(QString::number(ans.numerator()));
            ui->resDenom->setText(QString::number(ans.denominator()));
        }
        break;
    }

    case 2:
    {
        Fraction ans((num1.numerator() * num2.denominator() - num2.numerator() * num1.denominator()),
                     num1.denominator() * num2.denominator());
        if (((ans.numerator()) == 0) | ((ans.denominator()) == 1)) {
            ui->resNum->setText(QString::number(ans.numerator()));
        } else {
            ui->resNum->setText(QString::number(ans.numerator()));
            ui->resDenom->setText(QString::number(ans.denominator()));
        }
        break;
    }
    case 3:
    {
        Fraction ans(num1.numerator() * num2.numerator(),
                     num1.denominator() * num2.denominator());
        if (((ans.numerator()) == 0) || ((ans.denominator()) == 1)) {
            ui->resNum->setText(QString::number(ans.numerator()));
        } else {
            ui->resNum->setText(QString::number(ans.numerator()));
            ui->resDenom->setText(QString::number(ans.denominator()));
        }
        break;
    }
    case 4:
    {
        Fraction ans(num1.numerator() * num2.denominator(),
                     num1.denominator() * num2.numerator());
        if (((ans.numerator()) == 0) | ((ans.denominator()) == 1)) {
            ui->resNum->setText(QString::number(ans.numerator()));
        } else {
            ui->resNum->setText(QString::number(ans.numerator()));
            ui->resDenom->setText(QString::number(ans.denominator()));
        }
        break;

    }
    }
}

void FractionCalc::on_clear_clicked()
{
    refresh();
}


void FractionCalc::on_Lnum_cursorPositionChanged(int arg1, int arg2)
{
    ui->resNum->setText("");
    ui->resDenom->setText("");
}


void FractionCalc::on_Ldenom_cursorPositionChanged(int arg1, int arg2)
{
    ui->resNum->setText("");
    ui->resDenom->setText("");
}


void FractionCalc::on_Rnum_textChanged(const QString &arg1)
{
    ui->resNum->setText("");
    ui->resDenom->setText("");
}


void FractionCalc::on_Rdenom_textChanged(const QString &arg1)
{
    ui->resNum->setText("");
    ui->resDenom->setText("");
}


