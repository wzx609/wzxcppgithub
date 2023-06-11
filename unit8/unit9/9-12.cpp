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
void selectionSort(T a[], int n)
{
    int i, j;
    int leastIndex;
    for (i = 0; i < n - 1; i++) {
        leastIndex = i;

        for (j = i + 1; j < n; j++)
            if (a[j] < a[leastIndex])
                leastIndex = j;
        mySwap(a[i], a[leastIndex]);
         for(int m=0;m<n;m++){
            cout<<a[m]<<" ";
        }
        cout<<endl;
    }
    }

int main(){
    int data1[20]={1, 3, 5, 7, 9, 11, 13, 15, 17, 19,2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    selectionSort<int>(data1,20);
    return 0;
}