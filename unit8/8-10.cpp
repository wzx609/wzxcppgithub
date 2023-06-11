#include<bits/stdc++.h>
using namespace std;
class point{
    private:
    int x;
    int y;
    public:
    point();
    point(int a,int b);
    ~point();
    int getx()const;
    int gety()const;
    point operator +(const point &obj) const;
};
point::point():x(0),y(0)
{

}
point::point(int a,int b):x(a),y(b)
{

}
point::~point()
{

}
int point::getx()const
{
    return x;
}
int point::gety()const
{
    return y;
}
point point::operator +(const point &obj) const
{
    point c;
    c.x=x+obj.x;
    c.y=y+obj.y;
    return c;
}
int main(){
    point a(3,4);
    point b(5,6);
    point c=a+b;
    cout<<"x="<<c.getx()<<endl<<"y="<<c.gety();
    return 0;
}