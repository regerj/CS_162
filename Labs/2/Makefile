
CC = g++
exe_file = student_sorter
$(exe_file): student_sorter.o prog.o
	$(CC) student_sorter.o prog.o -o $(exe_file)
student_sorter.o: student_sorter.cpp
	$(CC) -c student_sorter.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp
clean:
	rm –f *.out *.o $(exe_file)