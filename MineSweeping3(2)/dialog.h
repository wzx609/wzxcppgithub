#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    int getRow();
    int getCol();
    int getnum();


private slots:
    void on_whorizontalSlider_valueChanged(int value);

      void on_hhorizontalSlider_valueChanged(int value);

      void on_mhorizontalSlider_valueChanged(int value);

      void on_wspinBox_valueChanged(int arg1);

      void on_hspinBox_valueChanged(int arg1);

      void on_mspinBox_valueChanged(int arg1);


      void on_cancelButton_clicked();

      void on_commiteButton_clicked();
signals:
      void getattribute(int,int,int);
private:
    Ui::Dialog *ui;
    QApplication* a;
};

#endif // DIALOG_H
