#include<bits/stdc++.h>
using namespace std;
int main(){
    ofstream file1("test1.txt",ios_base::app);
    file1<<"已成功添加字符!";
    file1.close();
    ifstream file2("test1.txt");
    char a[100];
    file2.getline(a,100);
    cout<<a;
    file2.close();
    return 0;
}