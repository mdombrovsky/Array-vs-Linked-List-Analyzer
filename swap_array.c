#include<stdio.h>

#include <stdlib.h>

#include"ds_array.h"

 

int main( int argc, char**argv )

{
 

    if(argc!=3)
    { 

        fprintf( stderr,"Usage:  %s [index] [index]", argv[0] );

        return-1;
    }

    ds_init_array();
    printf("\nswap return: %d\n",ds_swap(atoi(argv[1]),atoi(argv[2])));
    ds_finish_array();

 
 

  return 0;

}