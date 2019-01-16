#ifndef TQUEUEITEM_H
#define	TQUEUEITEM_H

#include "Triangle.h"
class TQueueItem {
public:
    TQueueItem(const Triangle& triangle);
    TQueueItem(const TQueueItem& orig);
    friend std::ostream& operator<<(std::ostream& os, const TQueueItem& obj);

    TQueueItem* SetNext(TQueueItem* next);
    TQueueItem* GetNext();
    Triangle GetTriangle() const;

    virtual ~TQueueItem();
private:
    Triangle triangle;
    TQueueItem *next;
};

#endif	/* TqueueITEM_H */
