#include <iostream>
#include <typeinfo>
/******************************************
Almost Always Auto !!!(AAA) （尽量使用auto）
*******************************************/
using std::endl;
using std::cout;
using std::cin;
auto max(int x,int y){
    return x > y ? x : y;
}

int main(){
    //auto变量必须在定义时初始化
    auto x = 3;
    auto y{42};

    //定义在一个auto序列中的变量必须始终推导成同一类型
    auto x1{1} , x2{2} ;

    //如果初始化表达式是引用成const，则去除引用或者const语义
    int y1{42};
    int& y2 = y1;
    auto y3 = y2;
    cout << typeid(y3).name() << endl;
    //if auto + &，则不去除引用或const语意
    auto& z1{y2};
    cout << typeid(z1).name() << endl;
    
    //初始化表达式为数组时，auto 推断为指针
    int p[3]{1,2,3};
    auto p1 = p;
    cout << typeid(p1).name() << endl;

    //auto& 推断为数组类型
    auto& p2 = p;
    cout << typeid(p2).name() << endl;

    //C++14中，auto可以作为函数的返回类型和参数类型
    cout << max(x1,x2) <<endl;

    cin.get();
    return 0;
}