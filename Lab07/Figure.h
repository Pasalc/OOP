#ifndef FIGURE_H
#define	FIGURE_H

class Figure {
public:
    virtual double Square() = 0;
    virtual void Print() = 0;
    virtual std::ostream& PrintInOs(std::ostream& os) const = 0;
    friend std::ostream& operator <<(std::ostream& os,const Figure& obj){
        return obj.PrintInOs(os);
    };
    //virtual size_t typeNum() = 0;
    virtual ~Figure() {};
};

#endif
