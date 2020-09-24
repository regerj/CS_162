CC = g++ -std=c++11
exe_file = wumpus_hunt
$(exe_file): implementation.o bats.o cave.o event.o gold.o pit.o player.o room.o wumpus.o main.o
	$(CC) implementation.o bats.o cave.o event.o gold.o pit.o player.o room.o wumpus.o main.o -o $(exe_file)
implementation.o: implementation.cpp
	$(CC) -c implementation.cpp
bats.o: bats.cpp
	$(CC) -c bats.cpp
cave.o: cave.cpp
	$(CC) -c cave.cpp
event.o: event.cpp
	$(CC) -c event.cpp
gold.o: gold.cpp
	$(CC) -c gold.cpp
pit.o: pit.cpp
	$(CC) -c pit.cpp
player.o: player.cpp
	$(CC) -c player.cpp
room.o: room.cpp
	$(CC) -c room.cpp
wumpus.o: wumpus.cpp
	$(CC) -c wumpus.cpp
main.o: main.cpp
	$(CC) -c main.cpp
clean:
	rm –f *.out *.o $(exe_file)