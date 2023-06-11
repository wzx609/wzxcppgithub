#include<bits/stdc++.h>
using namespace std;
class document{
    private:
    string name;
    public:
    document();
    document(string a);
    void putsname();
};

class book:public document{//派生类
    private:
    int pagecount;//增加数据成员
    public:
    book();
    book(string b,int a);
    int putspage();
};
document::document(){}
document::document(string a):name(a){

}
book::book(){}
book::book(string b,int a):document(b),pagecount(a){

}
void document::putsname(){
    cout<<name;
}
int book::putspage(){
    return pagecount;
}
int main(){
    book s("name",66);
    s.putsname();
    cout<<endl;
    cout<<s.putspage();
    return 0;
}