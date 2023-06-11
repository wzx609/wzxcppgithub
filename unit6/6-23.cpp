#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"请输入8个人的考试成绩: "<<endl;
    double a[8];//定义存放8个整形值的数组
    int i=0;
    double sum=0;//定义sum，存放成绩和
    for(i=0;i<8;i++){//遍历数组，输入成绩
        cin>>a[i];
        sum+=a[i];//输入的同时求和
    }
    double ave=sum/8;//求平均
    cout<<"他们的平均成绩为: "<<ave<<endl;//输出
    return 0;
}