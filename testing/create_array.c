#include <stdlib.h>
#include <stdio.h>
#include "ds_memory.h"
#include "ds_array.h"
 


int main(void){

    printf("create: %d\n",ds_create("array.bin",2048));
    printf("create array: %d\n", ds_create_array());
  

    return 0;
    
}
