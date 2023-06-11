#include "dialog.h"
#include "ui_dialog.h"
#include<QDebug>
#include<QSlider>
#include<QSpinBox>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->whorizontalSlider->setMaximum(30);//设置滑动调的宽度最大值
    ui->whorizontalSlider->setMinimum(9);//设置宽度最小值
    ui->whorizontalSlider->setTracking(true);//打开滑块跟踪
    ui->whorizontalSlider->setSingleStep(1);//步长为1

    ui->hhorizontalSlider->setMaximum(24);//高度最大值
    ui->hhorizontalSlider->setMinimum(9);//高度最小值
    ui->hhorizontalSlider->setTracking(true);//打开滑块跟踪
    ui->hhorizontalSlider->setSingleStep(1);//步长为1


    ui->mhorizontalSlider->setMinimum(10);//雷数最大值
    ui->mhorizontalSlider->setTracking(true);//滑块追踪
    ui->mhorizontalSlider->setSingleStep(1);//步长为1

    ui->wspinBox->setMaximum(30);//spinbox的宽度最大值
    ui->wspinBox->setMinimum(9);//宽度最小值
    ui->wspinBox->setSingleStep(1);//点击一次变化1

    ui->hspinBox->setMaximum(24);//高度最大值
    ui->hspinBox->setMinimum(9);//高度最小值
    ui->hspinBox->setSingleStep(1);//点击一次变化1


    ui->mspinBox->setMinimum(10);//雷数最大值
    ui->mspinBox->setSingleStep(1);//雷数最小值
}

Dialog::~Dialog()
{
    delete ui;
}
//让两种设值方式之间互相链接，改变其中一个另一个也会发生变化
void Dialog::on_whorizontalSlider_valueChanged(int value)
{

    ui->wspinBox->setValue(value);
}

void Dialog::on_hhorizontalSlider_valueChanged(int value)
{


    ui->hspinBox->setValue(value);

}

void Dialog::on_mhorizontalSlider_valueChanged(int value)
{
    ui->mhorizontalSlider->setMaximum((ui->hhorizontalSlider->value()-1)*(ui->whorizontalSlider->value()-1));
    ui->mspinBox->setValue(value);
}
void Dialog::on_wspinBox_valueChanged(int value)
{

    ui->whorizontalSlider->setValue(value);
}

void Dialog::on_hspinBox_valueChanged(int value)
{

    ui->hhorizontalSlider->setValue(value);

}

void Dialog::on_mspinBox_valueChanged(int value)
{
    ui->mspinBox->setMaximum((ui->wspinBox->value()-1)*(ui->hspinBox->value()-1));
    ui->mhorizontalSlider->setValue(value);

}

void Dialog::on_cancelButton_clicked()//取消按钮，点击关闭自定义框
{
    this->close();
}

int Dialog::getRow()//取得设定的行数
{
    return ui->hspinBox->value();
}

int Dialog::getCol()//取得设定的列数
{
    return ui->wspinBox->value();
}

int Dialog::getnum()//取得设定的雷数
{
    return ui->mspinBox->value();
}

void Dialog::on_commiteButton_clicked()//确定按钮，点击发出信号，让槽函数接受，并且关闭自定义对话框
{
    emit(getattribute(getRow(),getCol(),getnum()));
    this->close();
}
