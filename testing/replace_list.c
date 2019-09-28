#include<stdio.h>

#include <stdlib.h>

#include"ds_list.h"

 

int main( int argc, char**argv )

{
 

    if(argc!=3)
    { 

        fprintf( stderr,"Usage:  %s [value] [index]", argv[0] );

        return-1;
    }

    printf("\ninit: %d\n",ds_init_list());
    printf("replace return: %d\n",ds_replace(atoi(argv[1]),atoi(argv[2])));
    printf("finish: %d\n", ds_finish_list());

 
 

  return 0;

}