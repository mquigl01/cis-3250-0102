All: boggle.c boardGenerator.c boardGenerator.h dictionary.c dictionary.h scoreBoard.c scoreBoard.h wordChecker.c wordChecker.h
	gcc -Wall -pedantic -std=c99 -Iinclude boggle.c boardGenerator.c boardGenerator.h dictionary.c dictionary.h scoreBoard.c scoreBoard.h wordChecker.c wordChecker.h -o boggle
