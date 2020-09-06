#include <iostream>
using namespace std;
class A
{
public:
    A(int i) {}
    A(double d, int i) {}
    // ...
};

class B : A
{               // C++11
    using A::A; // 继承基类所有构造函数
    int d{0};   // 就地初始化
};

int main()
{
    B b(1); // 调A(int i)
    return 0;
}