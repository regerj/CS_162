
CC = g++ -std=c++11
exe_file = shape_test
$(exe_file): main.cpp shape.cpp rectangle.cpp circle.cpp square.cpp
	$(CC) main.cpp shape.cpp rectangle.cpp circle.cpp square.cpp -o $(exe_file)
main.o: main.cpp
	$(CC) -c main.cpp
shape.o: shape.cpp
	$(CC) -c shape.cpp
rectangle.o: rectangle.cpp
	$(CC) -c rectangle.cpp
circle.o: circle.cpp
	$(CC) -c circle.cpp
square.o: square.cpp
	$(CC) -c square.cpp
clean:
	rm –f *.out *.o $(exe_file)