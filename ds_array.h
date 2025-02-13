/* ds_array.h
 * Name: Michael Dombrovsky
 * Student ID: 1040227
 * Email: mdombrov@uoguelph.ca
 * Course: CIS*2520
 */

#include <stdlib.h>
#include <stdio.h>



/*Function Definitions*/
int ds_create_array();
int ds_init_array();
int ds_replace( int value, long index );
int ds_insert( int value, long index ); 
int ds_delete( long index ) ;
int ds_swap( long index1, long index2 );
long ds_find( int target ); 
int ds_read_elements( char *filename ); 
int ds_finish_array(); 
long get_index_start_array(int index);
void* read_int_in_array(void *ptr, long index);
void show_array();
