#include <fstream>
#include <iostream>
#include <array>
#include <filesystem>

using std::cout;
using std::endl;
using std::cin;
using std::fstream;
using std::ifstream;
using std::ofstream;
namespace fs = std::filesystem;

int main()
{
    using io = std::ios;
    fs::path p{"array.dat"};

    fstream out{p, io::app | io::out};

    if (out.fail())
    {
        cout << "can't open a outstream." << endl;
        std::abort();
    }
    std::array a{5, 1, 2, 3, 4, 6, 7, 9};
    std::streamsize size = a.size() * sizeof(a[0]);
    out.write(reinterpret_cast<char *>(&a[0]), size);

    //以读模式重新打开二进制文件，或者将光标定位到文件头
    out.close();
    //废物利用
    out.open(p, io::in);

    //从二进制流中读入一个数并输出到屏幕上：
    auto x{0};
    out.read(reinterpret_cast<char *>(&x), sizeof(x));
    cout << x << endl;

    // system("pause");
    cin.get();
    return 0;
}