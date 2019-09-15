/* ds_array.c
 * Name: Michael Dombrovsky
 * Student ID: 1040227
 * Course: CIS*2520
 */


long elements;


int ds_create_array(){

    int error;

    error=ds_create("array.bin",sizeof(long)+sizeof(int)*MAX_ELEMENTS);

    if(error!=0)
        return error+10;

    error=ds_init("array.bin");

    if(error!=0)
        return error+20;
    

    error=ds_malloc(sizeof(long));

    if(error==-1)
        return error+30;

    long=0;

    error=ds_malloc(sizeof(int)*MAX_ELEMENTS);

    if(error==-1)
        return error+40;

    return(0);
}
