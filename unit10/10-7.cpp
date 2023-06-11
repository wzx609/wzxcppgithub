#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int> a;
    a.push(5);
    a.push(1);
    a.push(4);
    a.push(6);
    cout<<a.top()<<" ";
    a.pop();
    cout<<a.top()<<" ";
    a.pop();
    a.push(2);
    a.push(3);
    cout<<a.top()<<" ";
    a.pop();
    cout<<a.top()<<endl;
    a.pop();

    queue<int> b;
    b.push(5);
    b.push(1);
    b.push(4);
    b.push(6);
    cout<<b.front()<<" ";
    b.pop();
    cout<<b.front()<<" ";
    b.pop();
    b.push(2);
    b.push(3);
    cout<<b.front()<<" ";
    b.pop();
    cout<<b.front()<<endl;
    b.pop();

    priority_queue<int> c;
    c.push(5);
    c.push(1);
    c.push(4);
    c.push(6);
    cout<<c.top()<<" ";
    c.pop();
    cout<<c.top()<<" ";
    c.pop();
    c.push(2);
    c.push(3);
    cout<<c.top()<<" ";
    c.pop();
    cout<<c.top()<<endl;
    c.pop();
    return 0;
}
