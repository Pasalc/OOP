#ifndef FIGURE_H
#define	FIGURE_H

class Figure {
public:
    virtual double Square() = 0;
    virtual void Print() = 0;
    virtual std::ostream& PrintInOs(std::ostream& os) = 0;
    //friend std::ostream& operator <<(std::ostream& os,const Figure& obj){};
    virtual ~Figure() {};
};

#endif
