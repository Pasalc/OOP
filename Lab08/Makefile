clean: main.exe
	rm *.o
main.exe: main.o TQueue.o Triangle.o TQueueItem.o Foursquare.o Rectangle.o TAllocationBlock.o
	g++ -Wall -g main.o TQueue.o Triangle.o TQueueItem.o Foursquare.o Rectangle.o TAllocationBlock.o -o main.exe -lpthread
main.o: main.cpp TQueueItem.h Rectangle.h TQueue.h Foursquare.h Triangle.h Figure.h
	g++ -c -g -Wall main.cpp 
TQueue.o: TQueue.cpp TQueue.h TIterator.h
	g++ -c -g -Wall TQueue.cpp 
TQueueItem.o: TQueueItem.cpp TQueueItem.h
	g++ -c -g -Wall TQueueItem.cpp 
Foursquare.o: Foursquare.cpp Foursquare.h
	g++ -c -g -Wall Foursquare.cpp 
Rectangle.o: Rectangle.cpp Rectangle.h
	g++ -c -g -Wall Rectangle.cpp 
Triangle.o: Triangle.cpp Triangle.h
	g++ -c -g -Wall Triangle.cpp 
TAllocationBlock.o: TAllocationBlock.cpp TAllocationBlock.h TAllocationItem.h
	g++ -c -g -Wall TAllocationBlock.cpp 
