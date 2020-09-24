
CC = g++ -std=c++11
exe_file = budget_buddy
$(exe_file): budget_buddy.o main.o
	$(CC) budget_buddy.o main.o -o $(exe_file)
budget_buddy.o: budget_buddy.cpp
	$(CC) -c budget_buddy.cpp
main.o: main.cpp
	$(CC) -c main.cpp
clean:
	rm –f *.out *.o $(exe_file)