class x;//提前声明x类
class z;//提前声明z类
class y{//定义y类
    private://无私有成员
    
    public:
    void g(x*f);//声明函数g（x*f），其参数是指向x类的指针f
};
class x{
    friend void h(x*p);//声明函数h（x*p）为x类的友元函数，友元函数可以通过对象名访问类的私有和保护成员
    friend void y::g(x*a);//声明y类的成员函数g（x*a）为x类的友元函数
    friend class z;//声明z类为x类的友元类，及z类的所有成员函数都是x类的友元函数，都可以通过对象名访问x类的私有和保护对象
    private:
    int i;//定义私有成员i
    public:
    x();//不带参数的构造函数
    int s(){//定义整形函数s，用于返回此时i的值
        return i;
    }
};

class z{
    private:
   
    public:
    void f(x*a);//声明f（x*a）函数，该函数的参数是指向x类的指针
};
void h(x*p){//实现函数，实现对i加10
    p->i+=10;
};
x::x():i(0){//不带参数的构造函数，默认初始化为0
};

void y::g(x*f){//实现函数，实现对i加1
    f->i+=1;
};

void z::f(x*a){//实现函数，实现对i加5

    a->i+=5;
};