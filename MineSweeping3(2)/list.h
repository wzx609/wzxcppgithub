#ifndef LIST_H
#define LIST_H

#include <QDialog>

namespace Ui {
class List;
}

class Help : public QDialog
{
    Q_OBJECT

public:
    explicit Help(QWidget *parent = nullptr);
    ~Help();

private:
    Ui::List *ui;
};

#endif // LIST_H
