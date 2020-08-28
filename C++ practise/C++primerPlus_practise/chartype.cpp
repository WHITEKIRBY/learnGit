#include <iostream>

int main(){
    using namespace std;
    char ch;
    
    cout << "Enter a character:";
    cin >> ch;
    cout << "Thanks for the " << ch << "character!";
    
    ch = 'M';
    int i = ch;
    cout << "The ASCII code for" << ch << "is:" << i << endl;
    
    
    cin.get();
    cin.get();
    return 0 ;
}