#include <stdlib.h>
#include <stdio.h>
#include "ds_memory.h"
#include "ds_list.h"
 


int main(void){

    printf("create: %d\n",ds_create("list.bin",2048));
    printf("create list: %d\n", ds_create_list());

  

    return 0;
    
}
