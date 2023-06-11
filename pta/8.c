#include<stdio.h>
#include<string.h>
int main(){
    FILE *in,*a;
    in=fopen("hello.c","r+");
    a=fopen("new_hello.c","w");
    char b;
    int found=0;
    b=getc(in);
    while(b!=EOF){
        if(b!='/'){
            putc(b,a);
        }
        if(b=='/'){
            b=getc(in);
            if(b=='/'){
                found=1;
                b=getc(in);
                while(b!='\n'&&b!=EOF){
                    b=getc(in);
                }
                
                }
            else if(b=='*'){
                    b=getc(in);
                    while(b!='*'){
                        b=getc(in);
                    }
                    while(b=='*'){
                        b=getc(in);
                        if(b=='/')
                        break;
                        else{
                        b='*';
                        continue;
                        }
                    }
            }
            else{
                putc('/',a);
                putc(b,a);
            }
        }
        if(b=='\n'&&found==1)
        putc(b,a);
        found=0;
        b=getc(in);
    }
    printf("处理结束");
    fclose(in);
    fclose(a);
    return 0;
}
