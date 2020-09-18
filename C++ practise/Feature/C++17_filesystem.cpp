#include <iostream>
#include <filesystem>
#include <string>
using std::cout;
using std::endl;

//More information please visit the website below:
// https://zh.cppreference.com/w/cpp/filesystem

int main()
{
    namespace fs = std::filesystem;
    //Three way to defined a file path: using (\,R /,and \\).
    fs::path p = {R"(D:\LEARNING_PROGRAMME)"};
    fs::path p2 = {"D:\\LEARNING_PROGRAMME\\hello.txt"};
    fs::path p3 = {"D:/LEARNING_PROGRAMME/hello.txt"};
    //output default file_separator
    cout << "File separator is:" << p.preferred_separator << endl;
    if (fs::is_regular_file(p))
    {
        cout << p << "size is :"<< fs::file_size(p) << endl;
    }
    else if (fs::is_directory(p))
    {
        cout << "P is a directory:" << endl;
        for (auto &e : fs::directory_iterator(p))
        {
            cout << e.path() << endl;
        }
    }
    else if (fs::exists(p))
    {
        cout << "p is a special file." << endl;
    }
    else
    {
        cout << "P does not exsist." << endl;
    }
    std::cin.get();
    return 0;
}