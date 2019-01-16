#ifndef TSTACK_H
#define	TSTACK_H

#include <iostream>
#include "TArrayItem.h"
#include "IRemoveCriteria.h"
#include <memory>

template <class T> class TArray {
public:
    TArray();
    bool push(std::shared_ptr<T>& item);
    bool empty();
    //std::shared_ptr<T> DeleteByCount(size_t num);
    bool RemoveNumber(size_t num);
    bool RemoveCriteria(IRemoveCriteria<T>* criteria);
    template <class A> friend std::ostream& operator<<(std::ostream& os, TArray<A>& array);

    //T delValue(size_t num);
    //T GetValue(size_t num) const;
    //void* operator new (size_t size);
    //void operator delete(void *p);
    TArrayItem<T> operator[](size_t num);

    virtual ~TArray();

private:
    TArrayItem<T>* item;
    size_t size;
    //TAllocationBlock arrayitem_allocator;
};

#endif // TARRAY_H
