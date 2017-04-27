proj2: main.o RegisterFile_01.o
	gcc -g -Wall main.o RegisterFile_01.o -o proj2

main.o: main.c
	gcc -c -g -Wall main.c

RegisterFile_01.o: RegisterFile_01.c RegisterFile_01.h
		gcc -c -g -Wall RegisterFile_01.c

clean:
	rm -f *- *.o proj2
