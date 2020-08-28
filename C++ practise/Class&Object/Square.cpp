#include "Square.h"
#include <iostream>
/*
问题：如果不使用vscode的cmake插件并利用cmake进行编译的话，
g++无法实现多文档编译链接，所以把这个cpp文件里面的内容也复
制到头文件里以便正常运行练习项目了。
详细配置方法可以搜索：（vscode C++ 多文档编译）
*/
Square::Square(double Side_){
    Side = Side_;
}

double Square::getArea(){
    return (Side * Side);
}

double Square::getSide(){
    return Side;
}

Square& Square::setSide(double Side_){
    Side = Side_;
    return (*this);
}