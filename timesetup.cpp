#include "timesetup.h"
#include "ui_timesetup.h"

 extern QString Datesetup;
 extern bool OK;

Timesetup::Timesetup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Timesetup)
{
    ui->setupUi(this);
}

Timesetup::~Timesetup()
{
    delete ui;
}

void Timesetup::on_pushButton_clicked()
{
    Datesetup.append("1");
    ui->lineEdit->setText(Datesetup);

}


void Timesetup::on_pushButton_2_clicked()
{
    Datesetup.append("2");
    ui->lineEdit->setText(Datesetup);

}

void Timesetup::on_pushButton_3_clicked()
{
    Datesetup.append("3");
    ui->lineEdit->setText(Datesetup);

}



void Timesetup::on_pushButton_4_clicked()
{
    Datesetup.append("4");
    ui->lineEdit->setText(Datesetup);

}

void Timesetup::on_pushButton_5_clicked()
{
    Datesetup.append("5");
    ui->lineEdit->setText(Datesetup);
}

void Timesetup::on_pushButton_6_clicked()
{
    Datesetup.append("6");
    ui->lineEdit->setText(Datesetup);

}

void Timesetup::on_pushButton_7_clicked()
{
    Datesetup.append("7");
    ui->lineEdit->setText(Datesetup);

}

void Timesetup::on_pushButton_8_clicked()
{
    Datesetup.append("8");
    ui->lineEdit->setText(Datesetup);

}

void Timesetup::on_pushButton_9_clicked()
{
    Datesetup.append("9");
    ui->lineEdit->setText(Datesetup);
}

void Timesetup::on_pushButton_11_clicked()
{
    Datesetup.append("0");
    ui->lineEdit->setText(Datesetup);
}


void Timesetup::on_pushButton_13_clicked() // - 键
{
    Datesetup.append("-");
    ui->lineEdit->setText(Datesetup);
}


void Timesetup::on_pushButton_14_clicked()// :键
{
    Datesetup.append(":");
    ui->lineEdit->setText(Datesetup);
}

void Timesetup::on_pushButton_16_clicked()//空格键
{
    Datesetup.append(" ");
    ui->lineEdit->setText(Datesetup);
}

void Timesetup::on_pushButton_10_clicked()  //ok 键
{
    OK = true;
}


void Timesetup::on_pushButton_12_clicked() //esc 键
{
    Datesetup = Datesetup.left(Datesetup.length() - 1);
    ui->lineEdit->setText(Datesetup);
}

void Timesetup::on_pushButton_15_clicked() //关闭 键
{
    this->close();
}
