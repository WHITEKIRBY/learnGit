#pragma once
#include <iostream>
class Square{
private:
    double Side;
public:
    Square();
    Square(double Side_);
    double getArea();
    Square& setSide(double Side_);
    double getSide();
};
Square::Square(double Side_){
    Side = Side_;
}

double Square::getArea(){
    return (Side * Side);
}

double Square::getSide(){
    return Side;
}

Square& Square::setSide(double Side_){
    Side = Side_;
    return (*this);
}