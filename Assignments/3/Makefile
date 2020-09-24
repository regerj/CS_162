
CC = g++ -std=c++11
exe_file = zoo_keeper
$(exe_file): animal.o bear.o sea_lion.o tiger.o zoo.o main.o
	$(CC) animal.o bear.o sea_lion.o tiger.o zoo.o main.o -o $(exe_file)
animal.o: animal.cpp
	$(CC) -c animal.cpp
bear.o: bear.cpp
	$(CC) -c bear.cpp
sea_lion.o: sea_lion.cpp
	$(CC) -c sea_lion.cpp
tiger.o: tiger.cpp
	$(CC) -c tiger.cpp
zoo.o: zoo.cpp
	$(CC) -c zoo.cpp
main.o: main.cpp
	$(CC) -c main.cpp
clean:
	rm –f *.out *.o $(exe_file)