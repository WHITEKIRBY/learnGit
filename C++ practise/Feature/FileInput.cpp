#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

namespace fs = std::filesystem;

int main()
{
    fs::path p{"scores.txt"};
    ifstream input{p};
    if (input.fail())
    {
        cout << "fail to open file";
        std::cin.get();
        return 0;
    }
    // string name;
    // double score{0.0};
    // input >> name >> score;
    // cout << name << " " << score << endl;
    // input >> name >> score;
    // cout << name << " " << score;
    char x;
    while (!input.get(x).eof())
    {
        cout << x; 
    }
    std::cin.get();
    return 0;
}