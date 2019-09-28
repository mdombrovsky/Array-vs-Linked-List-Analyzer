#include<stdio.h>

#include <stdlib.h>

#include"ds_array.h"

 

int main( int argc, char**argv )

{
 

    if(argc!=2)
    { 

        fprintf( stderr,"Usage:  %s [filename.txt]", argv[0] );

        return-1;
    } 

    ds_init_array();
    ds_read_elements(argv[1]);
    ds_finish_array();
  return 0;

}