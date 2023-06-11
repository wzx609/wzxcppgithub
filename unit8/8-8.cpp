#include<bits/stdc++.h>
using namespace std;
class baseclass{
    public:
    virtual void fn1();
    void fn2();
};
class derivedclass:public baseclass{
    public:
    void fn1();
    void fn2();
};
void baseclass::fn1(){
    cout<<"baseclass fn1()"<<endl;
}
void baseclass::fn2(){
    cout<<"baseclass fn2()"<<endl;
}
void derivedclass::fn1(){
    cout<<"derivedclass fn1()"<<endl;
}
void derivedclass::fn2(){
    cout<<"derivedclass fn2()"<<endl;
}
int main(){
    derivedclass a;
    baseclass *b;
    derivedclass *c;
    b=&a;
    c=&a;
    b->fn1();
    b->fn2();
    c->fn1();
    c->fn2();
    return 0;
}