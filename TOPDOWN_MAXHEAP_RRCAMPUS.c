#include<stdio.h>
#define MAX 100

void read_Array(int*, int);
void display_Array(int*, int);
void heapify(int*, int);
int delete_Max(int*, int*);
void sort(int*, int);

int main()
{
	int array[MAX];
	int n;
	printf("Enter the number of elements\n");
	scanf("%d", &n);
	read_Array(array, n);
	display_Array(array, n);
	heapify(array, n);
	printf("After heapify\n");
	display_Array(array, n);
	
	while(n)
	{
		int res = delete_Max(array,&n);
		printf("%d",res);
		//display_Array(array, n);
	}
	
	return 0;
}
void read_Array(int* array, int n)
{
	int i;
	for(i = 0; i < n ; ++i)
	{
		scanf("%d", &array[i]);
	}
}

void display_Array(int* array, int n)
{
	int i;
	for(i = 0; i < n ; ++i)
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
	int j,k;
	int data;
	for(i = 1; i < n; ++i)
	{
		k = i;
		j = (k - 1) / 2;
		data = array[k];
		while(array[j] < data && (k > 0))  // Sign change for mIn HEAP.
		{
			//swap(&array[i], &array[j]);
			array[k] = array[j];
			k = j;
			j = (k - 1) / 2;
		}
		array[k] = data;
	}
}
int delete_Max(int* array, int* n)
{
	int res = array[0];
	array[0] = array[(*n)-1];
	(*n)--;
	heapify(array,*n);
	return res;
}


