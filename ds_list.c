/* ds_list.c
 * Name: Michael Dombrovsky
 * Student ID: 1040227
 * Course: CIS*2520
 */

#include "ds_list.h"
#include "ds_memory.h"

/**
 * Creates linked list
 * 
 * Return values: 
 *      0 -- Success
 *      1X -- Initialization error
 *      20 -- Error allocating memory
 *      30 -- Error writing
 *      4X -- Error finishing
 **/
int ds_create_list(){
    
    int error;
    long output=-1;

    error=ds_init("list.bin");
    if(error!=0)
        return error+10;

    error=ds_malloc(sizeof(long));
    if(error==-1)
            return 20;
         
    error=set_head(output);
    if(error==1)
        return 30;

    error=ds_finish();
    if(error!=1)
        return error+40;
    return 0;
}

/**
 * Initalizes linked list
 * 
 * Return values:
 *      0 -- Success
 *      1 -- Error opening file
 *      2 -- Error reading from file
 **/ 
int ds_init_list(){
    return ds_init("list.bin");
}

/**
 * Sets the value at an index of the linked list
 * 
 * Return values:
 *      0 -- Success
 *      1 -- Index out bounds
 *      2 -- Error reading head
 *      3 -- Error list is empty
 *      4 -- Error writing replaced node
 *      1X -- Error creating first node
 *      2X -- Error traversing list
 *  
 *      
 **/
int ds_replace( int value, long index ){

    long head;
    int error;
    listNode node;
    long address;

    if(index<0)
        return 1;

    error=get_head(&head);
    if(error!=0)
        return 2;

    /*If no elements in list*/
    if(head==-1)
    {
        if(index!=0)
            return 3;

        error=write_first_node(value,-1);
        if(error!=0)
            return error+10;
        return 0;
      
    }

    /*If list not empty*/
    else{

        address=traverse_list(&node,sizeof(long),index);
        if(address<0)
            return 20+address*(-1);
        
        node.item=value;
        error=write_node(address,node);
        if(error==-1)
            return 4;
        
        return 0;
    }
   

}

/**
 * Inserts node 
 * 
 * Return values:
 *      0 -- Success
 *      1 -- Index out of bounds
 *      2 -- Error reading head
 *      3 -- Error list is empty, but index is not 0
 *      4 -- Error changing next value of previous node
 *      1X -- Error writing first node
 *      2X -- Error traversing list to previous node
 *      3X -- Error creating new node
 *      4X -- Error getting address of subsequent node
 *      5X -- Error creating new node
 *      
 **/
int ds_insert( int value, long index ){

    listNode priorNode;
    listNode futureNode;
    long head;
    long previousAddress;
    long newAddress;
    long futureAddress;
    int error;

    if(index<0)
        return 1;

    error=get_head(&head);
    if(error!=0)
        return 2;

    /*If list is empty*/
    if(head==-1)
    {   
        if(index!=0)
        {
            return 3;
        }
        error=write_first_node(value,-1);
        if(error!=0)
        {   
            return error+10;
        }

        return 0;
    }
    /*If list is not empty*/
    else{

        /*If want to insert into first index*/
        if(index==0){
            /* Creates new first node 
             * and sets it next to the 
             * previous nodes' address*/
            error=write_first_node(value,head);
            if(error!=0)
            {   
                return error+10;
            }  
            return 0;

        }

        /*If inserting to non-leading node*/
        else{

            /*Gets address of node before index*/
            previousAddress=traverse_list(&priorNode,head,index-1);
            if(previousAddress<0)
                return 20+previousAddress*(-1);

            

            /*Adding to end of list*/
            if(priorNode.next==-1){

                /*Creates new node*/
                newAddress=create_node(value,-1);
                if(newAddress<0)
                {
                    return newAddress*(-1)+30;
                }

          

            }

            /*Adding to middle of list*/
            else{

                /*Gets address of next node*/
                futureAddress=traverse_list(&futureNode,previousAddress,1);
                if(futureAddress<0)
                {
                    return futureAddress*(-1)+40;
                }

                /*Creates new node*/
                newAddress=create_node(value,futureAddress);
                if(newAddress<0)
                {
                    return newAddress*(-1)+50;
                }
                
                
                
            }
                /*Saves new nodes address into the previous node*/
                priorNode.next=newAddress;
                error=write_node(previousAddress,priorNode);
                if(error!=0)
                    return 4;
                return 0;

        }


    }

}

/**
 * Deltes a node at the specified index
 * 
 * Return values:
 *      0 -- Success
 *      1 -- Error getting head
 *      2 -- Error traversing to node
 *      3 -- Error setting new head
 *      4 -- Error traversing to prior node
 *      5 -- Error traversing to node
 *      6 -- Index out of bounds
 **/
int ds_delete( long index ){

    long head;
    long address;
    long previousAddress;
    int error;
    listNode node;
    listNode previousNode;

    if(index<0)
        return 6;

    error=get_head(&head);
    if(error!=0)
        return 1;



    /*If it is at front of list*/
    if(index==0)
    {
        /*Gets node to be deleted*/
        address=traverse_list(&node,head,index);
        if(address<0)
            return 2;

        error=set_head(node.next);
        if(error!=0)
            return 3;
        ds_free(address);
    }
    /*Not first*/
    else
    {   
        /*Gets prior node*/
        previousAddress=traverse_list(&previousNode,head,index-1);
        if(previousAddress<0)
            return 4;

        address=traverse_list(&node,previousAddress,1);
        if(address<0)
            return 5;
        previousNode.next=node.next;
        ds_free(address);


    }
    return 0;

}

/**
 * Swaps two elements in linked list
 * 
 * Return values:
 *      0 -- Succes
 *      1 -- Index 1 out of bounds
 *      2 -- Index 2 out of bounds
 *      3 -- Error writing node
 *      1X -- Error reading node
 **/ 
int ds_swap( long index1, long index2 ){

    long tempIndex;
    int temp;
    long head;
    long address1;
    long address2;
    listNode node1;
    listNode node2;
    int error;

    if(index1<0)
        return 1;
    if(index2<0)
        return 2;
    if(index1==index2)
        return 0;

    /* Want to make index1 smaller than index2
     * to use least amount of reads
     */
    if(index1>index2)
    {
        tempIndex=index1;
        index1=index2;
        index2=tempIndex;
    }

    error=get_head(&head);

    address1=traverse_list(&node1,head,index1);
    if(address1<0)
        return 10+address1*(-1);
    
    address2=traverse_list(&node2,address1,index2-index1);
    if(address2<0)
        return 10+address2*(-1);

    temp=node1.item;
    node1.item=node2.item;
    node2.item=temp;

    error=write_node(address1,node1);
    if(error!=0)
        return 3;

    error=write_node(address2,node2);
    if(error!=0)
        return 3;
    
    return 0;
}

/**
 * Searches for target
 * 
 * Return valies:
 *      address -- Success
 *      -1 -- Failure
 **/  
long ds_find( int target ){
    long address;
    int error;
    int count;
    listNode node;
    
    /*Gets head*/
    error=get_head(&address);
    if(error!=0)
        return -1;

    count=0;

    do{
        /*Reads in node*/
        error=traverse_list(&node,address,0);
        if(error<0)
            return -1;

        if(node.item==target)
        {
            /*Success*/
            return count;
        }
        count++; 
        address=node.next;
    }while(address!=-1);

    return -1;

}

/**
 * Reads elements from text file and puts them into list
 * 
 * Return values:
 *      0 -- Success
 *      1 -- Error opening file
 *      2 -- Error getting head
 *      3 -- Error creating node
 *      4 -- Error setting head
 **/
int ds_read_elements( char *filename ){
    FILE *fptr;
    int temp;
    int error;  
    int read; 
    long address;
    long newAddress;
    long head;
    listNode node;

    
    
    /*Opens file*/
    fptr=fopen(filename,"r");

    if(fptr==NULL)
    {
        /*Error opening file*/
        return 1;
    }
   
    /*Gets head*/
    error=get_head(&head);
    if(error<0)
        return 2;

    /*Gets last element*/
    if(head!=-1)
    {
        address=traverse_list(&node,head,-1);
    }

    do{
        /*Reads from file*/
        read=fscanf(fptr, "%d", &temp);

        /*If one element is read in*/
        if(read==1)
        {
            
            newAddress=create_node(temp,-1);
            if(newAddress<0)
                return 3;

            /*If first element*/
            if(head==-1)
            {
                head=newAddress;
                error=set_head(newAddress);
                if(error!=0)
                    return 4;
            }
            /*If elemnts already present*/
            else
            {
                node.next=newAddress;
                error=write_node(address,node);
                if(error!=0)
                    return 5;
            }

            address=newAddress;

        }
        

    }while(read!=EOF);

    return 0;
}


/**
 * Finishes off
 * 
 * Return values:
 *      0 -- Success
 *      1 -- Error finishing
 **/
int ds_finish_list(){

    int error;
    error=ds_finish();
    
    if(error!=1)
        return 1;

    return 0;
}

/**
 * Traverses a linked list
 * If traversals == -1 then go to last
 * 
 * Return values: 
 *      Address of desired node -- Success
 *      -1 -- Adress out of bounds
 *      -2 -- Failure to read next element
 *      -3 -- Coding error
 **/ 
long traverse_list(listNode *ptr, long address,int traversals){
    
    int i;
    listNode node;
    long currentAddress;
    


    if(address<0)
        return -1;

    currentAddress=address;


    for(i=0;(i<=traversals)||(traversals==-1);i++)
    {
        /*Reads node at address*/
        if(ds_read(&node, currentAddress,sizeof(node))==NULL)
        {
            return -2;
        }

        /*If right amount of traversals*/
        if(i==traversals||((traversals==-1)&&(node.next==-1)))
        {
            ptr=&node;
            return currentAddress;
        }


        /*Incrememnts address*/
        currentAddress=node.next;
    }

    return -3;
}

/**
 * Writes the first element of the linked list
 * 
 * Return values:
 *      0 -- Success
 *      1 -- Unable to read head
 *      2 -- First node already present
 *      3 -- Error allocating space
 *      4 -- Error writing node
 *      5 -- Error writing new head
 **/ 
int write_first_node(int value, long next){

    long head;
    int error;
    long address;

    error=get_head(&head);
    if(error!=0)
        return 1;

    /*Checks that there are no nodes*/
    if(head!=-1)
        return 2;
    
    address=create_node(value,next);
    if(address<0)
        return address*(-1)+2;

    /*Replaces value of head*/
    error=set_head(address);
    if(error==1)
        return 5;
    
    return 0;

}

/**
 * Creates node at specified address
 * 
 * Return values: 
 *      Address -- Success
 *      -1 -- Error allocating memory
 *      -2 -- Error writing node
 **/
long create_node(int value, long next){
    int error;
    long address;
    listNode node;
    
    node.item=value;
    node.next=next;

    address=ds_malloc(sizeof(listNode));
    if(address==-1)
        return -1;
    
    error=write_node(address, node);
    if(error==-1)
        return -2;
    
    return address;
}

/**
 * Changes values of a node
 * 
 * Return values:
 *      0 -- Success
 *      1 -- Error writing node
 **/ 
int write_node(long address, listNode node){
   
    int error;
    
    error=ds_write(address,&node,sizeof(node));
    if(error==-1)
        return 1;
    return 0;
    
}

/**
 * Gets the head
 * 
 * Return values:
 *      0 -- Success
 *      1 -- Failure
 **/
int get_head(void *ptr){
    if(ds_read(ptr,0,sizeof(long))==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
    return 1;
}

/**
 * Sets the head
 * 
 * Return values: 
 *      0 -- Success
 *      1 -- Failure
 **/
int set_head(long address){
    /*Replaces value of head*/
    if(ds_write(0,&address,sizeof(address))==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    return 1;
}