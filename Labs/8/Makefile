CC = g++ -std=c++11
exe_file = vector_test
$(exe_file): vector.cpp
	$(CC) vector.cpp -o $(exe_file)
vector.o: vector.cpp
	$(CC) -c vector.cpp
clean:
	rm –f *.out *.o $(exe_file)