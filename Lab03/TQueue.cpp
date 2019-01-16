#include "TQueue.h"

TQueue::TQueue() : head(nullptr), tail(nullptr) {
}


std::ostream& operator<<(std::ostream& os, const TQueue& queue) {

    std::shared_ptr<TQueueItem> item = queue.head;

    while(item!=nullptr)
    {
      os << *item;
      item = item->GetNext();
    }

    return os;
}

void TQueue::push(std::shared_ptr<Figure> &&triangle) {
    std::shared_ptr<TQueueItem> other(new TQueueItem(triangle));
    if(head==nullptr){
        head=other;
        tail=head;
    }
    else{
        tail->SetNext(other);
        tail = other;
    }
}

bool TQueue::empty() {
    return head == nullptr;
}

std::shared_ptr<Figure> TQueue::pop() {
    std::shared_ptr<Figure> result;
    if (head != nullptr) {
        result = head->GetFigure();
        head = head->GetNext();
    }

    return result;
}

TQueue::~TQueue() {

}
