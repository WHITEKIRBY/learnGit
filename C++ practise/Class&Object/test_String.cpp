#include <iostream>
using namespace std;

int main(){
    //创建字符串
    string s {"He llo"};
    //clear
    cout << s.find(" ",0) << endl;
    s.clear();
    //用数组为字符串赋值
    char s2[] {'W','o','r','l','d'};
    s += s2;
    //assign()
    s.assign("Hello World!");
    cout << s << endl;
    //append
    s.append("     ");
    s.append(5,' ');//注意双引号和单引号的区别!!这就是标准库吗，真是有够好笑的呢
    //s.append("!");
    //insert 空白
    s.insert(0,"   ");
    //移除字符串前面的空白
    s.erase(0,s.find_first_not_of(" \t\n\r"));
    //移除字符串后面的空白
    s.erase(s.find_last_not_of(" \t\n\r")+1);//注意不要把字符串最后一个位也删除了

    s += "$";
    
    cout << s << endl;
    return 0;
}