#include<QPoint>
#include"item.h"
Item::Item()
{
    mpos=QPoint(0,0);
    isopen=false;//初始化所有格子未打开
    ismine=false;//初始话所有格子不为雷
    ismark=false;//初始化所有格子没有被标记
    isask=false;//初始化所有各自没有被标记问号
    num=0;
}
Item::Item(QPoint pos)
{
    mpos=pos;
    isopen=false;
    ismine=false;
    ismark=false;
    isask=false;
    num=0;
}
