#include <iostream>
#include <array>
#include <algorithm>
using std::array;
using std::cout;
using std::endl;

void print(array<int,3>& a){
    for(int x:a){
        cout << x <<endl;
    }
}

int main(){
    //创建数组
    array<int,3> a1 {1,2,4};
    print(a1);
    //为数组赋值
    a1 = {7,8,9};
    print(a1);
    //交换数组
    array<int,3> b1 {100,200,300};
    print(b1);
    a1.swap(b1);
    print(a1);
    print(b1);
    //求数组大小
    cout << a1.size() <<endl;
    cout << a1.max_size() << endl;

    //Q?:为何我的std：：sort显示没有这个函数
    //A:#include <algorithm>
    //Q?:为何老师的演示中不包含这个头文件也通过了编译？？
    std::sort(a1.begin(),a1.end());
    print(a1);
    return 0;
}