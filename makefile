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

create_array: ds_memory.o ds_array.o create_array.o ds_memory.h ds_array.h
	$(CC) $(CFLAGS) create_array.o ds_memory.o ds_array.o -o create_array

find_array: ds_memory.o ds_array.o find_array.o ds_memory.h ds_array.h
	$(CC) $(CFLAGS) find_array.o ds_memory.o ds_array.o -o find_array

swap_array: ds_memory.o ds_array.o swap_array.o ds_memory.h ds_array.h
	$(CC) $(CFLAGS) swap_array.o ds_memory.o ds_array.o -o swap_array
	
	
delete_array: ds_memory.o ds_array.o delete_array.o ds_memory.h ds_array.h
	$(CC) $(CFLAGS) delete_array.o ds_memory.o ds_array.o -o delete_array

read_elements: ds_memory.o ds_array.o read_elements.o ds_memory.h ds_array.h
	$(CC) $(CFLAGS) read_elements.o ds_memory.o ds_array.o -o read_elements

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

create_array.o: create_array.c
	$(CC) $(CFLAGS) -c create_array.c -o create_array.o

find_array.o: find_array.c
	$(CC) $(CFLAGS) -c find_array.c -o find_array.o

swap_array.o: swap_array.c
	$(CC) $(CFLAGS) -c swap_array.c -o swap_array.o


delete_array.o: delete_array.c
	$(CC) $(CFLAGS) -c delete_array.c -o delete_array.o

read_elements.o: read_elements.c
	$(CC) $(CFLAGS) -c read_elements.c -o read_elements.o

clean_test: clean
	rm test
	rm test.bin

clean:
	rm *.o
	rm -i array.bin