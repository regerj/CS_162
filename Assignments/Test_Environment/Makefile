CC = g++ -std=c++11
exe_file = LL_Test
$(exe_file): linked_list.o node.o main.o
	$(CC) linked_list.o node.o main.o -o $(exe_file)
linked_list.o: linked_list.cpp
	$(CC) -c linked_list.cpp
node.o: node.cpp
	$(CC) -c node.cpp
main.o: main.cpp
	$(CC) -c main.cpp
clean:
	rm –f *.out *.o $(exe_file)