#include<bits/stdc++.h>
#include"Array.h"
using namespace std;
int main(){
    int n;
    double sum=0;
    cout<<"请输入学生个数:";
    cin>>n;
    Array<double> a(n);
    cout<<"请输入"<<n<<"位学生的成绩:";
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    double av=sum/n;
    cout<<"平均成绩为:"<<av;
    return 0;
    
}