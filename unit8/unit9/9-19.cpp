#include<bits/stdc++.h>
using namespace std;
template<class T>
int binSearch(const T list[], int n, const T& key)
{
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (key == list[mid])
            return mid;
        else if (key < list[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
template<class T>
void mySwap(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}
template<class T>
void bubbleSort(T a[], int n)
{
    int i, j;
    int lastExchangeIndex;
    i = n - 1;
    while (i > 0) {
        lastExchangeIndex = 0;
        for (j = 0; j < i; j++)
            if (a[j + 1] < a[j]) {
                mySwap(a[j], a[j + 1]);
                lastExchangeIndex = j;
            }
        i = lastExchangeIndex;
    }
}
int main(){
    int data1[20]={1, 3, 5, 7, 9, 11, 13, 15, 17, 19,2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    bubbleSort<int>(data1,20);
    int key;
    cout<<"请输入数字:";
    cin>>key;
    cout<<binSearch(data1,20,key);
    return 0;
}