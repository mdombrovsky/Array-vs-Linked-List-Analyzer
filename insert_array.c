#include<stdio.h>

#include <stdlib.h>

#include"ds_array.h"

 

int main( int argc, char**argv )

{

  int value;

  long index;

 

  if(argc!=3)

  { 

    fprintf( stderr,"Usage:  %svalue index\n", argv[0] );

    return-1;

  }

  

  value = atoi( argv[1] );

  index = atol( argv[2] );

 

  printf("init: %d\n",ds_init_array());

  printf("insert: %d\n",ds_insert( value, index ));

  printf("finish: %d\n",ds_finish_array());

 

  return 0;

}