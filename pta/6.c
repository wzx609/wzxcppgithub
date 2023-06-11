#include<stdio.h>
int main(){
    FILE *in;
    in=fopen("int_Data.dat","r+");
    int a;
    int sum=0;
    while((fscanf(in,"%d",&a))!=EOF){
        sum+=a;
    }
    fprintf(in,"\n%d",sum);
    fclose(in);
    return 0;
}