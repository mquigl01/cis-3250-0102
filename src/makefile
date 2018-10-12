boggle: boggle.c wordChecker.o scoreBoard.o dictionary.o boardGenerator.o
	gcc -Wall -pedantic -c boggle.c -iInclude ../bin/wordChecker.o ../bin/scoreBoard.o ../bin/dictionary.o ../bin/boardGenerator.o -o ../bin/boggle

boardGenerator.o: boardGenerator.c boardGenerator.h
	gcc -Wall -std=c99 -pedantic -c boardGenerator.c -o ../bin/boardGenerator.o

dictionary.o: dictionary.c dictionary.h
	gcc -Wall -std=c99 -pedantic -c dictionary.c -o ../bin/dictionary.o

scoreBoard.o: scoreBoard.c scoreBoard.h
	gcc -Wall -std=c99 -pedantic -c scoreBoard.c -o ../bin/scoreBoard.o

wordChecker.o: wordChecker.c wordChecker.h
	gcc -Wall -std=c99 -pedantic -c wordChecker.c -o ../bin/wordChecker.o

clean:
	rm -i *.o
