#include <iostream>
#include <filesystem>
#include <string>
using std::cin;
using std::cout;
using std::endl;
namespace fs = std::filesystem;

int main()
{
    fs::path p1 = {R"(D:\LEARNING_PROGRAMME)"};
    fs::path p2 = {R"(D:\LEARNING_PROGRAMME)"};
    fs::path p3 = {""};
    //append and /=
    p1.append(R"(C++ practise)");
    p1 /= R"(Feature)";
    cout << p1 << endl;
    //concat and +=

    p2.concat(R"(C++ practise)");
    p2 += R"(Feature)";
    cout << p2 << endl;
    // about: /

    p3 = p3 / R"(D:\LEARNING_PROGRAMME)" / R"(C++ practise)" / R"(Feature)";
    cout << p3 << endl;

    cin.get();
    return 0;
}