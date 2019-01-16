#ifndef TQUEUE_H
#define	TQUEUE_H

///#include "Triangle.h"
#include "Rectangle.h"
#include "Figure.h"
#include "TQueueItem.h"
#include <memory>

template<class T> class TQueue {
public:
    TQueue();

    void push(std::shared_ptr<T> &&figure);
    //void push(std::shared_ptr<Foursquare> &&triangle);
    bool empty();
    std::shared_ptr<T> pop();
    template<class A> friend std::ostream& operator<<(std::ostream& os,const TQueue<A>& Queue);
    virtual ~TQueue();
    begin();
    end();
private:
    std::shared_ptr<TQueueItem<T>> head;
    std::shared_ptr<TQueueItem<T>> tail;
};

#endif	/* TQueue_H */
