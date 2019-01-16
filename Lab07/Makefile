clean: main.exe
	rm *.o
main.exe: main.o TQueue.o TQueueItem.o TArray.o TArrayItem.o Triangle.o Foursquare.o Rectangle.o
	g++ -Wall -g main.o TQueue.o TArray.o TArrayItem.o TQueueItem.o Triangle.o Foursquare.o Rectangle.o -o main.exe
main.o: main.cpp TArray.h Triangle.h TQueue.h Rectangle.h Foursquare.h Figure.h FigSquare.h IRemoveCriteriaByValue.h IRemoveCriteriaAll.h
	g++ -c -g -Wall main.cpp
TQueue.o: TQueue.cpp TQueue.h TArray.h TIterator.h
	g++ -c -g -Wall TQueue.cpp 
TQueueItem.o: TQueueItem.cpp TQueueItem.h
	g++ -c -g -Wall TQueueItem.cpp 
TArray.o: TArray.cpp TArray.h 
	g++ -c -g -Wall TArray.cpp 
TArrayItem.o: TArrayItem.cpp TArrayItem.h Figure.h
	g++ -c -g -Wall TArrayItem.cpp 
Triangle.o: Triangle.cpp Triangle.h
	g++ -c -g -Wall Triangle.cpp
Rectangle.o: Rectangle.cpp Rectangle.h
	g++ -c -g -Wall Rectangle.cpp 
Foursquare.o: Foursquare.cpp Foursquare.h
	g++ -c -g -Wall Foursquare.cpp