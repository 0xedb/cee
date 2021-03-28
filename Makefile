
run: main.o token.o
	cc main.o token.o -o zoutput && ./zoutput

compile: main.c token.c
	cc -c main.c token.c 

clean: 
	rm a.out *.o zoutput