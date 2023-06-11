#include<bits/stdc++.h>
using namespace std;
int Row;
int Col;
int Num;
vector<vector<int>> a;
void show(){
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            if(a[i][j]>=9&&a[i][j]<=18)
            cout<<"*"<<"\t";
            if(a[i][j]>=-1&&a[i][j]<=8)
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void gameinit(){
    srand((unsigned)time(NULL));
    a.resize(Row);
    //全部默认为0
    for(int i=0;i<Row;i++){
        a[i].resize(Col,0);
    }
    //设置雷 -1
    for(int i=0;i<Num;){
        int m=rand()%Row;
        int n=rand()%Col;
        if(a[m][n]!=-1){
            a[m][n]=-1;
            i++;
        }
    }
    //雷周围格数值加1
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            if(a[i][j]==-1){
                for(int m=i-1;m<=i+1;m++){
                    for(int n=j-1;n<=j+1;n++){
                        if(m>=0&&m<Row&&n>=0&&n<Col&&a[m][n]!=-1)
                          a[m][n]++;
                    }
                }
            }
        }
    }
    //加密
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
           if(a[i][j]>=-1&&a[i][j]<=8)
             a[i][j]+=10;  
        }
    }
}
    //0递归翻开
void openNULL(int x,int y){
    if(a[x][y]==0){
        for(int m=x-1;m<=x+1;m++){
            for(int n=y-1;n<=y+1;n++){
                if(m>=0&&m<Row&&n>=0&&n<Col&&a[m][n]>=9){
                    a[m][n]-=10;
                    openNULL(m,n);
                }
                }
            }
        }
}
//点开
void open(int x,int y){
    if(a[x][y]>=9)
    a[x][y]-=10;
    openNULL(x,y);
}
//游戏状态
void gamestate(){
    int count=0;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            if(a[i][j]>=0&&a[i][j]<=8)
              count++;
               if(a[i][j]==-1){
             cout<<"你踩到了雷！"<<endl;
        for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            if(a[i][j]>=9&&a[i][j]<=18)
            a[i][j]-=10;
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
        exit(0);
        }
        }
    }
    if(count==Row*Col-Num){
    cout<<"通关！"<<endl;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            if(a[i][j]>=9&&a[i][j]<=18)
            a[i][j]-=10;
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    exit(0);
    }
}

int main(){
    cout<<"请输入行数:";
    cin>>Row;
    cout<<"请输入列数:";
    cin>>Col;
    cout<<"请输入雷的数量:";
    cin>>Num;
    gameinit();
    while(true){
        int x,y;
        show();
        cout<<"请输入坐标:";
        cin>>x>>y;
        open(x-1,y-1);
        gamestate();
    }
    
    return 0;
}