#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node {
	int data;
	struct node *link;
}NODE;

typedef struct table{
	NODE *table[100];
	int size;
}HASHTABLE;

NODE *createnode(int data)
{
	NODE *newnode = malloc(sizeof(NODE));
	newnode->data = data;
	newnode->link = NULL;
	return newnode;
}
void insertend(HASHTABLE *htable,int index, int data)
{
	NODE *newnode=createnode(data);
	NODE *p = htable->table[index];
	while(p->link != NULL)
		p = p->link;
	p->link= newnode;
	return;
}
int searchlist(HASHTABLE *htable,int index, int data)
{
	NODE *p = htable->table[index];
	while(p != NULL)
	{
		if(p->data = data)
			return index;
		p = p->link;
	}
	return -1;
}
void deletelist(HASHTABLE *htable,int index, int data)
{
	NODE *p = htable->table[index];
	NODE *prev = NULL;
	while(p != NULL)
	{
		prev=p;
		p=p->link;
		if(p->data==data)
		{
			prev->link=p->link;
			free(p);
			return;
		}
	}
}

void printlist(HASHTABLE *htable,int index)
{
	NODE *p=htable->table[index];
	while(p->link != NULL)
	{
		p=p->link;
		printf("%d -> ",p->data);
	}
	if(p->link == NULL)
		printf("NULL\n");
}
HASHTABLE *table_init(int size)
{
	int i;
	printf("initializing...");
	HASHTABLE *p = malloc(sizeof(HASHTABLE));
	for(i = 0; i<size; i++)
	{
		p->table[i]=malloc(size*sizeof(NODE));
		p->table[i]->data=NULL;
		p->table[i]->link=NULL;
}
	p->size = size;
		return p;
}
void insert(HASHTABLE *htable,int element)
{
	int index;
    int i;
    index=element % htable->size;
    printf("index:%d\n",index);
    for(i =0;i < htable->size; i++)
    {
        if(htable->table[index]->data == NULL)
        {
        	htable->table[index]=createnode(element);
            return;
        }
        if(htable->table[index]->data != NULL)
			insertend(htable,index,element);
            return;
    }   
}
int search(HASHTABLE *htable, int element)
{
    int index;
    index=element % htable->size;
        if(htable->table[index]->data == NULL)
        {;
            return -1;
        }
        else
        {
			return searchlist(htable,index,element);
		}
}
void deletehash(HASHTABLE *htable, int element)
{
    int index = search(htable,element);
    if(index==-1)
        return;
    deletelist(htable,index,element);

}


void display_table(HASHTABLE *htable)
{
	int i;
    for(i =0; i<htable->size; i++)
    {
		printf("%d : ", htable->table[i]->data);
		printlist(htable,i);
		printf("\n");
	}    
    
}

int main()
{
    int size, choice, loop = 1;
    int element, find;
    printf("Enter the size of the hash table\n");
    scanf("%d", &size);
    HASHTABLE *htable = table_init(size);
    while (1)
    {
    	printf("\nenter your choice(more than 4 to quit)\n");
    	printf("1.insert\n2.delete\n3.search\n4.print:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // Insert element
            scanf("%d", &element);
            insert(htable, element);
            break;

        case 2:
            // Delete element
            scanf("%d", &element);
            deletehash(htable, element);
            break;

        case 3:
            // Search element
            scanf("%d", &element);
            int flag=search(htable, element);
            if(flag==-1)
            printf("NO\n");
            else printf("YES\n");
            break;

        case 4:
            // Print all elements in the hash table
            display_table(htable);
            break;

        default:
            return;
        }
    }
}
