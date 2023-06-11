#include<bits/stdc++.h>
using namespace std;
class Dog{
    private:
    int weight;
    int old;
    public:
    Dog();
    Dog(int a,int b);
    int getold();
    int getweight();
};
Dog::Dog():weight(0),old(0)
{

}
Dog::Dog(int a,int b):weight(a),old(b)
{

}
int Dog::getold()
{
    return old;
}
int Dog::getweight()
{
    return weight;
}
int main(){
    Dog dog1(5,10);
    Dog dog2(1,1);
    ofstream file("dog");
    file.write(reinterpret_cast<char*> (&dog1),sizeof(dog1));
    file.close();
    ifstream file1("dog");
    file1.read(reinterpret_cast<char*> (&dog2),sizeof(dog2));
    file1.close();
    cout<<"dog2:"<<endl<<"weight:"<<dog2.getweight()<<endl<<"old:"<<dog2.getold()<<endl;
    return 0;
}