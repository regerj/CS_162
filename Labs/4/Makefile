
CC = g++ -std=c++11
exe_file = hand_class
$(exe_file): hand.o main.o
	$(CC) hand.o main.o -o $(exe_file)
card.o: hand.cpp
	$(CC) -c hand.cpp
main.o: main.cpp
	$(CC) -c main.cpp
clean:
	rm –f *.out *.o $(exe_file)