boggle: wordChecker.o scoreBoard.o dictionary.o boardGenerator.o boggle.o
	gcc -Wall -pedantic ../bin/boggle.o ../bin/wordChecker.o ../bin/scoreBoard.o ../bin/dictionary.o ../bin/boardGenerator.o -o ../bin/boggle

boardGenerator.o: boardGenerator.c boardGenerator.h
	gcc -Wall -std=c99 -pedantic -c boardGenerator.c -o ../bin/boardGenerator.o

dictionary.o: dictionary.c dictionary.h
	gcc -Wall -std=c99 -pedantic -c dictionary.c -o ../bin/dictionary.o

scoreBoard.o: scoreBoard.c scoreBoard.h
	gcc -Wall -std=c99 -pedantic -c scoreBoard.c -o ../bin/scoreBoard.o

wordChecker.o: wordChecker.c wordChecker.h
	gcc -Wall -std=c99 -pedantic -c wordChecker.c -o ../bin/wordChecker.o

boggle.o: boggle.c wordChecker.h scoreBoard.h dictionary.h boardGenerator.h
	gcc -Wall -std=c99 -c -pedantic boggle.c -o ../bin/boggle.o

clean:
	rm -i ../bin/*.o
