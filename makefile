scoreBoard: scoreBoard.o
	gcc -Wall -pedantic -std=c99 scoreBoard.o -o scoreBoard

scoreBoard.o: scoreBoard.c scoreBoard.h
	gcc -Wall -pedantic -std=c99 -c scoreBoard.c -o scoreBoard.o

clean:
	rm -i ./*.o