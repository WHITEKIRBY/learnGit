#include <iostream>
#include "Square.h"

using std::cout;
using std::endl;

int main(){
    Square s1;
    Square s2 = Square(4.0);//Anonymous object Initializing!

    cout << s1.getArea() << endl;
    cout << s2.getArea() << endl;

    s1 = s2;

    cout << s1.getArea() << endl;
    cout << s2.getArea() << endl;

    return 0;
}