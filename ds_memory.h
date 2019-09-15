/* ds_memory.h
 * Name: Michael Dombrovsky
 * Student ID: 1040227
 * Course: CIS*2520
 */

#include <stdlib.h>
#include <stdio.h>

#define MAX_BLOCKS 4096

 struct ds_counts_struct{
    int reads;
    int writes;
 };
 
 struct ds_blocks_struct{
    long start;
    long length;
    char alloced;
 };
 
 struct ds_file_struct{
     FILE *fp;
     struct ds_blocks_struct block[MAX_BLOCKS];
 };
 
 /*Function definitions*/
int ds_create( char *filename, long size );
int ds_init( char *filename );
long ds_malloc( long amount );
void ds_free( long start ) ;
void *ds_read( void *ptr, long start, long bytes ); 
long ds_write( long start, void *ptr, long bytes ); 
int ds_finish();



