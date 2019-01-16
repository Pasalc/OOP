clean: main.exe
	rm *.o
main.exe: main.o TQueue.o Triangle.o TQueueItem.o Foursquare.o Rectangle.o
	g++ -Wall -g main.o TQueue.o Triangle.o TQueueItem.o Foursquare.o Rectangle.o -o main.exe -lpthread
main.o: main.cpp TQueueItem.h Rectangle.h TQueue.h Foursquare.h Triangle.h Figure.h
	g++ -c -g -Wall main.cpp 
TQueue.o: TQueue.cpp TQueue.h
	g++ -c -g -Wall TQueue.cpp 
TQueueItem.o: TQueueItem.cpp TQueueItem.h
	g++ -c -g -Wall TQueueItem.cpp 
Foursquare.o: Foursquare.cpp Foursquare.h
	g++ -c -g -Wall Foursquare.cpp 
Rectangle.o: Rectangle.cpp Rectangle.h
	g++ -c -g -Wall Rectangle.cpp 