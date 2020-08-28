//猜大小
//电脑随机生成一个整数，用户猜
//提示：猜中了/大了/小了
#include <cstdlib>
#include <iostream>
int main(){
    //输入提示信息：生成数的范围。
    std::cout << "Generating a interger from 1~100" << std::endl;
    
    //输出提示信息：请用户输入整数
    std::cout << "Please guess it!" << std::endl << ":";
    int z = (rand() % 100);
    //定义变量保存用户输入
    auto x{0};
    std::cin >> x;
    //生成随机数，判断并输出信息
    if( x > z){
        std::cout << "too big!" << z << std::endl;
    }else if(x < z){
        std::cout << "too small!" << z << std::endl;
    }else{
        std::cout << "bingo!" << std::endl;
    }

    return 0;
}