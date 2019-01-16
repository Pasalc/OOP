#include "TQueue.h"
#include "TIterator.h"
#include "Figure.h"

template <class T> TQueue<T>::TQueue() : head(nullptr), tail(nullptr) {
}

template <class T> TIterator<TQueueItem<T>,T> TQueue<T>::begin(){
    return TIterator<TQueueItem<T>,T>(head);
}

template <class T> TIterator<TQueueItem<T>,T> TQueue<T>::end(){
    return TIterator<TQueueItem<T>,T>(nullptr);
}

template <class T> void TQueue<T>::sort() {
    if (!empty()) {
        std::shared_ptr<T> mid = pop();
        double midSquare = mid->Square();
        TQueue<T> left, right;


        while(!empty()) {
            auto i=pop();
            if ((*i).Square()<midSquare) {
                left.push(i);
            } else {
                right.push(i);
            }
        }

        left.sort();
        right.sort();

        while (!left.empty()) push(left.pop());
        push(mid);
        while (!right.empty()) push(right.pop());

    }
}

template<class T > std::future<void> TQueue<T>::sort_in_background() {
    std::packaged_task<void(void) > task(std::bind(std::mem_fn(&TQueue<T>::sort_parallel), this));
    std::future<void> res(task.get_future());
    //std::future<void> res=std::async(std::launch::assync,std::mem_fn(&TQueue<T>::sort_parallel),this);
    //res.get();
    std::thread th(std::move(task));
    th.detach();
    return res;
}

template <class T> void TQueue<T>::sort_parallel() {
    if (!empty()) {
        std::shared_ptr<T> middle = pop();
        TQueue<T> left, right;
        double sq=middle->Square();
        while (!empty()) {
            std::shared_ptr<T> item = pop();
            if ((*item).Square() < sq) {
                left.push(item);
            } else {
                right.push(item);
            }
        }
        std::future<void> left_res = left.sort_in_background();
        std::future<void> right_res = right.sort_in_background();


        left_res.get();
        while (!left.empty()) push(left.pop());

        push(middle);

        right_res.get();
        while (!right.empty()) push(right.pop());

    }
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

template <class T> void TQueue<T>::push(std::shared_ptr<T> &figure) {
    std::shared_ptr<TQueueItem<T>> other(new TQueueItem<T>(figure));
  //  for(auto i:*this){
  //      if(i->GetArray()->Insert(other)) return;
  //  }
    if(head==nullptr){
        head=other;
        tail=head;
    }
    else{
        tail->SetNext(other);
        tail = other;
    }
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

template <class T> std::shared_ptr<T> TQueue<T>::pop() {
    std::shared_ptr<T> result;
    if (head != nullptr) {
        result = head->GetFigure();
        head = head->GetNext();
    }

    return result;
}

template <class T> bool TQueue<T>::empty() {
    return head == nullptr;
}

template <class T> TQueue<T>::~TQueue() {
}

#include "Figure.h"
template class TQueue<Figure>;
template std::ostream& operator<<(std::ostream& os, const TQueue<Figure>& queue);
