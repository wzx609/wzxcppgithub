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
    a.swap(b);
    cout<<"swap exchange:"<<endl;
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

    
    return 0;
}