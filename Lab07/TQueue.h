#ifndef TLIST_H
#define	TLIST_H
#include <memory>
#include "TQueueItem.h"
#include "TIterator.h"
#include "IRemoveCriteria.h"

template <class T,class TT> class TQueue {

public:
    TQueue();

    void InsertSubitem(std::shared_ptr<TT>&& value);
    void RemoveSubitem(IRemoveCriteria<TT>* criteria);
    void PushBack(T* value);
    bool Remove(T* value);
    void DealWithNill();
    size_t Size();
    bool empty();
    //std::shared_ptr<T> pop(std::shared_ptr<TQueueItem<T>> item);
    std::shared_ptr<T> pop();


    TIterator<TQueueItem<T>, T> begin() const;
    TIterator<TQueueItem<T>, T> end() const;
    template <class A,class AA> friend std::ostream& operator<<(std::ostream& os,TQueue<A,AA>& queue);

    virtual ~TQueue();
private:
    std::shared_ptr<TQueueItem<T>> head;
    std::shared_ptr<TQueueItem<T>> tail;
};

#endif
 // TQUEUE_H
