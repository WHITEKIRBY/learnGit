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

    //由于C++存在输入缓冲区，在缓冲区内还存在一个换行符，导致return前的cin.get()不起作用
    //需要设置两条cin.get()语句
    cin.get();
    cin.get();
    return 0 ;
}