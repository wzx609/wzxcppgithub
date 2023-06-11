#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream file("test1.txt");
    char a[100];
    file.getline(a,100);
    cout<<a;
    file.close();
    return 0;
}
