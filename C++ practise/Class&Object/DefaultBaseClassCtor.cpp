#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
    A() { cout << "A()" << endl; }
    //这个默认构造函数不能省略：因为继承类B初始化时需要调用A的默认构造函数
    //但是A类由于已经存在带参构造函数，编译器不会自动生成默认构造函数，所以编译会报错。
    //或者强行要求编译器生成一个默认函数：A（） = default；
    A(int i) { cout << "A(" << i << ")" << endl; }
};

class B : public A
{
public:
    B() { cout << "B()" << endl; }
    //如果初始化时想要同时调用A类的带参构造函数，写法如下：
    B(int j) : A(j) { cout << "B(" << j << ")" << endl; }
    // B(int j) { cout << "B(" << j << ")" << endl; }
};

int main()
{
    A a;
    A a1{2};
    B b;
    B b1{3};

    std::cin.get();
    return 0;
}