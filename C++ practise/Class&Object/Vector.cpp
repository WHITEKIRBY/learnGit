#include <vector>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::vector;
template <typename T>
std::ostream &operator<<(std::ostream &s, const std::vector<T> &v)
{
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    for (const auto &e : v)
    {
        s << comma << e;
        comma[0] = ',';
    }
    return s << ']';
}

int main()
{
    //用C++11的列表初始化 创建vector对象
    vector<string> s1{"hello", "world!", "welcome", "to", "C!"};
    cout << s1 << endl;

    //删除s1中最后一个与元素
    s1.erase(s1.end() - 1); //注意，end（）迭代器指向的是最后一个元素的后一个位置！自己编写迭代器是也要养成这种习惯
    cout << s1 << endl;

    //在s1尾部追加一些元素
    s1.push_back("C++!");
    cout << s1 << endl;

    //用iterator拷贝s1中的内容以创建s2
    //另外c++11必须指定vector中的内容
    vector<string> s2(s1.begin(), s1.end());
    cout << s2 << endl;

    //用拷贝构造创建s3
    vector<string> s3(s2);
    cout << s3 << endl;
    
    //创建s4，初始化为多个相同的字符串
    vector<string> s4(4, "C++");
    cout << s4 << endl;

    return 0;
}