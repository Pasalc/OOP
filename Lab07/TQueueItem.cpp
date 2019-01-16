#include "TQueueItem.h"

template <class T> TQueueItem<T>::TQueueItem(T* value) {
    std::cout<<"QueueItem: Created\n";
    _value = std::shared_ptr<T> (value);
    _next = nullptr;
}

template <class T> std::shared_ptr<T> TQueueItem<T>::GetValue() {
    return _value;
}

template <class T> std::shared_ptr<TQueueItem<T>> TQueueItem<T>::GetNext() {
    return _next;
}

template <class T> std::shared_ptr<TQueueItem<T>>* TQueueItem<T>::GetNextAdress(){
    return &_next;
}

template <class T> void TQueueItem<T>::SetNext(std::shared_ptr<TQueueItem> next) {
    _next = next;
}

template <class T> std::shared_ptr<TQueueItem<T>> TQueueItem<T>::PushBack(std::shared_ptr<TQueueItem> next) {
    if (_next != nullptr) {
        return _next->PushBack(next);
    } else {
        _next = next;
        return _next;
    }
}

template <class T> void TQueueItem<T>::operator=(const std::shared_ptr<TQueueItem<T>>& right) {

    _value = right->_value;
    _next = right->_next;
}


template <class T> TQueueItem<T>::~TQueueItem() {
    std::cout<<"QueueItem: Deleted\n";
}

#include "TArray.h"
#include "Figure.h"
template class TQueueItem<TArray<Figure>>;
