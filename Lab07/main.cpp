#include <cstdlib>
#include <iostream>
#include <memory>

#include "Figure.h"
#include "Triangle.h"
#include "Foursquare.h"
#include "Rectangle.h"
#include "TArray.h"
#include "TQueue.h"
#include "IRemoveCriteriaByValue.h"
#include "IRemoveCriteriaAll.h"
#include "FigSquare.h"

int main() {
    TQueue<TArray<Figure>,Figure> list;
    size_t a=6,b=8,c=10;
    auto temp =std::shared_ptr<Triangle> (new Triangle(a,b,c));
    try{
        list.InsertSubitem(std::shared_ptr<Triangle> (new Triangle(a,b,c)));
        a=3;
        b=4;
        c=5;
        list.InsertSubitem(std::shared_ptr<Triangle> (new Triangle(a,b,c)));
        a=6;
        b=8;
        c=10;
        list.InsertSubitem(std::shared_ptr<Triangle> (new Triangle(a,b,c)));
        list.InsertSubitem(std::shared_ptr<Triangle> (new Triangle(a,b,c)));
        a=3;
        b=4;
        c=5;
        list.InsertSubitem(std::shared_ptr<Triangle> (new Triangle(a,b,c)));
        list.InsertSubitem(std::shared_ptr<Foursquare> (new Foursquare(a)));
        a=6;b=8;c=10;
        ///auto ter=new Triangle(a,b,c);
        ///IRemoveCriteria<Figure> criteria(ter);

        ///IRemoveCriteriaByValue<Triangle> criteria(std::shared_ptr<Triangle> (new Triangle(a,b,c)));

        ///list.RemoveSubitem(new IRemoveCriteriaByValue<Figure> (std::shared_ptr<Triangle> (new Triangle(a,b,c))));
        list.RemoveSubitem(new IRemoveCriteriaAll<Figure> (a));
        //list.RemoveSubitem(&criteria);
    }
    catch (...) {
        std::cout<<"I got it!!!Whatever it is...\n";
    }
    std::cout << list << std::endl;
    delete &list;


    char k;
    size_t g=0;
    size_t h=0;
    double squareOfFigure=0;
    TQueue<TArray<Figure>,Figure> queue;
    std::cout <<"Enter 1 to push triangle, enter 2 to push rectangle, enter 3 to push foursquare, enter 4 to pop, enter 5 to show elements of first-level container, enter 6 to show elements of second-level container, enter anything else to close program"<< std::endl;
    while(std::cin>>k){
        switch(k){
            case '1':
                std::cin>>a>>b>>c;
                queue.InsertSubitem(std::shared_ptr<Triangle> (new Triangle(a,b,c)));
                std::cout <<"Successfully Pushed Triangle in Queue"<<std::endl;
                break;
            case '2':
                std::cin>>a>>b;
                queue.InsertSubitem(std::shared_ptr<Rectangle> (new Rectangle(a,b)));
                std::cout <<"Successfully Pushed Rectangle in Queue"<<std::endl;
                break;
            case '3':
                std::cin>>a;
                queue.InsertSubitem(std::shared_ptr<Foursquare> (new Foursquare(a)));
                std::cout<<"Successfully Pushed Foursquare in Queue"<<std::endl;
                break;
            case '4':
                if(queue.empty()){
                    std::cout <<"Queue is empty" <<std::endl;
                    break;
                }
                else{
                    std::cout <<"Poped:" <<std::endl<<queue.pop();
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
                g=0;h=0;
                std::cout<<"Enter number of element to show (begins from zero)\n";
                std::cin>>h;
                for(auto i:queue){
                    if(g==h){
                        std::cout<<*i<<std::endl;
                    }
                    g++;
                }
                break;
            case '7':
                std::cout<<"Press:\n\t1 if you want to delete all figures which square are less then some square\n\t2 if you want to delete all figures of chosen type\t\nanything less to return to previous page\n";
                std::cin>>g;
                if(g==1){
                    std::cout<<"Enter your square:\t";
                    std::cin>>squareOfFigure;
                    queue.RemoveSubitem(new IRemoveCriteriaByValue<Figure> (std::shared_ptr<FigSquare> (new FigSquare(squareOfFigure))));
                }
                else if(g==2){
                    std::cout<<"Type:\n\t1 to delete all Triangles\t\n2 to delete all Rectangles\t\n3 to delete all Foursquares\t\nanything else to return to the main page\n";
                    std::cin>>g;
                    queue.RemoveSubitem(new IRemoveCriteriaAll<Figure> (g));
                }
                break;
            default:
                return 0;
            }

}
   return 0;
}

