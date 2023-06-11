#include<bits/stdc++.h>
using namespace std;
int main(){
    array<int,10> a;
    array<int,10> b;
    for(int i=0;i<10;i++){
        cin>>a[i];
    }
    for(int i=0;i<10;i++){
        cin>>b[i];
    }
    cout<<"oringin:"<<endl;
    cout<<"a:";
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"b:";
    for(int i=0;i<10;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    array<int,10>::iterator it1,it2;
    for(it1=a.begin(),it2=b.begin();it1!=a.end(),it2!=b.end();it1++,it2++){
        iter_swap(it1,it2);
    }
    cout<<"iter_swap exchange:"<<endl;
    cout<<"a:"<<endl;
    copy(a.begin(),a.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
    cout<<"b:"<<endl;
    copy(b.begin(),b.end(),ostream_iterator<int>(cout," "));
    return 0;
}