#include<iostream>
using namespace std;
void fn1(){//定义函数fn1，作用是让n加1，同时输出此时n的值
    static int n;//定义静态变量n，默认赋值为0
    n+=1;
     cout<<"n="<<n<<endl;
}
int main(){
    int i=0;
    for(i=0;i<10;i++){//循环调用fn1函数10次
        fn1();
    }
   
    return 0;
}
