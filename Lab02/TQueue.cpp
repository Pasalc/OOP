#include "TQueue.h"

TQueue::TQueue() : head(nullptr), tail(nullptr) {
}

TQueue::TQueue(const TQueue& orig) {
    head = orig.head;
    tail = orig.tail;
}

std::ostream& operator<<(std::ostream& os, const TQueue& queue) {

    TQueueItem *item = queue.head;

    while(item!=nullptr)
    {
      os << *item;
      item = item->GetNext();
    }
    return os;
}

TQueueItem* TQueue::push(Triangle &triangle) {
    TQueueItem *other = new TQueueItem(triangle);
    if(head==nullptr){
        head=other;
        tail=head;
        return tail;
    }
    tail->SetNext(other);
    tail=other;
    return tail;
    //tail = other;
}

bool TQueue::empty() {
    return head == nullptr;
}

Triangle TQueue::pop() {

    Triangle result;
    if (head!=nullptr){
        TQueueItem *old_head = head;
        head = head->GetNext();
        result = old_head->GetTriangle();
        old_head->SetNext(nullptr);
        delete old_head;
    }
    return result;

}

TQueue::~TQueue() {
    delete head;
}
