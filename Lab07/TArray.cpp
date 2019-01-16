#include "TArray.h"
template <class T> TArray<T>::TArray() : size(0){
    std::cout << "\tArray created" << std::endl;
    item=new TArrayItem<T>[5];
}

template <class T> std::ostream& operator<<(std::ostream& os, TArray<T>& array) {

    for(size_t i=0;i<array.size;i++)
    {
      std::cout<<array.item[i];
    }
    return os;
}

template <class T> bool TArray<T>::push(std::shared_ptr<T>& pushItem) {
    if(size>4){
        return false;
    }
    size_t i=0;
    while(i<size&&item[i].GetFigure()->Square()<=pushItem->Square()) i++;
    auto temp = pushItem;
    while(i<size){
        auto temp2=item[i].GetFigure();
        item[i].SetFigure(temp);
        temp=temp2;
        i++;
    }
    item[size].SetFigure(temp);
    size++;
    return true;
}

template <class T> bool TArray<T>::RemoveNumber(size_t num) {
    if(num>=size){
        return false;
    }
    size--;
    while(num<size){
        auto temp=item[num+1].GetFigure();
        item[num].SetFigure(temp);
        num++;
    }
    return true;
}

template <class T> bool TArray<T>::RemoveCriteria(IRemoveCriteria<T> * criteria) {
    for(size_t i=size;i>0;i--){
        if (criteria->isIt(item[i-1].GetFigure())){
            RemoveNumber(i-1);
        }
    }
    return this->empty();
}
template <class T> bool TArray<T>::empty() {
    return size == 0;
}

template <class T> TArray<T>::~TArray() {
    std::cout << "\tArray:Delete\n" << std::endl;
    for(size_t i=0; i<size;i++){
        auto r=item+i;
        delete r;
    }
}

#include "Figure.h"
template class TArray<Figure>;
template std::ostream& operator<<(std::ostream& os, TArray<Figure>& array);


///
//template <class T>  TAllocationBlock TArray<T>::arrayitem_allocator(sizeof(T*)*5,1);

/*
template <class T> void * TArray<T>::operator new (size_t size) {
	return arrayitem_allocator.allocate();
}


template <class T> void TArray<T>::operator delete(void *p) {
	arrayitem_allocator.deallocate(p);
}
*/
template <class T> TArrayItem<T> TArray<T>::operator [](size_t num){
    return item[num];//item.get()[num];//(item.get()+num);///sizeof(T)
}
