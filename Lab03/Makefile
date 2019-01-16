clean: main.exe
	rm *.o
main.exe: main.o TQueue.o Triangle.o TQueueItem.o Foursquare.o Rectangle.o
	g++ -Wall -g main.o TQueue.o Triangle.o TQueueItem.o Foursquare.o Rectangle.o -o main.exe
main.o: main.cpp TQueueItem.h Triangle.h TQueue.h Rectangle.h Foursquare.h Figure.h
	g++ -c -g -Wall main.cpp
TQueue.o: TQueue.cpp TQueue.h
	g++ -c -g -Wall TQueue.cpp 
TQueueItem.o: TQueueItem.cpp TQueueItem.h
	g++ -c -g -Wall TQueueItem.cpp 
Triangle.o: Triangle.cpp Triangle.h
	g++ -c -g -Wall Triangle.cpp
Rectangle.o: Rectangle.cpp Rectangle.h
	g++ -c -g -Wall Rectangle.cpp 
Foursquare.o: Foursquare.cpp Foursquare.h
	g++ -c -g -Wall Foursquare.cpp
