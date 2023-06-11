#include<bits/stdc++.h>
using namespace std;
#define PI 3.14
class shape{
    public:
    virtual void getarea();
};
class rectangle:public shape{
    private:
    float length;
    float width;
    public:
    rectangle(float a,float b);
    virtual  void getarea();
};
class circle:public shape{
    private:
    float r;
    public:
    circle(float a);
   virtual void getarea();
};
void shape::getarea(){
    
}
class square:public rectangle{
    public:
    square(float a);
};
square::square(float a):rectangle(a,a){

}
circle::circle(float a):r(a){

}
rectangle::rectangle(float a,float b):length(a),width(b){

}
void rectangle::getarea(){
    cout<<length*width<<endl;
}
void circle::getarea(){
    cout<<PI*r*r<<endl;
}

int main(){
    shape *s;
    s=new rectangle(3,4);
    cout<<"长方形的面积:";
    s->getarea();
    s=new circle(3);
    cout<<"圆的面积:";
    s->getarea();
    s=new square(3);
    cout<<"正方形的面积:";
    s->getarea();
    return 0;

}