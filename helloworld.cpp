#include<iostream>
#include<boost/format.hpp>
using namespace std;
int main()
{
    //目前编译器暂不支持C++20的format，这里使用boost::format
    cout<<boost::format("There are %d ways I love you.") % 214<<endl;

    return 0;
}
