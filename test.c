#include <stdlib.h>
#include <stdio.h>
#include "ds_memory.h"
 


int main(void){
    
    /*printf("%ld\n",sizeof(struct ds_blocks_struct));*/
    /*printf( "sizeof( struct ds_counts_struct ) = %ld\n",

           sizeof(struct ds_counts_struct ) );

    printf( "sizeof( struct ds_blocks_struct ) = %ld\n",

           sizeof(struct ds_blocks_struct ) );

    printf( "sizeof( struct ds_file_struct ) = %ld\n",

           sizeof(struct ds_file_struct ) );*/

    

    int ds_create_return=ds_create("test.bin",1234);

    int ds_init_return=ds_init("test.bin");
       
    ds_test_init();

    printf("ds_create return value: %d\nds_init return value: %d\n",ds_create_return,ds_init_return);
    printf("\nDone!\n");
    return 0;
}