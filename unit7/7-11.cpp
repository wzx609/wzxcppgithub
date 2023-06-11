#include<bits/stdc++.h>
using namespace std;
class baseclass{
    public:
    void fn1();
    void fn2();
};
class derivedclass:public baseclass{
    public:
    void fn1();
    void fn2();
};
void baseclass::fn1(){
    cout<<"baseclass fn1"<<endl;
}
void baseclass::fn2(){
    cout<<"baseclass fn2"<<endl;
}
void derivedclass::fn1(){
    cout<<"derivedclass fn1"<<endl;
}
void derivedclass::fn2(){
    cout<<"derivedclass fn2"<<endl;
}
int main(){
    derivedclass s;//derivedclass类对象s
    baseclass n;//baseclass类对象n
    derivedclass *a;//指向derivedclass类的指针a
    a=&s;
    baseclass *b;//指向baseclass类的指针b
    b=&n;
    s.fn1();
    s.fn2();
    a->fn1();
    a->fn2();
    b->fn1();
    b->fn2();
    return 0;
}