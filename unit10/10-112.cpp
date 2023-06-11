#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {1, 1, 4, 4, 5};   
    list<int> s(arr,arr+5);
    list<int>::iterator iter=unique(s.begin(),s.end());
    s.erase(iter,s.end());
    copy(s.begin(), s.end(), ostream_iterator<int>(cout, "\n"));
    return 0;
}