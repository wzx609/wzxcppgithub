#include<stdio.h>
/*main函数*/
int main(void)
{
    int i,sum=0;    //定义变量i和sum
    for(i=1;i<=10;i++)     //循环从i到10
    sum+=i;   //累加
    printf("sum:%d\n",sum);    //打印
    return 0;
}