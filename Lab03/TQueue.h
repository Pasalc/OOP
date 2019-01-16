#ifndef TQUEUE_H
#define	TQUEUE_H

#include "Triangle.h"
#include "Rectangle.h"
#include "TQueueItem.h"
#include <memory>

class TQueue {
public:
    TQueue();

    void push(std::shared_ptr<Triangle> &&triangle);
    void push(std::shared_ptr<Rectangle> &&triangle);
    void push(std::shared_ptr<Figure> &&triangle);
    //void push(std::shared_ptr<Foursquare> &&triangle);
    bool empty();
    std::shared_ptr<Figure> pop();
    friend std::ostream& operator<<(std::ostream& os,const TQueue& Queue);
    virtual ~TQueue();
private:
    std::shared_ptr<TQueueItem> head;
    std::shared_ptr<TQueueItem> tail;
};

#endif	/* TQueue_H */
