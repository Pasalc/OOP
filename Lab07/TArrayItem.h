#ifndef TSTACKITEM_H
#define	TSTACKITEM_H
#include <memory>
//#include "TAllocationBlock.h"


template<class T> class TArrayItem {
public:
    TArrayItem();
    TArrayItem(const std::shared_ptr<T>& obj);
    void SetFigure(const std::shared_ptr<T>& obj);
    std::shared_ptr<T> GetFigure() const;
    template<class A> friend std::ostream& operator<<(std::ostream& os, const TArrayItem<A>& obj);
    virtual ~TArrayItem();
private:
    std::shared_ptr<T> _obj;
/*    TArrayItem();
    TArrayItem(T *item);
    template<class A> friend std::ostream& operator<<(std::ostream& os, const TArrayItem<A>& obj);

    std::shared_ptr<TArrayItem<T>> SetNext(std::shared_ptr<TArrayItem> &next);
    std::shared_ptr<TArrayItem<T>> delValue(size_t num);
    std::shared_ptr<T> GetValue(size_t num) const;
    void* operator new (size_t size);
    void operator delete(void *p);
    T operator[](size_t num);
    virtual ~TArrayItem();
private:
    std::shared_ptr<T> item;
    size_t size;
    static TAllocationBlock arrayitem_allocator;
};
*/
};
#endif
