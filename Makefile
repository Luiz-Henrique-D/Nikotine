all:
	cc -g src/main.c src/lexer/lexer.c src/lexer/tokens.c -o Nikotine.o -Wall -I include/