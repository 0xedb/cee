CFLAGS= -Wall

run: main.o token/token.o
	cc $(CFLAGS) main.o token.o -o zoutput && ./zoutput

compile: main.c token/token.c
	cc $(CFLAGS) -c main.c token/token.c

clean: 
	rm a.out *.o zoutput

	