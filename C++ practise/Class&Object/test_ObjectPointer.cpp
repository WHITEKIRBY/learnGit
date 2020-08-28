#include <iostream>
#include "Square.h"
using std::cout;
using std::endl;


int main(){
    //4 way to initialize object & object pointer & object array.
    auto c1 = new Square[3] {1,2,3};
    auto*  c2 = new Square[3] {2,3,4};
    Square c3[] {Square{1},Square{2},Square{3}};
    Square c4[] {10,20,30};

    //fancy way of traversal in C++
    for (auto x : c3){
        cout << x.getArea() << endl;
    }

    delete [] c1;
    delete [] c2;
    c1=c2=nullptr;


    return 0;
}