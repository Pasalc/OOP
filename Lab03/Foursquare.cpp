#include "Foursquare.h"
#include <iostream>
#include <cmath>

Foursquare::Foursquare() : Foursquare(0) {
}

Foursquare::Foursquare(size_t i) : side_a(i) {}

Foursquare::Foursquare(std::istream &is) {
    std::cout << "Enter your side" << std::endl;
    is >> side_a;
}

Foursquare::Foursquare(const Foursquare& orig) {
    side_a = orig.side_a;
}

double Foursquare::Square() {
    return pow(side_a,2);

}

void Foursquare::Print() {
    std::cout << "Foursquare with a=" << side_a << ", b=" << side_a << ", c=" << side_a << ", d=" << side_a  << std::endl;

}

std::ostream& Foursquare::PrintInOs(std::ostream& os){

    os <<*this;
    return os;
}

std::ostream& operator <<(std::ostream& os,const Foursquare& obj){
    os << "Foursquare with a=" << obj.side_a << ", b=" << obj.side_a << ", c=" << obj.side_a << ", d=" << obj.side_a << std::endl;
    return os;
}

Foursquare::~Foursquare() {}
