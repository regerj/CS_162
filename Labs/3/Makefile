
CC = g++ -std=c++11
exe_file = deck_sorter
$(exe_file): card.o deck.o main.o
	$(CC) card.o deck.o main.o -o $(exe_file)
card.o: card.cpp
	$(CC) -c card.cpp
deck.o: deck.cpp
	$(CC) -c deck.cpp
main.o: main.cpp
	$(CC) -c main.cpp
clean:
	rm –f *.out *.o $(exe_file)