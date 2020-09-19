#include <iostream>
#include <fstream>
#include <filesystem>
#include <array>
#include <string>
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

namespace fs = std::filesystem;

int main()
{
    fs::path p{"GameName.txt"};
    ifstream in{p};
    if (!in)
    {
        cout << "can't open file!" << endl;
        std::abort();
    }
    //确定缓冲区数组大小
    constexpr int SIZE = 100;
    std::array<char, SIZE> buf;

    while (!in.eof())
    {
        in.getline(&buf[0], SIZE, '#');
        cout << &buf[0] << endl;
    }
    in.close();
    in.open(p);
    //std::getline 的用法
    string name{""};
    while (!in.eof())
    {
        std::getline(in, name, '#');
        cout << name << endl;
    }
    std::cin.get();
    return 0;
}