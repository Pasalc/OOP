#ifndef IREMOVECRITERIAALL_H
#define	IREMOVECRITERIAALL_H
#include "IRemoveCriteria.h"

template <class T> class IRemoveCriteriaAll : public IRemoveCriteria<T>{
public:
    IRemoveCriteriaAll(size_t num) {typeNum=num;};
    bool isIt(std::shared_ptr<T> value) override{
        if(typeNum==1){
            return dynamic_cast<Triangle*>(value.get());
        }
        if(typeNum==2)
        {
            return dynamic_cast<Rectangle*>(value.get());
        }
        if(typeNum==3){
            return dynamic_cast<Foursquare*>(value.get());
        }
        return false;
    }
private:
    size_t typeNum;

};

#endif
