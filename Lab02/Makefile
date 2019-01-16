clean: main.exe
	rm *.o
main.exe: main.o TQueue.o Triangle.o TQueueItem.o
	g++ -Wall -g main.o TQueue.o Triangle.o TQueueItem.o -o main.exe
main.o: main.cpp TQueueItem.h Triangle.h TQueue.h
	g++ -c -g -Wall main.cpp
TQueue.o: TQueue.cpp TQueue.h
	g++ -c -g -Wall TQueue.cpp 
TQueueItem.o: TQueueItem.cpp TQueueItem.h
	g++ -c -g -Wall TQueueItem.cpp 
Triangle.o: Triangle.cpp Triangle.h
	g++ -c -g -Wall Triangle.cpp
