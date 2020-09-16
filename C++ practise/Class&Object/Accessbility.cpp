#include <iostream>
using std::cin;
using std::cout;
using std::endl;
class A
{
public:
    int i{0};

protected:
    int j{1};

private:
    int k{2};
};

class Pub : public A
{
public:
    void foo()
    {
        i++;
        j++;
        // k++;
    }
};

class Pro : protected A
{
public:
    void foo()
    {
        i++;
        j++;
        // k++;
    }
};

class Pri : private A
{
public:
    void foo()
    {
        i++;
        j++;
        // k++;
    }
};

int main()
{
    Pub pub;
    Pro pro;
    Pri pri;

    pub.i++;
    //以下均不可访问：
    // pub.j++;
    // pub.k++;

    // pri.i++;
    // pri.j++;
    // pri.k++;

    // pro.i++;
    // pro.j++;
    // pro.k++;
}