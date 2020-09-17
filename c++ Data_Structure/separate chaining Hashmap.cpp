//From C version of Data structure,so the programme is totally c-style.
//And not recommanded to use "typedef", you should use "using" in C++ instead.
#include <iostream>
#include <set>
using std::set;
int foo(int arg)
{ // do something
    return (arg);
}

int main()
{

    // auto x = foo(42);

    if (auto x = foo(42); x > 40)
    {

        // do something with x
    }
    else
    {

        // do something with x
    }

    auto x = 3; // 名字 x 可重用
}