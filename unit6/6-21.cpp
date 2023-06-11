#include<bits/stdc++.h>
using namespace std;
int count(char *a);//声明一个计算字母个数的函数
int main(){
    char a[1000];//定义一个字符型数组
    gets(a);//输入字符串
    cout<<"英语字母个数为: "<<count(a)<<endl;
    return 0;
}
int count(char *a){
     int length(0);//定义一个整形变量，用于存放字母个数
      for(a;*a!='\0';a++){//遍历字符串
        if((*a>=65&&*a<=90)||(*a>=97&&*a<=122)){//当其为a-z或A-Z时，length加1
            length++;
        }
       
    }
    return length;//返回length值，即字母个数
}