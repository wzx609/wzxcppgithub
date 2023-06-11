#include<bits/stdc++.h>
using namespace std;
class employee{//定义employee类
    private://私有成员
    string name;//定义字符串name，代表姓名
    string address;//地址
    string city;//城市
    string pc;//邮编
    public://外部接口
    employee();//不带参数的构造函数
    employee(string a,string b,string c,string d);//带参数的构造函数
    void display();//用于输出姓名、地址、城市、邮编的值
    void setname(string a);//用于修改姓名
};
 employee::employee(){};
 employee:: employee(string a,string b,string c,string d):name(a),address(b),city(c),pc(d){//带参数的构造函数，用于对字符串赋初值
   
 }
 void employee::display(){ //输出4个字符串的值
    cout<<"姓名: "<<name<<endl;
    cout<<"地址: "<<address<<endl;
    cout<<"城市: "<<city<<endl;
    cout<<"邮编: "<<pc<<endl;
 }
 void employee::setname(string a){//用于修改name的值
    name=a;
 }
int main(){
    employee e("张三","山东大学","威海","1000");//定义一个名为e的对象
    e.display();//输出值
    e.setname("李四");//修改姓名成员
    cout<<endl;
    e.display();//再次输出
}