#include<stdio.h>
#include<string.h>
int main(){
     FILE *in;
     in=fopen("test.txt","r");
     char a[1000];
     while((fgets(a,100,in))!=NULL){
        if(strstr(a,"for")!=NULL){
            printf("This row have for:%s\n",a);
        }
     }
     fclose(in);
     return 0;
}