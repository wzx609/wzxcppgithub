#include<bits/stdc++.h>
using namespace std;
template<class T>
void exchange(list<T>& l1, class list<T>::iterator p1, list<T>& l2, class list<T>::iterator p2){
    list<T> a;
    list<T> b;
    l1.splice(a.end(),l1,p1,l1.end());
    l2.splice(b.end(),l2,p2,l2.end());
    b.splice(l1.end(),b,b.begin(),b.end());
    a.splice(l2.end(),a,a.begin(),a.end());
}
int main(){
    list<int> l1;
    list<int> l2;
    l1.assign(7,6);
    l2.assign(8,5);
    copy(l1.begin(),l1.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
    copy(l2.begin(),l2.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
    list<int>::iterator p1=l1.begin();
    list<int>::iterator p2=l2.begin();
    p1++;
    exchange(l1,p1,l2,p2);
    copy(l1.begin(),l1.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
    copy(l2.begin(),l2.end(),ostream_iterator<int>(cout," "));
    return 0;
}