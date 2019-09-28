#include<stdio.h>

#include <stdlib.h>

#include"ds_list.h"

 

int main( int argc, char**argv )

{
 

    if(argc!=2)
    { 

        fprintf( stderr,"Usage:  %s [filename.txt]", argv[0] );

        return-1;
    } 

    printf("init: %d\n",ds_init_list());
    printf("read: %d\n",ds_read_elements(argv[1]));
    printf("finish: %d\n", ds_finish_list());
  return 0;

}