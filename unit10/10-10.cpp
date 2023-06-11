#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> a;
    set<int> b;
    int num;
    cin>>num;
    while(num!=EOF){    
        a.insert(num);
        cin>>num;
    }
    cin>>num;
    while(num!=EOF){
        b.insert(num);
        cin>>num;
    }
    set<int> c;
    set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.begin()));
    cout<<"交集:";
    copy(c.begin(),c.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
    set<int> m;
    set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(m,m.begin()));
    cout<<"并集:";
    copy(m.begin(),m.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
    set<int> n;
    set_difference(a.begin(),a.end(),b.begin(),b.end(),inserter(n,n.begin()));
    cout<<"差集:";
    copy(n.begin(),n.end(),ostream_iterator<int>(cout," "));
    return 0;
}