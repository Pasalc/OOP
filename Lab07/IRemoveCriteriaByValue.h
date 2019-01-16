#ifndef IREMOVECRITERIABYVALUE_H
#define	IREMOVECRITERIABYVALUE_H
#include "IRemoveCriteria.h"

template <class T> class IRemoveCriteriaByValue : public IRemoveCriteria<T>{
public:
    IRemoveCriteriaByValue(std::shared_ptr<T> value){
        val=value;
    };
    bool isIt(std::shared_ptr<T> item) override{
        return val->Square()>item->Square();
    };
private:
    std::shared_ptr<T> val;
};

#endif
// IREMOVECRITERIABYVALUE_H
