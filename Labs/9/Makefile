CC = g++ -std=c++11
exe_file = merge_sort
$(exe_file): prog.o algo.o
	$(CC) prog.o algo.o -o $(exe_file)
prog.o: prog.cpp
	$(CC) -c prog.cpp
algo.o: algo.cpp
	$(CC) -c algo.cpp
clean:
	rm –f *.out *.o $(exe_file)