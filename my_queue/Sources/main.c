/*
 ============================================================================
 Name        : main.c
 Author      : cph
 Version     : 1.0
 Copyright   : Copyright from Chi Pham Hoang
 Description : test myqueue.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "myqueue.h"

void element_print(element_t element);
void element_copy(element_t *dest_element, element_t src_element);
void element_free(element_t *element);

int main( void )
{	
   element_t *p=NULL;   
   queue_t* queue = NULL;  
   
   /* 
   int* copied_element = (int *)malloc(sizeof(int)); 	
   int* a = (int *)malloc(sizeof(int));
   int* b = (int *)malloc(sizeof(int));
   int* c = (int *)malloc(sizeof(int));   
   
   *a = 1;
   *b = 2;
   *c = 3;  
 
  queue = queue_create();  
  
  queue_enqueue(queue, (element_t)a);
  queue_enqueue(queue, (element_t)b);
  queue_enqueue(queue, (element_t)c);  
  
  queue_print(queue);    
  printf("Current size of the queue: %d\n", queue_size(queue));
  p= queue_top(queue);
  if(p != NULL)
  {
	  printf("Top element: ");
	  element_print(p);
	  printf("\n");
  }
  else
  {
	  printf("Queue is empty - Top element: NULL\n");
  }
  
  element_copy((element_t *)copied_element,*p);
  printf("Coppied element value: %d\n",*copied_element);
  printf("Free copyied element\n");
  element_free((element_t *)copied_element);
  
  queue_dequeue(queue);
  queue_print(queue);
  printf("Current size of the queue: %d\n", queue_size(queue));
  p= queue_top(queue);  
  if(p != NULL)
  {
	  printf("Top element: ");
	  element_print(p);
	  printf("\n");
  }  
  
  queue_dequeue(queue);
  queue_print(queue);
  printf("Current size of the queue: %d\n", queue_size(queue));
  p= queue_top(queue);
  if(p != NULL)
  {
	  printf("Top element: ");
	  element_print(p);
	  printf("\n");
  }   
  
  
  queue_dequeue(queue); 
  queue_print(queue);
  printf("Current size of the queue: %d\n", queue_size(queue)); 
  
  queue_free(&queue);    
  free(a);
  free(b);
  free(c);   
  */
  
  printf("\n=========================================\n"); 
  float* copied_element = (float *)malloc(sizeof(float));     	
  float* d = (float *)malloc(sizeof(float));
  float* e = (float *)malloc(sizeof(float));
  float* f = (float *)malloc(sizeof(float));   
   
   *d = 1.1;
   *e = 2.2;
   *f = 3.3;  
 
  queue = queue_create();  
  
  queue_enqueue(queue, (element_t)d);
  queue_enqueue(queue, (element_t)e);
  queue_enqueue(queue, (element_t)f);
  queue_print(queue);  
  printf("Current size of the queue: %d\n", queue_size(queue));
    
  queue_dequeue(queue);
  queue_print(queue);
  printf("Current size of the queue: %d\n", queue_size(queue));  
  p= queue_top(queue);  
  if(p != NULL)
  {
	  printf("Top element: ");
	  element_print(*p);
	  printf("\n");
  }   
  
  queue_dequeue(queue);
  queue_print(queue);
  printf("Current size of the queue: %d\n", queue_size(queue));    
  p= queue_top(queue);
  if(p != NULL)
  {
	  printf("Top element: ");
	  element_print(*p);
	  printf("\n");
  }  
  
  //element_copy((element_t *)copied_element,*p);
  //printf("Coppied element value: %f\n",*copied_element);
  //free(copied_element);
  
  queue_dequeue(queue); 
  printf("Current size of the queue: %d\n", queue_size(queue));   
  queue_print(queue);    
  
  queue_free(&queue);    
  free(d);
  free(e);
  free(f);
  
  printf("\n=========================================\n");
  return 0;
}


/*
 * Implement here private functions to copy, to print and to destroy an element. Do you understand why you need these functions? 
 * Later you will learn how you could avoid this by using funtion pointers. 
 * 
 */

/*
 * Print 1 element to stdout. 
 * If the definition of element_t changes, then this code needs to change as well.
 */
void element_print(element_t element)
{
  // implementation goes here    
  //printf("%5d", *(int *) element);  
  printf("%5.2f", *(float *) element);
}

/*
 * Copy the content (e.g. all fields of a struct) of src_element to dst_element.
 * dest_element should point to allocated memory - no memory allocation will be done in this function
 * If the definition of element_t changes, then this code needs to change as well.
 */
void element_copy(element_t *dest_element, element_t src_element)
{
  // implementation goes here
  *dest_element = src_element;
}

/*
 * Free the memory allocated to an element (if needed)
 * If the definition of element_t changes, then this code needs to change as well.
 */
void element_free(element_t *element)
{
  // implementation goes here
  if(element == NULL)
  {
	  printf("The element has been free already! \n");
  }
  else
  {
	  free(element);	
  }  
	
    /*
	//Check if the queue is empty
	if(queue->current_size == 0)
	{
		//Queue is empty
		printf("\nQueue is empty !!!");
		return;
	}	
	
	int index=-1;
	int i=0;	
	//Check if the element is belongs to the queue
	int temp = queue->front;
	for(i=0; i < queue->current_size; i++)
	{
		if((temp + i) == QUEUE_SIZE) { temp = -1;}
		
		if((&(queue->arr[temp + i]) - element) == 0)
		{
			index = temp + i;
			if(index == QUEUE_SIZE) { index = 0;}
			break;
		}			
	}
	
	if( index == -1)
	{
		printf("The element is not belong to the queue\n");
	}
	else
	{
		temp = index;
		i=0;
		while(temp+i != queue->rear)		
		{	
			if( temp+i+1 == QUEUE_SIZE) { queue->arr[temp+i] = queue->arr[0];}
			else {	queue->arr[temp+i] = queue->arr[temp+i+1]; }
			i++;
			if((temp + i) == QUEUE_SIZE) { temp = -1;}
		}
		
		queue->rear--;
		if(queue->rear == -1) {queue->rear = QUEUE_SIZE - 1;}
		queue->current_size--;
	}
	*/
	
}
