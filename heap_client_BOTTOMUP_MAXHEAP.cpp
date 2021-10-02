#include<stdio.h>
#define MAX 50

void read_Array(int*, int);
void display_Array(int*, int);
void heapify(int*, int);
int delete_Max(int*, int*);
void heap_Sort(int*, int);

int main()
{
	int array[MAX];
	int n;

	printf("Enter the number of elements\n");
	scanf("%d", &n);

	read_Array(array, n);
	display_Array(array, n);
	heapify(array, n);

	display_Array(array, n);

	printf("Deleted element is = %d\n", delete_Max(array, &n));

	display_Array(array, n);

	heap_Sort(array, n);

	display_Array(array, n);
	
}

void read_Array(int* array, int n)
{
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &array[i]);
	}
}


void display_Array(int* array, int n)
{
	for(int i = 1; i <= n; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}


void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
	
void heapify(int* array, int n)
{
	int i;
	for(int i = n/2; i >= 1; --i)
	{
	int k;
	int j;
	k = i;
	j = 2 * k;
	int flag = 0;
	while(j <= n && !flag)
	{
		if(j < n && array[j + 1] > array[j])
		{
			++j;
		}
		if(array[k] < array[j])
		{
			swap(&array[k], &array[j]);
			k = j;
			j = 2 * k;
		}
		else
		{
			flag = 1;
		}
	}
}
}

int delete_Max(int* array, int* n)
{
	int max = array[1];
	array[1] = array[*n];
	(*n)--;
	display_Array(array, *n);
	heapify(array, *n);

	return max;
}


void heap_Sort(int* array, int n)
{
	for(int i = n; i > 1; --i)
	{
		swap(&array[1], &array[i]);
		heapify(array, i - 1);
	}
}


