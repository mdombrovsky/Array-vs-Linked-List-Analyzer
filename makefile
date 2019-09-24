CC=gcc
CFLAGS=-Wall -ansi -g -pedantic

all: ds_memory.o ds_list.o ds_array.o

ds_memory.o: ds_memory.c ds_memory.h
	$(CC) $(CFLAGS) -c ds_memory.c -o ds_memory.o

ds_list.o: ds_list.c ds_list.h
	$(CC) $(CFLAGS) -c ds_list.c -o ds_list.o
	
ds_array.o: ds_array.c ds_array.h
	$(CC) $(CFLAGS) -c ds_array.c -o ds_array.o

test: ds_memory.o ds_array.o test.o ds_memory.h ds_array.h
	$(CC) $(CFLAGS) test.o ds_memory.o ds_array.o -o test
	./test

test.o: test.c
	$(CC) $(CFLAGS) -c test.c -o test.o

clean_test: clean
	rm test
	rm test.bin

clean:
	rm *.o
	rm -i array.bin