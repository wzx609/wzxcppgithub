#include<bits/stdc++.h>
#include"node.h"
using namespace std;
int main(){
    int item;
    oederlist<int> a;
    oederlist<int> b;
    cout<<"请输入链表a的元素:";
    for(int i=0;i<5;i++){
        cin>>item;
        a.insertRear(item);
    }
    a.reset();
    cout<<"a的元素:";
    for(int i=0;i<5;i++){
        cout<<a.data()<<" ";
        a.next();
    }
    cout<<endl;
    cout<<"请输入链表b的元素:";
    for(int i=0;i<5;i++){
        cin>>item;
        b.insertRear(item);
    }
    b.reset();
    cout<<"b的元素:";
    for(int i=0;i<5;i++){
        cout<<b.data()<<" ";
        b.next();
    }
    cout<<endl;
    a.insert(a,b);
    cout<<"插入后的链表为:";
    a.reset();
     for(int i=0;i<10;i++){
        cout<<a.data()<<" ";
        a.next();
    }
    return 0;

}