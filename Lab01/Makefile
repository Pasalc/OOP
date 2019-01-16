clean: main.exe
	rm *.o
main.exe: main.o Triangle.o Foursquare.o Rectangle.o
	g++ -Wall main.o Triangle.o Foursquare.o Rectangle.o -o main.exe
main.o: main.cpp Triangle.h Foursquare.h Rectangle.h
	g++ -c -Wall main.cpp
Triangle.o: Triangle.cpp Triangle.h
	g++ -c -Wall Triangle.cpp 
Foursquare.o: Foursquare.cpp Foursquare.h
	g++ -c -Wall Foursquare.cpp 
Rectangle.o: Rectangle.cpp Rectangle.h
	g++ -c -Wall Rectangle.cpp
