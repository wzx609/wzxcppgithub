#include<iostream>
using namespace std;
class boat;//提前声明boat类
class car;//提前声明car类
int gettotalweight(boat& b,car& c);//声明gettotalweight函数，该函数传入boat类对象b，与car类对象c的地址
class boat{//定义boat类
    friend int gettotalweight(boat&b,car&c);//声明函数gettotalweight为boat类的友元函数
    private:
    int weight;//定义私有成员weight
    public:
    boat();//不带参数的构造函数
    boat(int a);//带参数的构造函数，用于初始化
};
class car{//定义car类
   friend int gettotalweight(boat&b,car&c);//声明函数gettotalweight为car类的友元函数
    private:
    int weight;//定义私有成员weight
    public:
    car();//默认构造函数
    car(int a);//带参构造函数
};
boat::boat():weight(0){};//默认初始化为0
boat::boat(int a){//实现带参函数，对weight初始化
    weight=a;
};
car::car():car(0){};//默认初始化为0
car::car(int a){//实现带参函数，对weight初始化
    weight=a;
};
int gettotalweight(boat& b,car& c){//定义返回值为整形的函数gettotalweight，传入两个对象的地址，用于将二者weight相加，b，c代表对象名
    
    return b.weight+c.weight;//友元函数，直接通过对象名调用私有成员
    
}
int main(){
    boat b(89);//定义boat类对象b，初始化为89
    car c(76);//定义car类对象c，初始化为76
    int sum;//定义sum，代表两者重量之和
    cout<<"sum="<<gettotalweight(b,c)<<endl;//输出sum
    return 0;
}