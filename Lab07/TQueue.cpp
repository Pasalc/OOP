#include "TQueue.h"

template <class T, class TT> TQueue<T, TT>::TQueue() {
    head = nullptr;
    tail=nullptr;
}

template <class T,class TT> std::shared_ptr<T> TQueue<T,TT>::pop() {
    std::shared_ptr<T> result;
    if (head != nullptr) {
        result = head->GetValue();
        head = head->GetNext();
    }
    if(head==nullptr){
        tail=nullptr;
    }
    return result;
}

template <class T, class TT> bool TQueue<T, TT>::empty(){
    return head==nullptr;
}
template <class T, class TT> void TQueue<T, TT>::DealWithNill(){//std::shared_ptr<TQueueItem<T>> item) {
    auto item=&head;
    std::cout<<*((*item)->GetValue());
    while((*item)!=nullptr){
        if((*item)->GetValue()->empty()){
            *item=(*item)->GetNext();
        }
        else{
            *&tail=*item;
            item=(*item)->GetNextAdress();
            //(*item)->SetToNext(item));
        }
    }
}

template <class T, class TT> void TQueue<T, TT>::RemoveSubitem(IRemoveCriteria<TT>* criteria) {
    std::cout << "---------------------->" << std::endl;
    for(auto i:(*this)){
        i->RemoveCriteria(criteria);
    }
    this->DealWithNill();

    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
}

template <class T, class TT> void TQueue<T, TT>::InsertSubitem(std::shared_ptr<TT>&& value) {
    try{
        if (head != nullptr) {

            for (auto i : * this) {
                if (i->push(value)){
                    return;
                }
            }
        }
        T* t_value = new T();
        if(t_value->push(value)){
            PushBack(t_value);
        }
        else{
            std::cout << "Queue: Can't push value to the new array. That means what something gone terribly wrong. Screw this and that code, I'm throwing an exception." << std::endl;
            throw std::invalid_argument("Catch me if you can");
        }
    }
    catch(...){
        std::cout<<"Gotcha\n";
    }
}

template <class T, class TT> void TQueue<T, TT>::PushBack(T* value) {
    std::shared_ptr<TQueueItem<T> > value_item(new TQueueItem<T>(value));
    if (head != nullptr) {
        tail = head->PushBack(value_item);
    } else {
        head = value_item;
        tail = head;
    }
}

template <class T, class TT> size_t TQueue<T, TT>::Size() {
    size_t result = 0;

    for (auto a : * this) result++;

    return result;
}

template <class T, class TT> TIterator<TQueueItem<T>, T> TQueue<T, TT>::begin() const{
    return TIterator<TQueueItem<T>, T>(head);
}

template <class T, class TT> TIterator<TQueueItem<T>, T> TQueue<T, TT>::end() const{
    return TIterator<TQueueItem<T>, T>(nullptr);
}

template <class T, class TT> TQueue<T, TT>::~TQueue() {
    std::cout << "Queue: deleted" << std::endl;
}

template <class A, class AA> std::ostream& operator<<(std::ostream& os, TQueue<A, AA>& queue) {
    std::cout << "Queue:" << std::endl;
    for(auto i:queue) std::cout << *i << std::endl;
    return os;
}

#include "TQueue.h"
#include "TArray.h"
#include "Figure.h"

template class TQueue<TArray<Figure>, Figure>;
template std::ostream& operator<<(std::ostream &os,TQueue<TArray<Figure>,Figure> &queue);

