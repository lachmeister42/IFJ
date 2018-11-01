PROGS=test
CC=gcc
CFLAGS=-Wall -std=c99 -pedantic -lm

all: test

test: binaryTree.o test.o errorHandler.o scanner.o parser.o
	$(CC) $(CFLAGS) -o $@ *.o
binaryTree.o: binaryTree.c
	$(CC) $(CFLAGS) -c binaryTree.c
treeTest.o: test.c
	$(CC) $(CFLAGS) -c test.c
errorHandler.o: errorHandler.c
	$(CC) $(CFLAGS) -c errorHandler.c
parser.o: parser.c
	$(CC) $(CFLAGS) -c parser.c
scanner.o: scanner.c
	$(CC) $(CFLAGS) -c scanner.c

clean:
	rm -f *.o *.out $(PROGS)
#