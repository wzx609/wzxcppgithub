#include<bits/stdc++.h>
using namespace std;
#define PI 3.14//宏定义pi的值为3.14
class simplecircle{
    private:
    int *itsradius=new int(0);//定义一个指向圆半径的指针，分配一个int类型的内存空间，存入0，并将其地址赋给指针
    public:
    simplecircle();//不带参数的构造函数
    simplecircle(int a);//带参构造函数
    double C();//输出圆的周长
    double S();//输出圆的面积
    int getradius();//输出圆的半径
};
simplecircle::simplecircle(){//不带参的构造函数
    *itsradius=0;
};
simplecircle::simplecircle(int a){//带参构造函数，给指针指向的位置存入一个半径值
    *itsradius=a;
}
double simplecircle::C(){//计算周长
    return 2*PI*(*itsradius);
}
double simplecircle::S(){//计算面积
    return PI*(*itsradius)*(*itsradius);
}
int simplecircle::getradius(){//输出半径
    return *itsradius;
}
int main(){
    simplecircle circle(5);//定义一个对象，半径赋值为5
    cout<<"半径为: "<<circle.getradius()<<endl;//输出半径
    cout<<"周长为: "<<circle.C()<<endl;//输出周长
    cout<<"面积为: "<<circle.S()<<endl;//输出面积
    return 0;
}