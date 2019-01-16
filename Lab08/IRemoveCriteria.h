#ifndef IREMOVECRITERIA_H
#define	IREMOVECRITERIA_H
#include <memory>

template<class T> class IRemoveCriteria {
public:
    /*std::shared_ptr<T> val;
    IRemoveCriteria(std::shared_ptr<T> value):_numType(0),figureType(false){
        //val=std::shared_ptr<T>(value);
        val=value;
        std::cout<<"DDDUUUUCCCCKKK";
        //auto temp =val->Square();
        //std::cout<<temp->Square();
    };
    IRemoveCriteria(size_t numType):_numType(numType),figureType(true){val=nullptr;};

    size_t _numType;
    bool figureType;
    bool isIt(std::shared_ptr<T> item) {
        if(figureType){
        //    =item->typeNum;
        }
        else{
            return val->Square()>item->Square();
        }
    }
        //return figureType?_value->typeNum== item->typeNum:_value->Square()>item->Square();};
    virtual ~IRemoveCriteria() {};*/
    virtual bool isIt(std::shared_ptr<T> value) = 0;
private:

};
#endif// IREMOVECRITERIA_H
