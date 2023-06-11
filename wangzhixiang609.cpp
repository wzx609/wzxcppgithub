#include<bits/stdc++.h>
using namespace std;
class student{
    friend void getsall(student s[5]);
    friend void getsmen(student s[5]);
    friend double ave(student s[]);
    private:
    int id;
    double score;
    string name;
    string gender;
    public:
    student();
    student(int a,double b,string c,string m);
    student(student &obj);
    
};
    student::student(){};
    student::student(int a,double b,string c,string m):id(a),score(b),name(c),gender(m){};
    student::student(student &obj){
        id=obj.id;
        score=obj.score;
        name=obj.name;
        gender=obj.gender;
    }
    void getsall(student s[5]){
        int i,j;
        student a;
        for(i=0;i<5;i++){
            for(j=i;j<5;j++){
                if(s[j].score>s[i].score){
                    a=student(s[j]);
                    s[j]=student(s[i]);
                    s[i]=student(a);
                }          
            }
             cout<<"id is "<<s[i].id<<endl;
                    cout<<"score is "<<s[i].score<<endl;
                    cout<<"name is "<<s[i].name<<endl;
                    cout<<"gender is "<<s[i].gender<<endl;
                    cout<<endl;
        }
    }
       void getsmen(student s[5]){
            int i;
            for(i=0;i<5;i++){
                if(s[i].gender=="man"){
                  cout<<"id is "<<s[i].id<<endl;
                    cout<<"score is "<<s[i].score<<endl;
                    cout<<"name is "<<s[i].name<<endl;
                    cout<<"gender is "<<s[i].gender<<endl; 
                    cout<<endl;
                }
                
            }
       }
       double ave(student s[5]){
        int i;
        double sum=0;
        for(i=0;i<5;i++){
            sum+=s[i].score;
        }
        return sum/5;
       }
    int main(){
        int i,j;
        int a;
        double b;
        string c,d;
        student s[5];
         cout<<"请输入学生信息(一行代表一个学生，各个数据之间用空格隔开)："<<endl;
        for(i=0;i<5;i++){  
            cin>>a>>b>>c>>d;
            s[i]={a,b,c,d};
        }
        cout<<"ALL STUDENT:"<<endl;
             getsall(s);
             cout<<"MAN:"<<endl;
             getsmen(s);
                 cout<<"average is "<<ave(s);
            return 0;
    }