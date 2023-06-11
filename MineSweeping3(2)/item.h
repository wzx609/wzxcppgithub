#ifndef ITEM_H
#define ITEM_H

#include<qpoint.h>

class Item
{
public:
    Item();
    Item(QPoint pos);
    QPoint mpos;
    bool ismine;
    bool isopen;
    bool ismark;
    bool isask;
    int num;
};

#endif // ITEM_H
