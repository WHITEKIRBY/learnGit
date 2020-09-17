#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main(){
    //常量声明
    const int x = 42;
    //常量不可变
    //x = 21;(error)

    //指针常量指向的数据不可变
    int y = 2;
    //int* p = x;(error)
    const int* p = &x;
    //*p = x;(error)
    const int* q = &y;
    //*q = 4;(error)

    //指针常量不可变
    int* const r = &y;
    int z = 5;
    //r = &z;(error)
    *r = 24;
    cout << *r << " " << y << endl;

    //常指针常量
    const int* const s = &y;
    //s = &z;(error)

    const char* str = "Hello";
    //*str = "w";(error)
    
    auto p1 = &y;
    auto p2 = "world";
    auto const p3 = "l";

    char a[3],b[3];
    char* const p4 = a;
    p4[3] = b[0];

    cin.get();
    return 0;
}