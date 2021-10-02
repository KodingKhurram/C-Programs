
#include<stdio.h>
#define MAX 50

void read_Array(int*, int);
void display_Array(int*, int);
void heapify(int*, int);
void heapify(int*, int, int);
int delete_Max(int*, int*);
void heap_Sort(int*, int);
int count=0;

void heap(int *array,int n,int size)
{
	int i,j,k,heap,root,temp,c;
	for(i=1;i<=n;i++)
	{
		k=i;
		root=array[k];
		heap=0;
		c=n*2;
		while(c<=size && !heap)
		{
			if(array[c]<array[c+1])
			c++;
			if(array[c]<=root)
			heap=1;
			else
			{
            array[k]=array[c];
			k=c;
			array[k]=root;
		    }
		}
	}
}

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


void heapify(int* array, int n)
{
	for(int i=1;i<n;i++)
	{
		printf("iteration %d\n",i);
		heap(array,i,n);
	}
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
	


int delete_Max(int* array, int* n)
{
	int max = array[1];
	array[1] = array[*n];
	(*n)--;
	heapify(array, *n);
	return max;
}




