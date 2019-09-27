/* ds_list.h
 * Name: Michael Dombrovsky
 * Student ID: 1040227
 * Course: CIS*2520
 */

#include <stdlib.h>
#include <stdio.h>

struct ds_list_item_struct{
    int item;
    long next;
};

typedef struct ds_list_item_struct listNode;

/*Function definitions*/
int ds_create_list();
int ds_init_list();
int ds_replace( int value, long index );
int ds_insert( int value, long index ); 
int ds_delete( long index );
int ds_swap( long index1, long index2 ); 
long ds_find( int target ); 
int ds_read_elements( char *filename ); 
int ds_finish_list(); 
long traverse_list(listNode *ptr, long address,int traversals);
int write_first_node(int value, long next);
long create_node(int value, long next);
int write_node(long address, listNode node);
int get_head(void *ptr);
int set_head(long address);

