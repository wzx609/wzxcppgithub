#include<bits/stdc++.h>
using namespace std;
#define PI 3.14
class shape{
    public:
    virtual float getarea()=0;
    virtual float getperim()=0;
    virtual int getvertexcount()=0;
};
class rectangle:public shape{
    private:
    float length;
    float width;
    public:
    rectangle(float a,float b);
    float getarea();
    float getperim();
    int getvertexcount();
};
class circle:public shape{
    private:
    float r;
    public:
    circle(float a);
    float getarea();
    float getperim();
    int getvertexcount();
};
class square:public rectangle{
    public:
    square(int a);

};
circle::circle(float a):r(a)
{

}
rectangle::rectangle(float a,float b):length(a),width(b)
{

}
float  rectangle::getarea(){
    return length*width;
}
float circle::getarea(){
    return PI*r*r;
}
float rectangle::getperim()
{
    return 2*(length+width);
}
float circle::getperim()
{
    return 2*PI*r;
}
square::square(int a):rectangle(a,a)
{

}
int circle::getvertexcount(){
    return 0;
} 
int rectangle::getvertexcount(){
    return 4;
}
int main(){
    shape *a;
    rectangle b(3,4);
    circle c(2);
    square m(4);
    a=&b;
    cout<<"矩形的面积为："<<a->getarea()<<endl;
    cout<<"矩形的周长为："<<a->getperim()<<endl;
    cout<<"矩形的顶点个数为："<<dynamic_cast<rectangle*>(a)->getvertexcount()<<endl;
    a=&c;
    cout<<"圆的面积为："<<a->getarea()<<endl;
    cout<<"圆的周长为："<<a->getperim()<<endl;
    cout<<"圆的顶点个数为："<<dynamic_cast<circle*>(a)->getvertexcount()<<endl;
    a=&m;
    cout<<"正方形的面积为："<<a->getarea()<<endl;
    cout<<"正方形的周长为："<<a->getperim()<<endl;
    cout<<"正方形的顶点个数为："<<dynamic_cast<square*>(a)->getvertexcount()<<endl;
    return 0;
}