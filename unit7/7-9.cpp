#include<bits/stdc++.h>
using namespace std;
class base{
    public:
    void fn1();
    void fn2();
};
class derived:private base{
    public:
    void fn1();
};
void base::fn1(){
    cout<<"fn1"<<endl;
}
void base::fn2(){
    cout<<"fn2"<<endl;
}
void derived::fn1(){//使用derived类的函数fn1调用base类的fn1
    base::fn1();
}
int main(){
    derived s;
    s.fn1();
    return 0;
}