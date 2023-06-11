#include<bits/stdc++.h>
using namespace std;
class object{
    private:
    int weight;
    public:
    object(){}
    object(int a);
    ~object();
};
class box:public object{
    private:
    int height;
    int width;
    public:
    box(){}
    box(int c,int a,int b);
    ~box();
};
object::object(int a):weight(a){
    cout<<"construct object"<<endl;

}
box::box(int c,int a,int b):object(c),height(a),width(b){
    cout<<"construct box"<<endl;
}
object::~object(){
    cout<<"deconstruct object"<<endl;
}
box::~box(){
    cout<<"deconstruct box"<<endl;
}
int main(){
    box s(1,2,3);//创建对象，观察顺序
    return 0;
}
