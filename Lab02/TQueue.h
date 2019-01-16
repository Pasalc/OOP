#ifndef TQUEUE_H
#define	TQUEUE_H

#include "Triangle.h"
#include "TQueueItem.h"

class TQueue {
public:
    TQueue();
    TQueue(const TQueue& orig);

    TQueueItem* push(Triangle &triangle);
    bool empty();
    Triangle pop();
    friend std::ostream& operator<<(std::ostream& os,const TQueue& queue);
    virtual ~TQueue();
private:
    TQueueItem *head;
    TQueueItem *tail;
};

#endif	/* TQueue_H */
