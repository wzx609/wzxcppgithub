#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
    FILE *in;
    in=fopen("data1.txt","r");
    char ch;
    ch=getc(in);
    int zm=0;
    int num=0;
    int el=0;
    while(ch!=EOF){
        if((ch>=65&&ch<=90)||(ch>=97&&ch<=122)){
            zm++;
        }
        else if(ch>=48&&ch<=57){
            num++;
        }
        else
        el++;
        ch=getc(in);
    }
    printf("字母:%d,",zm);
    printf("数字:%d,",num);
    printf("其他:%d",el);
    return 0;

}