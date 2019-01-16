#include <cstdlib>
#include <iostream>

#include "Figure.h"
#include "Triangle.h"
#include "Rectangle.h"
//#include "TQueueItem.h"
#include "TQueue.h"
#include "Foursquare.h"
#include <random>

int main() {
    char k;
    size_t a,b,c;
    TQueue<Figure> queue;
/*    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, 10000);

    for (int i = 0; i < 50; i++) {
        int side = distribution(generator);
        queue.push(std::shared_ptr<Foursquare> (new Foursquare(side)));
    }
	std::cout <<"Members of queue:\n" <<queue;
    std::cout << "Sort -------------" << std::endl;
    queue.sort();
    std::cout << "Done -------------" << std::endl;
*/


    std::cout <<"Enter 1 to push triangle, enter 2 to push rectangle, enter 3 to push foursquare, enter 4 to pop, enter 5 to show elements of container, enter 6 to  enter anything else to close program"<< std::endl;
    while(std::cin>>k){
        switch(k){
            case '1':
                std::cin>>a>>b>>c;
                queue.push(std::shared_ptr<Triangle> (new Triangle(a,b,c)));
                std::cout <<"Pushed"<<std::endl;
                break;
            case '2':
                std::cin>>a>>b;
                queue.push(std::shared_ptr<Rectangle> (new Rectangle(a,b)));
                std::cout <<"Pushed"<<std::endl;
                break;
            case '3':
                std::cin>>a;
                queue.push(std::shared_ptr<Foursquare> (new Foursquare(a)));
                std::cout<<"Pushed"<<std::endl;
                break;
            case '4':
                if(queue.empty()){
                    std::cout <<"Queue is empty" <<std::endl;
                    break;
                }
                else{
                    std::cout <<"Poped:" <<std::endl;
                    queue.pop()->Print();
                    break;
                }
            case '5':
                if(queue.empty()){
                    std::cout <<"Queue is empty" <<std::endl;
                }
                else{
                    std::cout <<"Members of queue:\n" <<queue;
                }
                break;
            case '6':
                queue.sort_parallel();
				std::cout<<"Sorted]n";
                break;
            default:
                return 0;
            }

}
    return 0;
}
