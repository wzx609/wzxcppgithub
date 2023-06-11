#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string,int> a;
    string word;
    while(cin>>word){
        a[word]++;
    }
    map<string,int>::iterator iter;
    for(iter=a.begin();iter!=a.end();iter++){
        cout<<(*iter).first<<"出现的次数:"<<(*iter).second<<endl;
    }
    return 0;
}