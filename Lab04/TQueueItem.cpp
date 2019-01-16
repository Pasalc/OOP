#include "TQueueItem.h"
#include <iostream>

template<class T> TQueueItem<T>::TQueueItem(const std::shared_ptr<T>& figure) {
    this->figure = figure;
    this->next = nullptr;
}

template<class T> std::shared_ptr<TQueueItem<T>> TQueueItem<T>::SetNext(std::shared_ptr<TQueueItem<T>> &next) {
    std::shared_ptr<TQueueItem<T>> old = this->next;
    this->next = next;
    return old;
}

template<class T> std::shared_ptr<T> TQueueItem<T>::GetFigure() const {
    return this->figure;
}

template<class T> std::shared_ptr<TQueueItem<T>> TQueueItem<T>::GetNext() {
    return this->next;
}

template<class A> std::ostream& operator<<(std::ostream& os, const TQueueItem<A>& obj) {
    obj.GetFigure()->PrintInOs(os);
    return os;
}

template<class T> TQueueItem<T>::~TQueueItem() {
}

#include "Figure.h"
template class TQueueItem<Figure>;
template std::ostream& operator<<(std::ostream& os, const TQueueItem<Figure>& stack);
