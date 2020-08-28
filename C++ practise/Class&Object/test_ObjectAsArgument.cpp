#include <iostream>
#include "Square.h"
using std::cout;
using std::endl;

const void print1(Square c){
    cout << c.getArea() <<endl;
} 

const void print2(Square* c){
    cout << c->getArea() << endl;
}
//C++ feature: Overload of function!
const void print2(Square& c){
    cout << c.getArea() << endl;
}
int main(){

    Square c1{3.3};
    print1(c1);
    print2(&c1);
    print2(c1);

    return 0;
}