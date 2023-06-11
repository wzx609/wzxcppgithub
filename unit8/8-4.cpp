#include<bits/stdc++.h>
using namespace std;
class counter{
    private:
    int number;
    public:
    counter();
    counter(int a);
    counter operator +(const counter &obj) const;  
    int getnum() const;
};
counter::counter():number(0)
{

}
counter::counter(int a):number(a)
{

}
counter counter::operator +(const counter &a) const
{
    counter b;
    b.number=number+a.number;
    return b;
}
int counter::getnum() const
{
    return number;
}
int main()
{
    counter a(3);
    counter b(2);
    counter c;
    c=a+b;
    cout<<"a+b="<<c.getnum()<<endl;
    return 0;
}