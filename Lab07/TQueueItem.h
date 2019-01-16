#ifndef TLISTITEM_H
#define	TLISTITEM_H
#include <memory>
#include <iostream>

template <class T> class TQueueItem {
public:
    TQueueItem(T* value);

    std::shared_ptr<T> GetValue();
    std::shared_ptr<TQueueItem<T>> GetNext();
    void SetNext(std::shared_ptr<TQueueItem<T>> next);
    std::shared_ptr<TQueueItem<T>>* GetNextAdress();
    std::shared_ptr<TQueueItem<T>> PushBack(std::shared_ptr<TQueueItem<T>> next);
    void operator= (const std::shared_ptr<TQueueItem<T>>& QItem);
    virtual ~TQueueItem();
private:
    std::shared_ptr<T> _value;
    std::shared_ptr<TQueueItem> _next;

};

#endif  // TQUEUEITEM_H
