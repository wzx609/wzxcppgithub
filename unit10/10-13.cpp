#include<bits/stdc++.h>
using namespace std;

class SrandNum{
private:
    int x;
public:
    SrandNum();
    int operator()();
};

SrandNum::SrandNum()
:x(0)
{

}

int SrandNum::operator()()
{
    static unsigned int seq;
    srand((unsigned)time(NULL)+(++seq));
    return rand()%10;
}

template<class T>
class A:public binary_function<T, T, T>
{
public:
    T operator()(T x, T y) const
    {
        return pow(x, y);
    }
};

template<class T>
class B:public unary_function<T, T>
{
public:
    T operator()(T x) const
    {
        return pow(x, x);
    }
};

int main()
{
    vector<int> v(6);
    vector<int>::iterator it;
    ostream_iterator<int> output(cout, " ");
    generate(v.begin(), v.end(), SrandNum());
    copy(v.begin(), v.end(), output);
    cout<<endl;

    transform(v.begin(), v.end(), output, bind1st(A<int>(), 5));
    cout<<endl;

    transform(v.begin(), v.end(), output, bind2nd(A<int>(), 7));
    cout<<endl;

    transform(v.begin(), v.end(), output, B<int>());
    cout<<endl;

    return 0;
}