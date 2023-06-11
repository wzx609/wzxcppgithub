#include "list.h"
#include "ui_list.h"

#include<qfile.h>

Help::Help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::List)
{
    ui->setupUi(this);
    this->setWindowTitle("扫雷规则");//将窗口标题设为“扫雷规则”
}

Help::~Help()
{
    delete ui;//析构函数
}
