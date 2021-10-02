
#include<stdio.h>
#define MAX 50

void read_Array(int*, int);
void display_Array(int*, int);
void heapify(int*, int);
void heapify(int*, int, int);
int delete_Max(int*, int*);
void heap_Sort(int*, int);


void heap(int *array,int n)
{
	int i,j,k,heap,p,temp;
	for(i=n/2;i>=1;i--)
	{
		k=i;
		p=array[k];
		heap=0;
		while(2*i<=n && !heap)
		{
			j=2*i;
			if(j<n && array[j]<array[j++])
			j++;
			if(p>=array[j])
			heap=1;
			else// swap parent with child
			{
			array[k]=array[j];
			//k=j;
			array[j]=p;
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
	for(int i = n; i >= 1; --i)
		heap(array,i);
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




