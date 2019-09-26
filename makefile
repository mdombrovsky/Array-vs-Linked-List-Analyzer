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

insert_array: ds_memory.o ds_array.o insert_array.o ds_memory.h ds_array.h
	$(CC) $(CFLAGS) insert_array.o ds_memory.o ds_array.o -o insert_array

show_array: ds_memory.o ds_array.o show_array.o ds_memory.h ds_array.h
	$(CC) $(CFLAGS) show_array.o ds_memory.o ds_array.o -o show_array

show_array.o: show_array.c
	$(CC) $(CFLAGS) -c show_array.c -o show_array.o

insert_array.o: insert_array.c
	$(CC) $(CFLAGS) -c insert_array.c -o insert_array.o

test.o: test.c
	$(CC) $(CFLAGS) -c test.c -o test.o

clean_test: clean
	rm test
	rm test.bin

clean:
	rm *.o
	rm -i array.bin