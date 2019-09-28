/* ds_array.c
 * Name: Michael Dombrovsky
 * Student ID: 1040227
 * Course: CIS*2520
 */

#include "ds_array.h"
#include "ds_memory.h"

long elements;

#define MAX_ELEMENTS 256

/**
 * Creates array
 * 
 * Return values:
 *      0 -- Success
 *      1X -- Initialization error
 *      20 -- Error allocating memory
 *      30 -- Error allocating memory
 *      40 -- Error writing
 *      5X -- Error finishing
 **/ 
int ds_create_array(){

    int error;
    int output=0;

    error=ds_init("array.bin");

    if(error!=0)
        return error+10;
    
    error=ds_malloc(sizeof(elements));

    if(error==-1)
        return 20;

    error=ds_malloc(sizeof(int)*MAX_ELEMENTS);

    if(error==-1)
        return 30;

    error=ds_write(0,&output,sizeof(elements));
    
    if(error==-1)
        return 40;
        
    error=ds_finish();
    
    if(error!=1)
        return error+50;

    return(0);
}

/**
 * Initializes array
 * 
 * Return values:
 *      0 -- Success
 *      1X -- Initialization error
 *      20 -- Error reading
 **/ 
int ds_init_array(){

    int input;
    int error;

    error=ds_init("array.bin");

    if(error!=0)
    {
        return error+10;
    }

    if(ds_read(&input,0,sizeof(elements))==NULL)
    {
        return 20;
    }

    elements=input;
    return 0;
}

/**
 * Sets the value at an index of the array
 * 
 * Return values:
 *      0 -- Success
 *      1 -- Invalid index
 *      2 -- Writing error
 **/
int ds_replace( int value, long index ){

    int error;


    if(index>=MAX_ELEMENTS||index<0)
        return 1;

    error=ds_write(get_index_start_array(index),&value,sizeof(value));

    if(error==-1)
        return 2;

    return 0;

}

/**
 * Insert element into array
 * 
 * Return values: 
 *      0 -- Success
 *      10 -- No space in array
 *      2X -- Error writing
 *      30 -- Error reading
 *      4X -- Error writing in recurive portion
 *      50 -- Adding past end of array
 *      
 **/ 
int ds_insert( int value, long index ){
    
    int temp;
    int error;

    if(elements>=MAX_ELEMENTS)
    {   
        /*No space in array*/
        return 10;
    }

    if(elements<index)
    {
        /*Cannot add past the array*/
        return 50;
    }


    /*Base case*/
    if(index==elements)
    {

        
        /*If nothing in index*/
        /*Write value to that location*/
        error=ds_replace(value,index);
        
        if(error!=0)
            return error+20;
        
        /*Incrmements counter*/
        elements++;

        return 0;
    
    }
    /*Recursive case*/
    else
    {
        /*If index is non-empty*/
        /*Read value into temp*/
        if(read_int_in_array(&temp,(index))==NULL)
        {
            return 30;  
        }    

        /*Put value into current index*/
        error=ds_replace(value,index);
        if(error!=0)
            return error+40;

        /*Recursivley find a spot for temp*/
        error=ds_insert(temp,index+1);
        if(error!=0)
            return error;
    }
    return error;
}

/**
 * Deletes the value at an index
 * 
 * Return values;
 *      0 -- Success
 *      10 -- Error reading
 *      2X -- Error writing
 *      30 -- Recursive error (should never happen)
 */
int ds_delete( long index ){

    int temp; 
    int error; 
    
    /*Base case*/
    if(index==elements-1)
    {
        /*Delete last element*/
        elements--;
        return 0;
    }

    /*Recursive case*/
    else
    {
       
        if(read_int_in_array(&temp,(index+1))==NULL)
            return 10;
        
        error= ds_replace(temp,index);
        if(error!=0)
            return error+20;

        error=ds_delete(index+1);
        if(error!=0)
            return error;

    }

    return error;

}

/**
 * Swaps two elements
 * 
 * Return value:
 *      0 -- Success
 *      10 -- Index 1 out of bound
 *      20 -- Index 2 out of bound
 *      30 -- Error reading from index 1
 *      40 -- Error reading from index 2
 *      5X -- Error writing to index 1
 *      6X -- Error writing to index 2
 **/
int ds_swap( long index1, long index2 ){

    int value1;
    int value2;
    int error;

    if(index1>=elements||index1<0)
        return 10;

    if(index2>=elements||index2<0)
        return 20;

    /*Gets value 1*/
    if(read_int_in_array(&value1,(index1))==NULL)
        return 30;

    if(read_int_in_array(&value2,(index2))==NULL)
        return 40;

    /*Puts value 1 into index 2*/
    error= ds_replace(value2,index1);
    if(error!=0)
        return error+50;

    /*Puts value 1 into index 2*/
    error= ds_replace(value1,index2);
    if(error!=0)
        return error+60;

    return 0;
}

/**
 * Searches the array for an element
 * 
 * Return values:
 *      index -- Success
 *      -1 -- Failure
 **/
long ds_find( int target ){
    int i;
    int temp;

    for(i=0;i<elements;i++)
    {
        read_int_in_array(&temp, i);
        if(target==temp)
            return i;
    }
    return -1;
}

/**
 * Reads elements from text file and puts them into array
 * 
 * Return values:
 *      0 -- Success
 *      10 -- Error opening file
 *      20 -- Too many elements in file
 *      3X -- Error inserting file
 **/ 
int ds_read_elements( char *filename ){
    FILE *fptr;
    int temp;
    int error;
    int read;    
    /*Opens file*/
    fptr=fopen(filename,"r");

    if(fptr==NULL)
    {
        /*Error opening file*/
        return 10;
    }
   
    do{
        /*Reads from file*/
        read=fscanf(fptr, "%d", &temp);

        /*If one element is read in*/
        if(read==1){

            /*If array is already full*/
            if(elements==MAX_ELEMENTS)
            {
                return 20;
            }

            /*Insert element into end of array*/
            error=ds_insert(temp,elements);

            /*If there is error with ds_insert*/
            if(error!=0)
            {
                return error+30;
            }
        }

    }while(read!=EOF);

    return 0;

}

/**
 * Writes the header to file
 * 
 * Return values:
 *      0 -- Success
 *      1 -- Error writing
 *      2 -- Error finishing
 **/
int ds_finish_array(){
    int error;
    
    error=ds_write(0,&(elements),sizeof(elements));
    if(error==-1)
        return 1;

    error=ds_finish();
    
    if(error!=1)
        return 2;

    return 0;
}

/**
 * Calculates the index with which do call ds_read
 * 
 * Return values:
 *      long -- Correct index with which to call ds_read
 *      
 **/
long get_index_start_array(int index){
    return sizeof(elements)+(index)*sizeof(int);
}

/**
 * Reads array elements from the file
 * 
 * Return values:
 *      ptr -- Success
 *      NULL -- Failure
 **/ 
void* read_int_in_array(void *ptr, long index){
    return ds_read(ptr, get_index_start_array(index),sizeof(int));
}

/**
 * Shows contents of the array
 **/ 
void show_array(){
    int i;
    int temp;
    ds_test_init();
    printf("elements: %ld\n", elements); 
    for(i=0;i<elements;i++)
    {   
        read_int_in_array(&temp,i);
    
        printf("element [%d] = %d\n",i,temp);
    }
}