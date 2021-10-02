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

			case 4: display_Array(queue, n);
					break;
		}
	}
}

void heapify(heap_t* array, int n, int position)
{
	int j;
	int flag = 0;heap_t temp;
	

	for(j=position+1;j<=n;j++)
	{
		if(array[position].priority>array[j].priority)
		{
			temp=array[j];
			array[j]=array[position];
			array[position]=temp;
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
	for(i = 1; i<=n; i++)
	{
		heapify(array, n,i);
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
