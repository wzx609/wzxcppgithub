#include<bits/stdc++.h>
using namespace std;
template<class T>
void dequeue(vector<T> &b,class vector<T>::iterator a,int m){
    int c=1;
    while(b.size()!=1){
        if(a==b.end()){
            a=b.begin();
        }
        if(c!=m){
            a++;
            c++;
            continue;
        }
        else{
            cout<<*a<<" "; 
            b.erase(a);
            c=1;
            continue;
        }
    }
}
int main(){
    vector<int>::iterator b;
    vector<int> a;
    int n;
    cout<<"请输入n:";
    cin>>n;
    for(int i=1;i<=n;i++){
        a.push_back(i);
    }
    b=a.begin();
    int m;
    cout<<"请输入m:";
    cin>>m;
    dequeue(a,b,m);
    b=a.begin();
    cout<<endl;
    cout<<"留下的骑士的编号为:"<<*b;
    return 0;
}