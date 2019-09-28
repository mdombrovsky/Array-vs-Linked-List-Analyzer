#include <stdlib.h>
#include <stdio.h>
#include "ds_list.h"
 


int main(void){

    printf("init list: %d\n",ds_init_list());
    show_list();
    printf("finish list: %d\n",ds_finish_list());

    return 0;
    
}