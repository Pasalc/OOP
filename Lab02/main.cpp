#include <cstdlib>
#include <iostream>

#include "Triangle.h"
#include "TQueueItem.h"
#include "TQueue.h"

// Simple queue on pointers

int main() {
    char c;
    Triangle a;
    TQueue queue;
    std::cout <<"Enter 1 to push, enter 2 to pop, enter 3 to show elements of container, enter anything else to close program"<< std::endl;
    while(std::cin>>c){
        switch(c){
            case '1':
                std::cin>>a;
                queue.push(a);
                std::cout <<"Pushed"<<std::endl;
                break;
            case '2':
                if(queue.empty()){
                    std::cout <<"Queue is empty" <<std::endl;
                    break;
                }
                else{
                    a = queue.pop();
                    std::cout <<"Poped:" <<a <<std::endl;
                    break;
                }
            case '3':
                if(queue.empty()){
                    std::cout <<"Queue is empty" <<std::endl;
                }
                else{
                    std::cout <<"Members of queue:" <<queue <<std::endl;
                }
                break;
            default:
                return 0;
            }
}
    return 0;
}
