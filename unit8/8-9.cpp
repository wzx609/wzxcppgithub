#include<bits/stdc++.h>
using namespace std;
class baseclass{
    public:
    virtual ~baseclass(){
        cout<<"deconstruct baseclass"<<endl;
    }
};
class derivedclass:public baseclass{
    ~derivedclass(){
        cout<<"deconstruct derivedclass"<<endl;
    }
};
int main(){
    baseclass *a=new derivedclass;
    a->~baseclass();
    return 0;
}