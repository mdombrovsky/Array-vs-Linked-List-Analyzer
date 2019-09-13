/* ds_memory.c
 * Name: Michael Dombrovsky
 * Student ID: 1040227
 * Course: CIS*2520
 */


#include "../includes/ds_memory.h"

/*Global variables*/
struct ds_file_struct ds_file;
struct ds_counts_struct ds_counts;


int ds_create( char *filename, long size ){

    int i;

    struct ds_blocks_struct block;
    struct ds_blocks_struct blockArray [MAX_BLOCKS];

    char zero=0;

    FILE * fptr;

    block.start=0;
    block.length=size;
    block.alloced=0;

    /*Populates blocks*/
    for(i=0;i<MAX_BLOCKS;i++)
    {
        blockArray[i].start=block.start;
        blockArray[i].length=block.length;
        blockArray[i].alloced=block.alloced;

        if(block.length!=0)
            block.length=0;        
    }

    /*Opens file*/
    fptr=fopen(filename,"wb");

    if(fptr==NULL)
    {
        /*Error opening file*/
        return 1;
    }

    if(fwrite(blockArray,sizeof(blockArray[0]),MAX_BLOCKS,fptr)!=MAX_BLOCKS)
    {
        /*Error writing files*/
        return 2;
    }

    if(fwrite(&zero,sizeof(zero),size,fptr)!=size){
        /*Error writing files*/
        return 2;
    }

    if(fclose(fptr)!=0)
    {
        /*Error closing file*/
        return 3;
    }

    return 0;
}

int ds_init( char *filename ){

    ds_file.fp=fopen(filename,"rb");

    ds_counts.reads=0;
    ds_counts.writes=0;

    if(ds_file.fp==NULL)
    {
        /*Error opening file*/
        return 1;
    }

    if(fread(ds_file.block,MAX_BLOCKS,sizeof(ds_file.block[0]),ds_file.fp)!=MAX_BLOCKS)
    {
        /*Error reading from file*/
        return 2;
    }
    
    if(fclose(ds_file.fp)!=0)
    {
        /*Error closing file*/
        return 3;
    }
    
    return 0;
}

long ds_malloc( long amount ){

    int i,j;

    int found=0;


    /*Search through blocks for empty block*/
    for(i=0;i<MAX_BLOCKS&&!found;i++)
    {
        if(ds_file.block[i].length>=amount && ds_file.block[i].alloced==0)
        {
            ds_file.block[i].length=amount;
            ds_file.block[i].alloced=1;
            found=1;
            
        }
    }

    if(!found)
    {
        /*If no blocks are found*/
        return -1;
    }
    
    /*Search for second block*/
    found=0;
    for(j=0;j<MAX_BLOCKS&&!found;j++)
    {
        if(ds_file.block[j].length==0)
        {
            ds_file.block[j].start=ds_file.block[i].start+amount;
            ds_file.block[j].length=ds_file.block[i].length-amount;
            ds_file.block[j].alloced=0;
            found=1;
        }
    }

    return ds_file.block[i].start;

}
