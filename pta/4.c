#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *in;
    float a;
    in=fopen("data2.txt","w");
    scanf("%f",&a);
    while(a!=EOF){
        fprintf(in,"%f\n",a);
        scanf("%f",&a);
    }
    fclose(in);
    return 0;
}