#include "TQueueItem.h"
#include <iostream>

TQueueItem::TQueueItem(const Triangle& triangle) {
    this->triangle = triangle;
    this->next = nullptr;
}

TQueueItem::TQueueItem(const TQueueItem& orig) {
    this->triangle = orig.triangle;
    this->next = orig.next;
}

TQueueItem* TQueueItem::SetNext(TQueueItem* next) {

    this->next = next;
    return this;
}

Triangle TQueueItem::GetTriangle() const {
    return this->triangle;
}

TQueueItem* TQueueItem::GetNext() {
    return this->next;
}

TQueueItem::~TQueueItem() {
    delete next;
}

std::ostream& operator<<(std::ostream& os, const TQueueItem& obj) {
    os << obj.triangle;
    return os;
}
