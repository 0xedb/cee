CFLAGS= -Wall

run: main.o token.o lexer.o lexer.o repl.o
	cc $(CFLAGS) main.o token.o lexer.o repl.o -o zoutput && ./zoutput

compile: main.c token/token.c lexer/lexer.c repl/repl.c
	cc $(CFLAGS) -c main.c token/token.c lexer/lexer.c repl/repl.c

clean: 
	rm a.out *.o zoutput

