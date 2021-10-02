#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct heap
{
	int data;
	int priority;
};
typedef struct heap heap_t;

void read_Array(heap_t*, int);
void insert(heap_t*, int);
void heapify(heap_t*, int, int);
void display_Array(heap_t*, int);
void swap(heap_t*, heap_t*);
int delete_Min(heap_t* array, int* n);
int main()
{
	int n ,ch;

	heap_t queue[MAX];
	printf("Enter the number of elements\n");
	scanf("%d", &n);

	while(1)
	{
		printf("Enter the choice\n");	
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: read_Array(queue, n);
					break;

			case 2: insert(queue, n);
					break;

			case 3: display_Array(queue, n);
					break;

			case 4: delete_Min(queue, &n);
					break;
		}
	}
}

void heapify(heap_t* array, int n, int position)
{
	int i;
	int j;
	i = position;
	j = 2 * i;
	int flag = 0;

	while(j <= n && !flag)
	{
		if(j < n && array[j].priority > array[j+1].priority)
		{
			++j;
		}
		if(array[i].priority > array[j].priority)
		{
			//swap(&array[i], &array[j]);
			heap_t temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i = j;
			j = 2 * i;
		}
		else
		{
			flag = 1;
		}
 }
}

void read_Array(heap_t* array, int n)
{
	int data,i; 
	int priority;
	printf("Enter the elements and its priority\n");
	for(i = 1; i <= n ; ++i)
	{
		scanf("%d%d", &array[i].data, &array[i].priority);
	}
}

void insert(heap_t* array, int n)
{
	int i;
	for(i = n; i >= 1; --i)
	{
		heapify(array, n, i);
	}
}

void display_Array(heap_t* array, int n)
{
	int i;
	for(i = 1; i <= n; ++i)
	{
		printf("%d %d ", array[i].data, array[i].priority);
	}
	printf("\n");
}

int delete_Min(heap_t* array, int* n)
{
	array[1] = array[*n];
	(*n)--;
	insert(array, *n);
}

void swap(heap_t* a, heap_t* b)
{
	
}
