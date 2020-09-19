#include <iostream>
#include <fstream>
#include <filesystem>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

namespace fs = std::filesystem;

int main()
{
    fs::path p{"scores.txt"};

    ofstream output{p};
    double lileiScore{90.5};
    int hanmeimeiScore{80};

    output << "Lilei " << lileiScore << endl;
    output << "hanmeimei " << hanmeimeiScore << endl;

    output.close();

    cout << "size of file is : " << fs::file_size(p) << endl;


    std::cin.get();

    return 0;
}