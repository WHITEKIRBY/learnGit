#include <iostream>

int main(){
    using namespace std;

    
    // char alarm = '\a';
    // cout << alarm << "Don't do that !\a\n";
    // cout << "Don't!\a\n";
    // cout << "Don't\a" << alarm;

    // cout << "hi\x1a there?";

    cout << "Enter your code:______\b\b\b\b\b\b";
    int code;
    cin >> code;
    cout << "You have entered:" << code << "...\n";
    cout << "ID verified! Plan B is proceeding...\n";


    cin.get();
    cin.get();
    return 0 ;
}