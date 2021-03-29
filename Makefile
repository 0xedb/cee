CFLAGS= -Wall

run: main.o token.o lexer.o
	cc $(CFLAGS) main.o token.o lexer.o -o zoutput && ./zoutput

compile: main.c token/token.c
	cc $(CFLAGS) -c main.c token/token.c lexer/lexer.c

clean: 
	rm a.out *.o zoutput

