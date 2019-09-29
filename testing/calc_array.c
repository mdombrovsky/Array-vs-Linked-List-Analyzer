#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ds_memory.h"
#include "ds_array.h"

void generateFile(int elements){

    FILE *fptr;
    int i;
    fptr=fopen("elements.txt","w");
    for(i=0;i<elements;i++)
        fprintf(fptr,"%d\n",rand()%100+1);
    fclose(fptr);

}

int main (int argc, char**argv){


    FILE *fptr;
    int option;

    int i;
    int j;
    int elements;
    int reads[30][10];
    int writes[30][10];
    char fileName[100];

    elements=0;

    if(argc!=2)
    { 

        fprintf( stderr,"Usage:  %s [1-4]\n", argv[0] );

        return-1;
    }
    else{
        option=atoi(argv[1]);
        if(option>4||option<0)
        {
            fprintf( stderr,"Usage:  %s [1-4]\n", argv[0] );
            return -1;
        }
    }

    switch(option){
        case 1:
            strcpy(fileName,"../graphs/replace_array.csv");
            break;
        case 2:
            strcpy(fileName,"../graphs/insert_array.csv");
            break;
        case 3:
            strcpy(fileName,"../graphs/delete_array.csv");
            break;
        case 4:
            strcpy(fileName,"../graphs/swap_array.csv");
            break;
        default:
            fprintf( stderr,"Unrecoverable error");
            return -1;
    }


    fptr=fopen(fileName,"w");

    for(i=10;i<=100;i+=10)
    {
        if(i!=10)
        {
            fprintf(fptr, ",");
        }
        
        fprintf(fptr, "\"Reads n=%d\",\"Writes n=%d\"",i,i);

        if(i==100)
        {
            fprintf(fptr, "\n");
        }
    }
    


    for(j=0;j<10;j++){
        elements+=10;
        for(i=0;i<30;i++){
            
            if(ds_create("array.bin",2048)!=0)
            {
                printf("ds_create\n");
                return 0;
            }
            if(ds_create_array()!=0)
            {
                printf("ds_create_list\n");
                return 0;
            }
            
            if(ds_init_array()!=0)
            {
                printf("ds_init_list\n");
            }
            generateFile(elements);
 

            if(ds_read_elements("elements.txt")!=0)
            {
                printf("ds_read_elements\n");
            }
          

            reads[i][j]=get_reads();
            writes[i][j]=get_writes();


            switch(option){
                case 1:
                    if(ds_replace(0,rand()%elements)!=0)
                    {
                        printf("ds_thing\n");
                    }
                    break;
                case 2:
                    if(ds_insert(0,rand()%elements)!=0)
                    {
                        printf("ds_thing\n");
                    }
                    break;
                case 3:
                    if(ds_delete(rand()%elements)!=0)
                    {
                        printf("ds_thing\n");
                    }
                    break;
                case 4:
                    if(ds_swap(rand()%elements,rand()%elements)!=0)
                    {
                        printf("ds_thing\n");
                    }
                    break;
                default:
                    fprintf( stderr,"Unrecoverable error");
                    return -1;
            }


  

            if(ds_finish_array()!=0)
            {
                printf("ds_finish\n");
            }
            
           reads[i][j]=get_reads()-reads[i][j];
           writes[i][j]=get_writes()-writes[i][j];

           
        }
         printf("\nDone list with %d elements\n\n",elements);
    }

    for(i=0;i<30;i++)
    {
      
        for(j=0;j<10;j++)
        {
            if(j!=0)
            {
                fprintf(fptr,",");
            }
            fprintf(fptr, "\"%d\",\"%d\"",reads[i][j],writes[i][j]);
        }
        
        
        fprintf(fptr,"\n");
    
        
    }
    

    fclose(fptr);
    printf("\nDone\n");
    return 0;



}