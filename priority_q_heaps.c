#include <stdlib.h>
#include <stdio.h>
 
typedef struct heap {
    int capacity;
    int size;
    int* elements;
} heap;
 
heap* heap_construct(int initial_capacity);
void  heap_destruct(heap* heap);
int  heap_get_capacity(heap *heap);
int  heap_get_size(heap *heap);
 
// Insert data into heap, return 1 if inserted, return 0 if size > capacity
int heap_insert(heap *heap, int data);
 
// Return the min value without deleting it
int  heap_get_min(heap *heap);
 
// Delete the min value in the heap
int heap_remove(heap *heap);
 
/* Print the values(data) in ascending order by deleting the min value node from the heap each time*/
void heap_print(heap *heap);
 
int main() {
int choice, loop = 1;
int initial_capacity = 0;
scanf("%d", &initial_capacity);
heap *my_heap = heap_construct(initial_capacity);
while(loop) {
scanf("%d", &choice);
switch(choice) {
int number_of_elements, element, index;
int data;
case 1: // Insert elements
printf("enter the element\n");
scanf("%d", &element);
if(!heap_insert(my_heap, element))
printf("OVERFLOW\n");
break;
case 2: /*Print elements in sorted order, and empties the heap. */
heap_print(my_heap);
heap_destruct(my_heap);
loop = 0;
break;
default: heap_destruct(my_heap);loop = 0;
}		
}
return 0;
}
 
heap* heap_construct(int n)
{
	int i;  
    heap *temp=(heap*)malloc(sizeof(heap));
    temp->capacity=n;
    temp->size=0;
    temp->elements=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        temp->elements[i]=0;
    return temp;
}
 
void heap_destruct(heap* tmp)
{  
}
 
int heap_get_capacity(heap* tmp)
{
    return tmp->capacity;
}
 
int heap_get_size(heap* tmp)
{
    return tmp->size;
}
 
int heap_insert(heap* tmp,int data)
{
    int i=0;
    if(tmp->size < tmp->capacity)
    {
        tmp->elements[tmp->size++]=data;
        return 1;
    }
    else 
  return 0;
}
 
int heap_get_min(heap* tmp)
{
    int min=tmp->elements[0],i;
    for(i=1;i<tmp->size;i++)
    {
        if(tmp->elements[i]<min)
            min=tmp->elements[i];
    }
    return min;
}
 
int heap_remove(heap* tmp)
{
   int min=heap_get_min(tmp),i,k;
   for(i=0;i<tmp->size;i++)
   {
       if(tmp->elements[i]==min)
       {
           for(k=i;k<tmp->size;k++)
           tmp->elements[k]=tmp->elements[k+1];
           tmp->size--;
           return min;
       }
   }
}
 
void heap_print(heap *my_heap)
{
    while(my_heap->size!=0)
    {
        int min=heap_remove(my_heap);
        printf("%d\n",min);
    }
}
