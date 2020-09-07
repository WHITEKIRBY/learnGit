#include <iostream>
using std::cout;
using std::endl;

//todo1:inherent ctor
//创建基类B以及构造函数B（int），B（char），并创建D对象继承/不继承B的ctor的效果

//todo2:派生类中调用基类构造函数
//D中增加成员double x；及D（double），在D（double）初始化列表调用B（i）并初始化x

//todo3：派生类先调用基类ctor，再构造内嵌对象
//增加类E及E（int),并在D中加入E的两个对象；创建D对象并观察E ctor 和B ctor 次序
class B
{
public:
    B() { cout << "B()" << endl; };
    B(int i) { cout << "B(" << i << ")" << endl; }
    B(char c) { cout << "B(" << c << ")" << endl; }
};

class E
{
public:
    E() { cout << "E()" << endl; }
};

class D : public B
{
public:
    using B::B;
    D() = default;
    //D(){} --> D():B() {}
    //D(int i){} --> D(int i):B(int i){}
    //D(char c){}
    D(double x) : e1{}, e2{}, B(static_cast<int>(x)), x{1.0} { cout << "D(" << x << ")" << endl; }

private:
    double x{0.0};
    E e1, e2;
};

int main()
{
    B b;
    D d;
    cout << "d2 with parameter: 3.03" << endl;
    cout << "You can see the order." << endl;
    D d2{3.03};
    std::cin.get();
    return 0;
}