#include "TQueue.h"

template <class T> TQueue<T>::TQueue() : head(nullptr), tail(nullptr) {
}


template <class A> std::ostream& operator<<(std::ostream& os, const TQueue<A>& queue) {

    std::shared_ptr<TQueueItem<A>> item = queue.head;

    while(item!=nullptr)
    {
      os << *item;
      item = item->GetNext();
    }

    return os;
}

template <class T> void TQueue<T>::push(std::shared_ptr<T> &&figure) {
    std::shared_ptr<TQueueItem<T>> other(new TQueueItem<T>(figure));
    if(head==nullptr){
        head=other;
        tail=head;
    }
    else{
        tail->SetNext(other);
        tail = other;
    }
}

template <class T> bool TQueue<T>::empty() {
    return head == nullptr;
}

template <class T> std::shared_ptr<T> TQueue<T>::pop() {
    std::shared_ptr<T> result;
    if (head != nullptr) {
        result = head->GetFigure();
        head = head->GetNext();
    }

    return result;
}

template <class T> TQueue<T>::~TQueue() {

}

#include "Figure.h"
template class TQueue<Figure>;
template std::ostream& operator<<(std::ostream& os, const TQueue<Figure>& queue);
