#include<iostream>
using namespace std;
class cat//定义cat类
{
    private://私有成员，外部无法直接访问
    int a;
    static int numofcats;//定义静态变量numofcats，用来记录创建cat类的个数，由于其归该类所有成员所共有，所以可以用来记录对象个数
    public://外部接口，可以通过这里访问类内的私有成员
    cat();//无参数的构造函数，默认初始化为0
    cat(int m);//带参构造函数，用于初始化
    static void getnumofcats();//定义静态函数getnumofcats用来输出此时numofcats的大小，由于静态成员函数归该类所有对象所共有，所以可以用来输出此时创建所有对象的个数
};
cat::cat():a(0){
    numofcats++;//创建一个类，同时让numofcats加1
}
cat::cat(int m):a(m){
    numofcats++;//创建一个类，同时让numofcats加1
}
void cat::getnumofcats(){//用来输出对象的个数
    cout<<"count="<<numofcats<<endl;
};
int cat::numofcats=0;//静态成员初始化
int main(){
    cat a(4);//创建一个cat类的对象a
    cat::getnumofcats();//输出此时的numofcats的值
    cat b(5);//创建一个b类
    cat::getnumofcats();//输出此时numofcats的值
    return 0;
}
