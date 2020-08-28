#include <iostream>
#include <string>

int main(){

    using namespace std;
    string str1;
    string str2 = "Do I love myself?";
    // string initial_way1 {"One way to initial string"};
    // string initial_way2 = {"Another way to initial string"};
    //以上为C++11特性

    char str3[20] = "Do I love myself?";
    //这里可以看出使用string类的主要区别：不必声明数组的长度，对于内存使用更加安全。
    //“类设计让程序能够自动处理string的大小。”

    str1 = str2;//字符串类型可以直接赋值，字符数组不可！
    str2 = str1 + str2;//字符串类型可以简单+合并
    
    //对于字符数组，达到相同的效果要引入头文件<cstring>/string.h
    //如: strcpy(); strcat();
    
    cout << str1.size() << endl;//对字符类对象使用方法

    return 0;
}
