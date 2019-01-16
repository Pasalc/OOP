#include "Rectangle.h"
#include <iostream>
#include <cmath>

Rectangle::Rectangle() : Rectangle(0, 0) {
}

Rectangle::Rectangle(size_t i, size_t j) : side_a(i), side_b(j) {}

Rectangle::Rectangle(std::istream &is) {
    std::cout << "Enter your sides" << std::endl;
    is >> side_a;
    is >> side_b;
}

Rectangle::Rectangle(const Rectangle& orig) {
    side_a = orig.side_a;
    side_b = orig.side_b;
}

double Rectangle::Square() {
    return side_a*side_b;

}

void Rectangle::Print() {
    std::cout << "Rectangle with a=" << side_a << ", b=" << side_b << ", c=" << side_a << ", d=" << side_b << std::endl;

}

std::ostream& Rectangle::PrintInOs(std::ostream& os) const{

    os <<*this;
    return os;
}

std::ostream& operator <<(std::ostream& os,const Rectangle& obj){
    os << "Rectangle with a=" << obj.side_a << ", b=" << obj.side_b << ", c=" << obj.side_a << ", d=" << obj.side_b << std::endl;
    return os;
}

Rectangle::~Rectangle() {
}
