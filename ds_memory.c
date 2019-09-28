/* ds_memory.c
 * Name: Michael Dombrovsky
 * Student ID: 1040227
 * Course: CIS*2520
 */


#include "ds_memory.h"

/*Global variables*/
struct ds_file_struct ds_file;
struct ds_counts_struct ds_counts;

/**
 * Create initial header and writes it to file
 * 
 * Return values:
 *      0 -- Success
 *      1 -- Error opening file
 *      2 -- Error writing to file
 *      3 -- Error closing file
 *      4 -- Invalid size
 **/ 
int ds_create( char *filename, long size ){

    int i;

    struct ds_blocks_struct block;
    struct ds_blocks_struct blockArray [MAX_BLOCKS];
    
    char zero=0;

    FILE * fptr;

    if(size<0)
        return 4;

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
        /*Error writing file*/
        return 2;
    }

    for(i=0;i<size;i++)
    {
        if(fwrite(&zero,sizeof(zero),1,fptr)!=1){
            /*Error writing files*/
            return 2;
        }
    }

    if(fclose(fptr)!=0)
    {
        /*Error closing file*/
        return 3;
    }

    return 0;
}

/**
 * Initializes global variables
 * 
 * Return values:
 *      0 -- Success
 *      1 -- Error opening file
 *      2 -- Error reading from file
 **/
int ds_init( char *filename ){

   
    ds_file.fp=fopen(filename,"rb+");

    ds_counts.reads=0;
    ds_counts.writes=0;

    if(ds_file.fp==NULL)
    {
        /*Error opening file*/
        return 1;
    }

   if(fread(ds_file.block,sizeof(ds_file.block[0]),MAX_BLOCKS,ds_file.fp)!=MAX_BLOCKS)
    {
        /*Error reading from file*/
        return 2;
    }
    
    
    return 0;
}

/**
 * Allocates space in the header
 * 
 * Return values:
 *      block start location -- Success
 *      -1 -- Failure (no blocks availible) 
 **/
long ds_malloc( long amount ){

    int i,j;

    int found=0;

    int original;

    if(amount<0)
    {
        return -1;
    }

    /*Search through blocks for empty block*/
    for(i=0;i<MAX_BLOCKS&&found==0;i++)
    {
        if(ds_file.block[i].length>=amount && ds_file.block[i].alloced==0)
        {
            original=ds_file.block[i].length;
            ds_file.block[i].length=amount;
            ds_file.block[i].alloced=1;
            found=1;
            
        }        
      
    }
    i--;
  
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
            ds_file.block[j].length=original-amount;
            ds_file.block[j].alloced=0;
            found=1;
        }
    }

    return ds_file.block[i].start;

}

/**
 * Frees a block
 * 
 * Return values:
 *      N/A
 */ 
void ds_free( long start ){

    int i;
    
    int found=0;

    /*Search through block array*/
    for(i=0;i<MAX_BLOCKS&&!found;i++)
    {
        if(ds_file.block[i].start==start)
        {
            ds_file.block[i].alloced=0;
            found=1;
        }
    }

    return;
}

/**
 * Reads from the file
 * 
 * Return values:
 *      ptr -- Success
 *      NULL -- Failure
 **/ 
void *ds_read( void *ptr, long start, long bytes ){
    
    if(start<0)
    {
        return NULL;
    }
    
    if(ds_file.fp==NULL)
    {
        /*Error opening file*/
        return NULL;
    }

    /*Accounts for header*/
    if(fseek(ds_file.fp,start+sizeof(ds_file.block),SEEK_SET)!=0)
    {
        /*Error rewinding file*/
        return NULL;
    }

    /*Reads data*/
    if(fread(ptr,bytes,1,ds_file.fp)!=1)
    {
        /*Error reading file*/
        return NULL;
    }

    /*Increments reads*/
    ds_counts.reads++;

    /*FIX_ME IS THIS RIGHT???????*/
    return ptr;
}

/**
 * Writes to file
 * 
 * Return values:
 *      start -- Success
 *      -1 -- Failure
 **/
long ds_write( long start, void *ptr, long bytes ){
    
    if(start<0)
    {
        return -1;
    }

    if(fseek(ds_file.fp,start+sizeof(ds_file.block),SEEK_SET)!=0)
    {
        /*Error rewinding file*/
        return -1;
    }

    if(fwrite(ptr,bytes,1,ds_file.fp)!=1)
    {
        /*Error writing file*/
        return -1;
    }

    ds_counts.writes++;

    return start;
}

/**
 * Writes the new header to file
 * 
 * Return values:
 *      1 -- Success
 *      0 -- Failure
 **/
int ds_finish(){
    
    if(ds_file.fp==NULL)
    {
        /*Error with file pointer*/
        return 0;
    }

    if(fseek(ds_file.fp,0,SEEK_SET)!=0)
    {
        /*Error rewinding file*/
        return 0;
    }

    if(fwrite(ds_file.block,sizeof(ds_file.block[0]),MAX_BLOCKS,ds_file.fp)!=MAX_BLOCKS)
    {

        /*Error writing file*/
        return 0;
    }

    if(fclose(ds_file.fp)!=0)
    {
       /*Error closing file*/
        return 0;
    }

    printf("reads: %d\nwrites: %d\n",ds_counts.reads,ds_counts.writes);

    return 1;
}


/**
 * Prints out memory table
 **/ 
void ds_test_init(){
    int i;
    printf("Block #\tstart\tlength\talloced\n");
    for(i=0;i<MAX_BLOCKS&&i<16;i++)
        printf("%d\t%ld\t%ld\t%d\n",i,ds_file.block[i].start,ds_file.block[i].length,ds_file.block[i].alloced);

    printf("read = %d\nwrite = %d\n",ds_counts.reads,ds_counts.writes);
}

/**
 * Returns the amount of reads
 **/
int get_reads(){
    return ds_counts.reads;
}

/**
 * Retuns the amount of writes
 **/ 
int get_writes(){
    return ds_counts.writes;
}