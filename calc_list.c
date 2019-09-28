#include <stdio.h>
#include <stdlib.h>
#include "ds_memory.h"
#include "ds_list.h"

void generateFile(int elements){

    FILE *fptr;
    int i;
    fptr=fopen("elements.txt","w");
    for(i=0;i<elements;i++)
        fprintf(fptr,"%d\n",rand()%100+1);
    fclose(fptr);

}

int main (void){


    FILE *fptr;


    int i;
    int j;
    int elements;

    elements=0;
    
    fptr=fopen("swap_list.csv","w");

    fprintf(fptr, "\"Reads\",\"Writes\"\n");


    for(j=0;j<10;j++){
        elements+=10;
        for(i=0;i<30;i++){
            
            if(ds_create("list.bin",2048)!=0)
            {
                printf("ds_create\n");
                return 0;
            }
            if(ds_create_list()!=0)
            {
                printf("ds_create_list\n");
                return 0;
            }
            
            if(ds_init_list()!=0)
            {
                printf("ds_init_list\n");
            }
            generateFile(elements);
 

            if(ds_read_elements("elements.txt")!=0)
            {
                printf("ds_read_elements\n");
            }
          
            if(ds_swap(rand()%elements,rand()%elements)!=0)
            {
                printf("ds_thing\n");
            }

            if(ds_finish_list()!=0)
            {
                printf("ds_finish\n");
            }
            fprintf(fptr, "\"%d\",\"%d\"\n",get_reads(),get_writes());

           
        }
         printf("\nDone list with %d elements\n\n",elements);
    }
    fclose(fptr);
    printf("\nDone\n");
    return 0;



}