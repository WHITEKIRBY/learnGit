#include <iostream>

int main()
{
    using namespace std;

    // cout << (1 / 2) << endl;
    // cout << static_cast<double>(1 / 2) << endl;
    // cout << static_cast<double>(1) / 2 << endl;

    int r, &ri = r;
    r = 5; ri = 10;
    cout << r << " " << ri << endl;
    cin.get();
    return 0;
}