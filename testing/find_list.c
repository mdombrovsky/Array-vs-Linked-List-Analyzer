#include<stdio.h>

#include <stdlib.h>

#include"ds_list.h"

 

int main( int argc, char**argv )

{
 

    if(argc!=2)
    { 

        fprintf( stderr,"Usage:  %s [index]", argv[0] );

        return-1;
    }

    printf("init: %d\n",ds_init_list());
    printf("find return: %ld\n",ds_find(atoi(argv[1])));
    printf("finish: %d\n",ds_finish_list());

 
 

  return 0;

}