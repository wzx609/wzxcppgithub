#include<bits/stdc++.h>
using namespace std;

const int M=5;
const int N=100;

template<class T>
T Josephus(vector<T>& a, int m)
{
    int c=-1;
    while(a.size()>1)
    {
        c=(c+m)%a.size();
        cout<<a[c]<<", ";
        a.erase(a.begin()+c);
        c--;
    }
    cout<<endl;
    return a[0];
}

template<class T>
T Josephus(queue<T>& a, int m)
{
    int c=1;
    while(a.size()>1)
    {
        if(m!=c)
        {
            c++;
            a.push(a.front()); 
            a.pop();
        }
        else
        {
            cout<<a.front()<<", ";
            a.pop();
            c = 1;
        }
    }
    cout<<endl;
    return a.front();
}

template <class T>
T Josephus(list<T>& a, int m)
{
    int c=0;
    typename list<T>::iterator it, now;
    it=a.begin();
    while(a.size()>1)
    {
        c++;
        now = it;
        if(++it==a.end())
            it = a.begin();
        if(m==c)
        {
            cout<<*now<<", ";
            a.erase(now);
            c=0;
        }
    }
    cout<<endl;
    return a.front();
}

int main()
{
    int i;
    int last;
    
    vector<int> v1;
    for(i=0; i<N; i++)
        v1.push_back(i);

    last = Josephus(v1, M);
    cout<<"The last num is "<<last<<endl;

    queue<int> v2;
    for(i=0; i<N; i++)
        v2.push(i);

    last = Josephus(v2, M);
    cout<<"The last num is "<<last<<endl;

    list<int> v3;
    for(i=0; i<N; i++)
        v3.push_back(i);

    last = Josephus(v3, M);
    cout<<"The last num is "<<last<<endl;

    return 0;
}