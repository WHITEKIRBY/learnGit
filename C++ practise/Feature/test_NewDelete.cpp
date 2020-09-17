#include <iostream>
int main(){
    using namespace std;

    int* p = nullptr;
    int* q{ nullptr };//C++11 

    p = new int(42);
    q = new int[4];

    cout << "Before: *p = " << *p << endl;
    *p = 24;
    cout << "After: *p = " << *p << endl;

    for (int i=0;i<4;i++){
        *(q+i) = i^2;//按位异或
        cout << *(q+i) <<endl;
    }

    delete p;
    delete [] q;
    
    cin.get();
    return 0;
}