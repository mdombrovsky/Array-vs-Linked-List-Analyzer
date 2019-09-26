#include <stdlib.h>
#include <stdio.h>
#include "ds_memory.h"
#include "ds_array.h"
 


int main(void){
    
       /*printf("%ld\n",sizeof(struct ds_blocks_struct));*/
       /*printf( "sizeof( struct ds_counts_struct ) = %ld\n",

              sizeof(struct ds_counts_struct ) );

       printf( "sizeof( struct ds_blocks_struct ) = %ld\n",

              sizeof(struct ds_blocks_struct ) );

       printf( "sizeof( struct ds_file_struct ) = %ld\n",

              sizeof(struct ds_file_struct ) );*/

       

       /*int ds_create_return=ds_create("test.bin",1234);

       int ds_init_return=ds_init("test.bin");
       
       int ds_malloc_return1=ds_malloc(10);
       int ds_malloc_return2=ds_malloc(10000);
       int ds_malloc_return3=ds_malloc(17);

       int ds_finish_return=ds_finish();

       ds_test_init();

       printf("ds_create return value: %d\nds_init return value: %d\nds_malloc return value: %d, %d, %d\nds_finish return value: %d",ds_create_return,ds_init_return,ds_malloc_return1,ds_malloc_return2,ds_malloc_return3,ds_finish_return);
       printf("\nDone!\n");*/

       /*
       unsigned char c1, c2;

       unsigned short s1, s2;

       unsigned int i1, i2;

       unsigned long l1, l2;

       float f1,f2;

       double d1, d2;

       

       long memory[12];     

       

       int i;

       

       c1 = 1;

       c2 = 2;

       s1 = 3;

       s2 = 4;

       i1 = 5;

       i2 = 6;

       l1 = 7;

       l2 = 8;

       f1 = 9.0;

       f2 = 10.0;

       d1 = 11.0;

       d2 = 12.0;

       


       ds_create( "test.bin", 1234);

       

       

       ds_init( "test.bin");


       memory[0] = ds_malloc( sizeof(c1) );

       ds_write( memory[0], &c1, sizeof(c1) );

       

       memory[1] = ds_malloc( sizeof(c2) );

       ds_write( memory[1], &c2, sizeof(c2) );

       

       ds_free( memory[1] );

       

       
       memory[2] = ds_malloc( sizeof(s1) );

       ds_write( memory[2], &s1, sizeof(s1) );

       

       memory[3] = ds_malloc( sizeof(s2) );

       ds_write( memory[3], &s2, sizeof(s2) );

       

       ds_free( memory[3] );

       

       

       memory[4] = ds_malloc( sizeof(i1) );

       ds_write( memory[4], &i1, sizeof(i1) );

       

       memory[5] = ds_malloc( sizeof(i2) );

       ds_write( memory[5], &i2, sizeof(i2) );

       

       ds_free( memory[5] );

       

     

       memory[6] = ds_malloc( sizeof(l1) );

       ds_write( memory[6], &l1, sizeof(l1) );

       

       memory[7] = ds_malloc( sizeof(l2) );

       ds_write( memory[7], &l2, sizeof(l2) );

       

       ds_free( memory[7] );

       



       memory[8] = ds_malloc( sizeof(f1) );

       ds_write( memory[8], &f1, sizeof(f1) );

       

       memory[9] = ds_malloc( sizeof(f2) );

       ds_write( memory[9], &f2, sizeof(f2) );

       

       ds_free( memory[9] );

       

      

       memory[10] = ds_malloc( sizeof(d1) );

       ds_write( memory[10], &d1, sizeof(d1) );

       

       memory[11] = ds_malloc( sizeof(d2) );

       ds_write( memory[11], &d2, sizeof(d2) );

       

       ds_free( memory[11] );

       

       printf( "Remaining memory allocations:\n");

       for(i=0;i<12;i+=2) 

       {

       printf( "%ld\n", memory[i] );

       }

       

       ds_test_init();

       ds_finish();

       unsigned char c1;

       unsigned short s1;

       unsigned int i1;

       unsigned long l1;

       float f1;

       double d1;

 

       long memory[6] = { 0, 2, 6, 14, 10, 30};

       

       ds_init( "test.bin");

       

       ds_read( &c1, memory[0],sizeof( c1 ) );

       ds_read( &s1, memory[1],sizeof( s1 ) );

       ds_read( &i1, memory[2],sizeof( i1 ) );

       ds_read( &l1, memory[3], sizeof( l1 ) );

       ds_read( &f1, memory[4],sizeof( f1 ) );

       ds_read( &d1, memory[5],sizeof( d1 ) );

       

       printf( "%d %d %d %ld %f %f\n", c1, s1, i1, l1, f1, d1 );

       

       ds_finish();*/
   
       int a,b,c,d,e;
       a=ds_create("array.bin",2048);
   
       b=ds_create_array();
    
     c=0;
     d=0;
     e=0;

       ds_test_init();
       printf("a:%d\nb:%d\nc:%d\nd:%d\ne:%d\n",a,b,c,d,e);


       
       
       return 0;
}