CC=gcc
CFLAGS=-Wall -ansi -g -Iincludes


ds_memory.o: src/ds_memory.c includes/ds_memory.h
	$(CC) $(CFLAGS) -c src/ds_memory.c -o bin/ds_memory.o

ds_list.o: src/ds_list.c includes/ds_list.h
	$(CC) $(CFLAGS) -c src/ds_list.c -o bin/ds_list.o
	
ds_array.o: src/ds_array.c includes/ds_array.h
	$(CC) $(CFLAGS) -c src/ds_array.c -o bin/ds_array.o

clean:
	rm bin/*