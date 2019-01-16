#include <cstdlib>
#include "Triangle.h"
#include "Foursquare.h"
#include "Rectangle.h"

int main(int argc, char** argv) {

    bool key=true;
    Figure *ptr;
    char figure_type;
    std::cout << "Type \"1\" to choose triangle. Type \"2\" to choose foursquare. Type \"3\" to choose rectangle. Type \"4\" to repeat this message. " << std::endl;
    while(std::cin >> figure_type)
        switch(figure_type){
            case '1':
                ptr = new Triangle(std::cin);
                ptr->Print();
                std::cout << "Square of triangle:" << ptr->Square() << std::endl;
                delete ptr;
                key=true;
                break;
            case '2':
                ptr = new Foursquare(std::cin);
                ptr->Print();
                std::cout << "Square of foursquare:" << ptr->Square() << std::endl;
                delete ptr;
                key=true;
                break;
            case '3':
                ptr = new Rectangle(std::cin);
                ptr->Print();
                std::cout << "Square of rectangle:" << ptr->Square() << std::endl;
                delete ptr;
                key=true;
                break;
            case '4':
                std::cout << "Type \"1\" to choose triangle. Type \"2\" to choose foursquare. Type \"3\" to choose rectangle. Type \"4\" to repeat this message. " << std::endl;
                key=true;
                break;
            default:
                if(key) {
                std::cout << "Entered value was not valid" << std::endl;
                key=false;
                }
                break;
        }
    return 0;
}
