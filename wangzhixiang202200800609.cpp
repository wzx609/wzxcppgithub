/*
创建一个矩形类，矩形的边平行于坐标轴。矩形的属性用其左下角坐标、长度和宽度描述。
(1) 从键盘输入两个矩形参数（注意输入提示信息），创建两个矩形对象，
     判断两个矩形是否相交？求出相交部分的面积。
(2) 从键盘再输入或随机产生3个矩形对象，对输入的所有5个矩形按面积由小到大排序，
     然后依次显示各个矩形的左下角坐标、长、宽、面积。
*/

/*
注意：请用姓名全拼音加学号命名源文件，如Zhanglei202200800123.cpp
然后将文件发送到邮箱46432248@qq.com
文件命名错误将扣分，无法确定发送人视为0分。切记！
*/
#include<bits/stdc++.h>
using namespace std;
class retangle{
    private:
    double x;
    double y;
    double length;
    double width;
    public:
    retangle();
    retangle(double m,double n,double a,double b);
    ~retangle(){};
    double getarea();
    double getlength();
    double getwidth();
    double getx();
    double gety();
    bool intersect(retangle& a);
    double intersectarea(retangle& a);
};
retangle::retangle():x(0),y(0),length(0),width(0)
{

}
retangle::retangle(double m,double n,double a,double b):x(m),y(n),length(a),width(b)
{

}
double retangle::getarea()
{
    return length*width;
}
double retangle::getlength()
{
    return length;
}
double retangle::getwidth()
{
    return width;
}
double retangle::getx()
{
    return x;
}
double retangle::gety()
{
    return y;
}
bool retangle::intersect(retangle& a)
{
    double ax=abs((x+length/2)-(a.getx()+a.getlength()/2));
    double ay=abs((y+width/2)-(a.gety()+a.getwidth()/2));
    if(ax<(abs(x)+abs(a.getx()))/2&&ay<(abs(y)+abs(a.gety()))/2){
        return true;
    }
    else
    return false;
}
double retangle::intersectarea(retangle& a)
{
    return (length+a.getlength()-abs(x-a.getx()))*(width+a.getwidth()-abs(y-a.gety()));
}
int main(){
    double m,n,length,width;
    cout<<"请输入矩形属性(分别为x,y,长度length,宽度width):";
    cin>>m>>n>>length>>width;
    retangle a(m,n,length,width);
    cout<<"请输入矩形属性(分别为x,y,长度length,宽度width):";
    cin>>m>>n>>length>>width;
    retangle b(m,n,length,width);
    bool x=a.intersect(b);
    if(x){
        cout<<"矩形相交"<<endl;
        cout<<"相交面积为:"<<a.intersectarea(b)<<endl;        
    }
    else
    cout<<"矩形不相交"<<endl;
    cout<<"请输入矩形属性(分别为x,y,长度length,宽度width):";
     cin>>m>>n>>length>>width;
    retangle c(m,n,length,width);
    cout<<"请输入矩形属性(分别为x,y,长度length,宽度width):";
     cin>>m>>n>>length>>width;
    retangle d(m,n,length,width);
    cout<<"请输入矩形属性(分别为x,y,长度length,宽度width):";
     cin>>m>>n>>length>>width;
    retangle e(m,n,length,width);
    vector<retangle> q(5);
    q[0]=a;
    q[1]=b;
    q[2]=c;
    q[3]=d;
    q[4]=e;
    for(int i=0;i<5;i++){
        for(int j=i;j<5;j++){
            if(q[i].getarea()>q[j].getarea()){
                  retangle p;
                  p=q[j];
                  q[j]=q[i];
                  q[i]=p;
            }
        }
    }
    for(int i=0;i<5;i++){
        cout<<"x:"<<q[i].getx()<<" "<<"y:"<<q[i].gety()<<" "<<"面积:"<<q[i].getarea()<<" "<<"长度:"<<q[i].getlength()<<" "<<"宽度:"<<q[i].getwidth()<<endl;
    }

    return 0;
}