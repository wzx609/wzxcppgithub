#include<bits/stdc++.h>
using namespace std;
void x(int *a,int *b,int n,int m);//声明转置函数
int main(){
    int n,m;
    cout<<"请输入行数: ";
    cin>>n;
    cout<<"请输入列数: ";
    cin>>m;
    int *a=new int[m*n];//动态创建一维数组a
    int *b=new int[m*n];//动态创建一维数组b
    x(a,b,n,m);
    return 0;
}
void x(int *a,int *b,int n,int m){
     int i,j;             
	for(i=0;i<n;i++){	
		for(j=0;j<m;j++)			
			cin>>a[i*m+j];//给数组a赋值
		}
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			b[i*n+j]=a[i+m*j]; //根据转置规则对b赋值
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)//输出b
			cout<<b[i*n+j]<<' ';
			cout<<endl;
		}
}