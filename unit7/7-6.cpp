#include<bits/stdc++.h>
using namespace std;
class mammal{
    public:
    ~mammal();
    mammal();
};
class dog:public mammal{
    private:
    string name;
    public:
    ~dog();
    dog();
    dog(string a);
};
mammal::mammal(){
    cout<<"constructing mammal"<<endl;
}
dog::dog(){
    cout<<"constructing dog"<<endl;
}
dog::dog(string a):mammal(),name(a){
    cout<<"constructing dog"<<endl;
}
mammal::~mammal(){
    cout<<"destructing mammal"<<endl;
}
dog::~dog(){
    cout<<"destructing dog"<<endl;
}
int main(){
    dog s("Tom");//创建对象，观察顺序
    return 0;
}