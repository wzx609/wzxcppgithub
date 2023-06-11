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

int main()
{
    vector<int> v(6);
    ostream_iterator<int> output(cout, " ");
    generate(v.begin(), v.end(), SrandNum());
    copy(v.begin(), v.end(), output);
    return 0;
}