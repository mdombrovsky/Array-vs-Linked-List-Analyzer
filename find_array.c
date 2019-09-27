#include<stdio.h>

#include <stdlib.h>

#include"ds_array.h"

 

int main( int argc, char**argv )

{
 
    if(argc!=2)
    { 

        fprintf( stderr,"Usage:  %s [element]", argv[0] );

        return-1;
    }

    ds_init_array();
    printf("\nfind return: %ld\n",ds_find(atoi(argv[1])));
    ds_finish_array();

 
 

  return 0;

}