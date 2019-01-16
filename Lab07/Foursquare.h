#ifndef FOURSQUARE_H
#define FOURSQUARE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Foursquare : public Figure{
public:
    Foursquare();
    Foursquare(std::istream &is);
    Foursquare(size_t i);
    Foursquare(const Foursquare& orig);

    double Square() override;
    void   Print() override;
    //size_t typeNum(){return 2;};
    std::ostream& PrintInOs(std::ostream& os) const override;
    friend std::ostream& operator<<(std::ostream& os, const Foursquare& obj);

    virtual ~Foursquare();
private:
    size_t side_a;
};

#endif
