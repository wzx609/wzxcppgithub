#include<bits/stdc++.h>
using namespace std;
#define PI 3.14
class shape{
    public:
    virtual float getarea()=0;
    virtual float getperim()=0;
};
class rectangle:public shape{
    private:
    float length;
    float width;
    public:
    rectangle(float a,float b);
    float getarea();
    float getperim();
};
class circle:public shape{
    private:
    float r;
    public:
    circle(float a);
    float getarea();
    float getperim();
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
int main(){
    shape *a;
    rectangle b(3,4);
    circle c(2);
    a=&b;
    cout<<"矩形的面积为："<<a->getarea()<<endl;
    cout<<"矩形的周长为："<<a->getperim()<<endl;
    a=&c;
    cout<<"圆的面积为："<<a->getarea()<<endl;
    cout<<"圆的周长为："<<a->getperim()<<endl;
    return 0;
}