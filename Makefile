proj2: main.o RegisterFile_01.o ALUSimulator.o
	gcc -g -Wall main.o RegisterFile_01.o ALUSimulator.o -o proj2

main.o: main.c
	gcc -c -g -Wall main.c

RegisterFile_01.o: RegisterFile_01.c RegisterFile_01.h
		gcc -c -g -Wall RegisterFile_01.c

ALUSimulator.o: ALUSimulator.c ALUSimulator.h
	gcc -c -g -Wall ALUSimulator.c

clean:
	rm -f *- *.o proj2
