#link the executable
#the first rule is the default
ic_recorder : main.o
	gcc -o ic_recorder main.o
	
#compile main
main.o :
	gcc -Wall -c main.c

clean :
	rm *.o
	rm ic_recorder
