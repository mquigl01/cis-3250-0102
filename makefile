All: boggle.c board_generator.c board_generator.h dictionary.c dictionary.h scoreboard.c scoreboard.h word_checker.c word_checker.h
	gcc -Wall -pedantic -std=c99 -Iinclude boggle.c board_generator.c board_generator.h dictionary.c dictionary.h scoreboard.c scoreboard.h word_checker.c word_checker.h -o boggle
