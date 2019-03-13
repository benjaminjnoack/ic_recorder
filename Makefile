#default goal
#link the executable
ic_recorder : main.o
	gcc -o ic_recorder main.o
	
#compile main
main.o : main.c
	gcc -Wall -c main.c

clean :
	rm *.o
	rm ic_recorder
