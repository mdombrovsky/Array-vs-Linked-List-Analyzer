/* ds_array.c
 * Name: Michael Dombrovsky
 * Student ID: 1040227
 * Course: CIS*2520
 */

#include "ds_array.h"
#include "ds_memory.h"

long elements;


int ds_create_array(){

    int error;

    error=ds_init("array.bin");

    if(error!=0)
        return error+10;
    

    error=ds_malloc(sizeof(elements));

    if(error==-1)
        return error+20;

    elements=0;

    error=ds_malloc(sizeof(int)*MAX_ELEMENTS);

    if(error==-1)
        return error+30;

    error=ds_write(0,&elements,sizeof(elements));
    if(error==-1)
        return error+40;
    
    error=ds_finish();
    if(error!=1)
        return error+50;
    return(0);
}
