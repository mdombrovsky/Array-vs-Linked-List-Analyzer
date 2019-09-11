/* ds_memory.c
 * Name: Michael Dombrovsky
 * Student ID: 1040227
 * Course: CIS*2520
 */

struct ds_file_struct ds_file;

struct ds_counts_struct ds_counts;

int ds_create( char *filename, long size );

int ds_init( char *filename );

long ds_malloc( long amount );

void ds_free( long start ) ;

void *ds_read( void *ptr, long start, long bytes ); 

int ds_finish();
