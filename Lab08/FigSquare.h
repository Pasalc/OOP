#ifndef FIGSQUARE_H
#define FIGSQUARE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class FigSquare : public Figure{
public:
    FigSquare();
    FigSquare(double i):square(i){};

    double Square() override{return square;};
    ///Плохая наследственность

    void   Print() override{};
    std::ostream& PrintInOs(std::ostream& os) const override{return os<<"Nope\n";};

    ///
    virtual ~FigSquare(){};
private:
    double square;
};

#endif // FIGSQUARE_H
