CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -g3

all: run

run: linked_list.o graph.o graph_test.o
	$(CC) $(CFLAGS) -o $@ $^
	echo "building...."

linked_list.o: linked_list.c linked_list.h
graph.o: graph.c graph.h
graph_test.o: graph_test.c

test: run
	./run

clean:
	$(RM) run *.o
