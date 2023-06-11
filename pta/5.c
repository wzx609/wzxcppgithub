#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *a,*b;
    a=fopen("data3_1.txt","r");
    b=fopen("data3_2.txt","r");
    char c1,c2;
    int line=1,list=0;
    while(1){//回车算第二行
        list++;
        c1=getc(a);
        c2=getc(b);
        if(c2==EOF){
            printf("data_2 文件已经达到末尾");
            break;
        }
         if(c1==EOF){
            printf("data_1 文件已经达到末尾");
            break;
        }
        if(c1==c2&&c1=='\n'){
            line++;
            list=1;
            printf("读到字符: \n");
            printf("\n");
        }
        if(c1==c2&&c1!='\n')
            printf("读到字符:%c\n",c1);    
        if(c1!=c2){
            if(c1=='\n'&&c2!='\n'){
            printf("data3_1 行号：%d 列号：%d\n",line+1,1);
            printf("data3_2 行号：%d 列号：%d\n",line,list); 
            break;
            }
            if(c1!='\n'&&c2=='\n'){
            printf("data3_1 行号：%d 列号：%d\n",line,list);
            printf("data3_2 行号：%d 列号：%d\n",line+1,1); 
            break;
            }
            else{
            printf("data3_1 行号：%d 列号：%d\n",line,list);
            printf("data3_2 行号：%d 列号：%d\n",line,list);
            break;
            }
        }
    }
    return 0;
}