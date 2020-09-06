#include <iostream>
#include <string>
#include <array>
using std::cout;
using std::endl;
using std::string;

enum class Color
{
    red,
    orange,
    yellow,
    green,
    blue,
    purple,
    black
};

class shape //Base class
{
private:
    bool filled{false};
    Color color{Color::black};

public:
    shape() = default;
    shape(Color color_, bool filled_)
    {
        color = color_;
        filled = filled_;
    }

    string tostring()
    {
        std::array<string, 7> c{"red", "orange", "yellow", "green", "blue", "purple", "black"};
        return "This object is " + c[static_cast<int>(color)] + " with filled:" + std::to_string(filled);
    }
};

class Square : public shape //the exmaple of inherence for shape.
{
private:
    double Side;

public:
    Square() = default;
    Square(double Side_, Color color_, bool filled_);
    double getArea();
    Square &setSide(double Side_);
    double getSide();
};
Square::Square(double Side_, Color color_, bool filled_) : shape{color_, filled_}
//because the elelment of shape are private,it can just be initialize by shape{}.
{
    Side = Side_;
}

double Square::getArea()
{
    return (Side * Side);
}
double Square::getSide()
{
    return Side;
}
Square &Square::setSide(double Side_)
{
    Side = Side_;
    return (*this);
}

int main()
{
    Square s1{1.0, Color::red, true};
    cout << s1.tostring() << endl;
    std::cin.get();
    return 0;
}