#include<bits/stdc++.h>
using namespace std;
int main(){
    set<string> b;
    multiset<string> a;
    string word;
    cout<<"请输入单词(ctrl+z停止):"<<endl;
    while(cin>>word){
        b.insert(word);
        a.insert(word);
    }
    multiset<string>::iterator iter=b.begin();
    for(iter=b.begin();iter!=b.end();iter++){
        cout<<*iter<<"出现次数:"<<a.count(*iter)<<endl;
    }
    return 0;
}