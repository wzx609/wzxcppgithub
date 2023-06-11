#include<bits/stdc++.h>
using namespace std;
template<class T>
int seqSearch(const T list[], int n, const T& key)
{
    int i;
    for (i = 0; i < n; i++)
        if (list[i] == key)
            return i;
    return -1;
}
int main(){
    int data1[20]={1, 3, 5, 7, 9, 11, 13, 15, 17, 19,2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int key;
    cout<<"请输入一个数字:";
    cin>>key;
    cout<<seqSearch<int>(data1,20,key);
    return 0;
}