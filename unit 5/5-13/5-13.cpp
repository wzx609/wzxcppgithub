#include"x.h"//将编写好的类与函数包含进来
#include<iostream>
using namespace std;
int main(){
    x q;//定义x类对象q
    y m;//定义y类对象m
    z n;//定义z类对象n
    cout<<"i="<<q.s()<<endl;//调用s（）函数输出此时i的值
    m.g(&q);//调用g（x*f）函数，传入此时q对象的地址，实现i+1
    cout<<"i="<<q.s()<<endl;//输出此时i的值
    n.f(&q);//调用f（x*p）函数，传入q地址，实现对i+5
    cout<<"i="<<q.s()<<endl;//输出此时i的值
    h(&q);//调用函数h（x*f），实现对i+10
    cout<<"i="<<q.s()<<endl;//输出此时i的值
    return 0;
}