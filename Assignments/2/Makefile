
CC = g++ -std=c++11
exe_file = crazy_eights
$(exe_file): card.o deck.o game.o hand.o player.o main.o
	$(CC) card.o deck.o game.o hand.o player.o main.o -o $(exe_file)
card.o: card.cpp
	$(CC) -c card.cpp
deck.o: deck.cpp
	$(CC) -c deck.cpp
main.o: main.cpp
	$(CC) -c main.cpp
game.o: game.cpp
	$(CC) -c game.cpp
hand.o: hand.cpp
	$(CC) -c hand.cpp
player.o: player.cpp
	$(CC) -c player.cpp
clean:
	rm –f *.out *.o $(exe_file)