all: boggle.o wordChecker.o scoreBoard.o dictionary.o boardGenerator.o boggle

boardGenerator.o: boardGenerator.c boardGenerator.h
	gcc -Wall -std=c99 -c -pedantic boardGenerator.c -o boardGenerator.o

dictionary.o: dictionary.c dictionary.h
	gcc -Wall -std=c99 -c -pedantic dictionary.c -o dictionary.o

scoreBoard.o: scoreBoard.c scoreBoard.h
	gcc -Wall -std=c99 -c -pedantic scoreBoard.c -o scoreBoard.o

wordChecker.o: wordChecker.c wordChecker.h
	gcc -Wall -std=c99 -c -pedantic wordChecker.c -o wordChecker.o

boggle.o: boggle.c wordChecker.h scoreBoard.h dictionary.h boardGenerator.h
	gcc -Wall -std=c99 -c -pedantic boggle.c -o boggle.o

boggle: boggle.o wordChecker.o scoreBoard.o dictionary.o boardGenerator.o
	gcc -Wall -pedantic boggle.o wordChecker.o scoreBoard.o dictionary.o boardGenerator.o -o boggle

clean:
	rm -i *.o
