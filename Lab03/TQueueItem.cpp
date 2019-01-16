#include "TQueueItem.h"
#include <iostream>

TQueueItem::TQueueItem(const std::shared_ptr<Figure>& figure) {
    this->figure = figure;
    this->next = nullptr;
}

std::shared_ptr<TQueueItem> TQueueItem::SetNext(std::shared_ptr<TQueueItem> &next) {
    std::shared_ptr<TQueueItem> old = this->next;
    this->next = next;
    return old;
}

std::shared_ptr<Figure> TQueueItem::GetFigure() const {
    return this->figure;
}

std::shared_ptr<TQueueItem> TQueueItem::GetNext() {
    return this->next;
}

std::ostream& operator<<(std::ostream& os, const TQueueItem& obj) {
    obj.figure->PrintInOs(os);
    return os;
}

TQueueItem::~TQueueItem() {
}

