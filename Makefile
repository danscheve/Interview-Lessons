all: stack queue ll bitSet stddev fact
CC=gcc

CFLAGS=-I.
DEPS=fifo.h

%.o: %.c $(DEPS)	
	$(CC) -c -o $@ $< $(CFLAGS)
stack: stack.o
	gcc -o stack stack.c -I.
queue: queue.o
	gcc -o queue queue.c -I.
ll: ll.o
	gcc -o ll ll.c -I.
bitSet: bitSet.o
	gcc -o bitSet bitSet.c -I.
stddev: stddev.o
	gcc -o stddev stddev.c -I.
fact: fact.o
	gcc -o fact fact.c -I.
