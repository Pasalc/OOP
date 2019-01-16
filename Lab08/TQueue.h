#ifndef TQUEUE_H
#define	TQUEUE_H

///#include "Triangle.h"
#include "Rectangle.h"
#include "Figure.h"
#include "TQueueItem.h"
#include "TIterator.h"
#include <memory>
#include <future>
#include <mutex>
#include <functional>
//#include <mingw.mutex.h>
//#include <mingw.future.h>
//#include <mingw.thread.h>
//#define BOOST_THREAD_VERSION 4
//#include <boost/thread.hpp>
//#include <boost/thread/future.hpp>

//#define BOOST_THREAD_VERSION 4
//#include <boost/thread.hpp>
//#includeD:\FI\Kurs2\OOP\Lab_08\include\TQueue.h <boost/thread/future.hpp>

template<class T> class TQueue {
public:
    TQueue();

    void push(std::shared_ptr<T> &&figure);
    void push(std::shared_ptr<T> &figure);
    std::shared_ptr<T> pop();
    bool empty();

    void sort();
    void sort_parallel();

    template<class A> friend std::ostream& operator<<(std::ostream& os,const TQueue<A>& Queue);
    virtual ~TQueue();

    TIterator<TQueueItem<T>,T> begin();
    TIterator<TQueueItem<T>,T> end();
private:
    std::future<void> sort_in_background();

    std::shared_ptr<TQueueItem<T>> head;
    std::shared_ptr<TQueueItem<T>> tail;


};

#endif	/* TQueue_H */
