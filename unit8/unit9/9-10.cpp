#include<bits/stdc++.h>
using namespace std;
template<class T>
void insertionSort(T a[], int n)
{
    int i, j;
    T temp;
    for (i = 1; i < n; i++) {
        j = i;
        temp = a[i];
        while (j > 0 && temp < a[j - 1]) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = temp;
        for(int m=0;m<n;m++){
            cout<<a[m]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int data1[20]={1, 3, 5, 7, 9, 11, 13, 15, 17, 19,2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    insertionSort<int>(data1,20);
    return 0;
}