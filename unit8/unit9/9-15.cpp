#include<bits/stdc++.h>
using namespace std;
template<class T>
void mySwap(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}
template<class T>
void bubbleSort(T a[], int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(a[j]>a[i])
            mySwap(a[i],a[j]);
        }
        for(int m=0;m<n;m++){
            cout<<a[m]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int data1[20]={1, 3, 5, 7, 9, 11, 13, 15, 17, 19,2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    bubbleSort<int>(data1,20);
    return 0;
}