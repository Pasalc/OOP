#ifndef TQUEUEITEM_H
#define	TQUEUEITEM_H
#include <memory>
#include "Figure.h"
//#include "Triangle.h"

template<class T> class TQueueItem {
public:
    TQueueItem(const std::shared_ptr<T>& figure);
    //TQueueItem(const std::shared_ptr<Figure>& figure);
    template<class A> friend std::ostream& operator<<(std::ostream& os, const TQueueItem<A>& obj);

    std::shared_ptr<TQueueItem<T>> SetNext(std::shared_ptr<TQueueItem> &next);
    std::shared_ptr<TQueueItem<T>> GetNext();
    std::shared_ptr<T> GetFigure() const;

    virtual ~TQueueItem();
private:
    std::shared_ptr<T> figure; //Figure
    std::shared_ptr<TQueueItem<T>> next;
};

#endif	/* TQUEUEITEM_H */
