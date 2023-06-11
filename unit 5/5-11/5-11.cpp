#include"fn1.h"//将另一个编辑好的函数文件包含进来
#include<iostream>
using namespace std;
void fn1();//提前声明函数fn1
int n;//在主函数前定义全局变量n，默认同时也为外部变量
int main(){
    n=1;//在main中对n赋值
    fn1();//调用fn1函数，对n赋值
    cout<<"n="<<n<<endl;//输出此时n的值
    return 0;
}