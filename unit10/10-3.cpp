#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> s(5);
    int c=0;
    while(c!=EOF){
        s.push_back(c);
        cout<<"s.capacity="<<s.capacity()<<endl;
        cin>>c;
    }
    return 0;
}