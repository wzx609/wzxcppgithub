#include<bits/stdc++.h>
using namespace std;
class mammal{
    public:
    virtual void speak();
};
class dog:public mammal{
    public:
    void speak();
};
void mammal::speak()
{
    cout<<"mammal"<<endl;
}
void dog::speak()
{
    cout<<"dog"<<endl;
}
int main(){
    dog a;
    a.speak();
    return 0;
}