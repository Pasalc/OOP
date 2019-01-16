#include "Foursquare.h"
#include <iostream>
#include <cmath>

Foursquare::Foursquare() : Foursquare(0) {
}

Foursquare::Foursquare(size_t i) : side_a(i) {
    std::cout << "Foursquare created: " << side_a << std::endl;
}

Foursquare::Foursquare(std::istream &is) {
    std::cout << "Enter your side" << std::endl;
    is >> side_a;
}

Foursquare::Foursquare(const Foursquare& orig) {
    std::cout << "Foursquare copy created" << std::endl;
    side_a = orig.side_a;
}

double Foursquare::Square() {
    return pow(side_a,2);

}

void Foursquare::Print() {
    std::cout << "Foursquare with a=" << side_a << ", b=" << side_a << ", c=" << side_a << ", d=" << side_a  << std::endl;

}

Foursquare::~Foursquare() {
    std::cout << "Foursquare deleted" << std::endl;
}
