#include <stdlib.h>
#include <stdio.h>
#include "ds_memory.h"
#include "ds_list.h"
 


int main(void){
    
       

   
       int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0;
       a=ds_create("list.bin",2048);
   
       b=ds_create_list();
       
       c=ds_init_list();
   
       d=ds_read_elements("elements.txt");
       show_list();
       e=ds_finish_list();

       
       printf("a:%d\nb:%d\nc:%d\nd:%d\ne:%d\nf:%d\ng:%d\nh:%d\ni:%d\nj:%d\n",a,b,c,d,e,f,g,h,i,j);


       
       
       return 0;
}