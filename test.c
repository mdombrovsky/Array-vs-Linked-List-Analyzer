#include <stdlib.h>
#include <stdio.h>
#include "ds_memory.h"

 


int main(void){
    
    /*printf("%ld\n",sizeof(struct ds_blocks_struct));*/
    ds_create("bin/test.bin",10);
    
    printf("Done\n");
    return 0;
}