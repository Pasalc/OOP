#include "TArrayItem.h"
#include <iostream>

template <class T> TArrayItem<T>::TArrayItem() {
    std::cout<<"\t\tArrayItem:Created\n";
    this->_obj=nullptr;
}

template <class T> TArrayItem<T>::TArrayItem(const std::shared_ptr<T>& obj) {
    std::cout<<"\t\tArrayItem:Created with obj\n";
    this->_obj=obj;
}

template <class T> void TArrayItem<T>::SetFigure(const std::shared_ptr<T>& obj){
    this->_obj=obj;
}

template <class T> std::shared_ptr<T> TArrayItem<T>::GetFigure() const{
    return this->_obj;
}

template<class A> std::ostream& operator<<(std::ostream& os, const TArrayItem<A>& obj) {
    obj.GetFigure()->PrintInOs(os);
    return os;
}

template <class T> TArrayItem<T>::~TArrayItem() {
    std::cout << "TArrayItem :Delete Figure-->"<<*(this->GetFigure())<< std::endl;
}

#include "Figure.h"
template class TArrayItem<Figure>;
template std::ostream& operator<<(std::ostream& os, const TArrayItem<Figure>& array);
