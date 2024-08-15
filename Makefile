all:
	cc -g src/utils/utils.c src/parser/parser.c src/main.c src/lexer/lexer.c src/lexer/tokens.c -o Nikotine.o -Wall -I include/