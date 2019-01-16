#ifndef TQUEUEITEM_H
#define	TQUEUEITEM_H
#include <memory>
#include "Figure.h"
#include "Triangle.h"
class TQueueItem {
public:
    TQueueItem(const std::shared_ptr<Figure>& figure);
    //TQueueItem(const std::shared_ptr<Figure>& figure);
    friend std::ostream& operator<<(std::ostream& os, const TQueueItem& obj);

    std::shared_ptr<TQueueItem> SetNext(std::shared_ptr<TQueueItem> &next);
    std::shared_ptr<TQueueItem> GetNext();
    std::shared_ptr<Figure> GetFigure() const;

    virtual ~TQueueItem();
private:
    std::shared_ptr<Figure> figure; //Figure
    std::shared_ptr<TQueueItem> next;
};

#endif	/* TQUEUEITEM_H */
