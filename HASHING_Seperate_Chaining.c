#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node {
	int data;
	struct node *link;
}NODE;

typedef struct table{
	NODE **table;
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
	NODE * newnode = createnode(data);
	NODE *p = htable->table[index];
	while(p->link != NULL)
		p = p->link;
	p->link = newnode;
	return;
}
int searchlist(HASHTABLE *htable,int index, int data)
{
	NODE *p = htable->table[index];
	while(p != NULL)
	{
		if(p->data = data)
			return 1;
		p = p->link;
	}
	return 0;
}
void deletelist(HASHTABLE *htable,int index, int data)
{
	NODE *p = htable->table[index];
	NODE *prev = NULL;
	if(p->link->data = data)
		p = NULL;
	else
	{
		while(p != NULL)
	{
		prev = p;
		if(p->data = data)
		{
			p = p->link;
			break;
		}
	}
	prev->link = p->link;
	free(p);
	}
}
void printlist(HASHTABLE *htable,int index)
{
	NODE *p = htable->table[index];
	while(p != NULL)
		printf("%d -> ",p->data);
	if(p == NULL)
		printf("NULL\n");
}
HASHTABLE *table_init(int size)
{
	int i;
	printf("this is initialization");
	HASHTABLE *p = malloc(sizeof(HASHTABLE));
	p->table=malloc(size*sizeof(struct NODE*));
	for(i = 0; i<size; i++)
	{
		p->table[i]->data=0;
		p->table[i]->link=NULL;
}
	p->size = size;
	for(i = 0; i<size; i++)
		printf("%d",p->table[i]->data);
		return p;
}
void insert(HASHTABLE *htable,int element)
{
	int index = element % htable->size;
    int i;
    for(i =0;i < htable->size; i++)
    {
        if(htable->table[index] == NULL)
        {
			NODE *newnode = createnode(element);
			htable->table[index]->link = newnode;
            return;
        }
        if(htable->table[index] != NULL)
			insertend(htable,index,element);
            return;
    }   
}
int search(HASHTABLE *htable, int element)
{
    int index = element % htable->size;
    int i;
    for(i =0;i<htable->size; i++)
    {
        if(htable->table[index] == NULL)
        {
            return 0;
        }
        if(htable->table[index] != NULL)
		{
			int res = searchlist(htable,index,element);
			if(res)
				return index;
			else return 0;
		}
    }
    return 0;
}
void delete (HASHTABLE *htable, int element)
{
    int index = search(htable,element);
    if(index)
        index--;
    else
        return;
    deletelist(htable,index,element);

}


void display_table(HASHTABLE *htable)
{
	int i;
    for(i =0; i<htable->size; i++)
    {
		printf("%d : ", htable->table[i]);
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
    	printf("enter your choice\n");
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
            delete (htable, element);
            break;

        case 3:
            // Search element
            scanf("%d", &element);
            find = search(htable, element);
            if (find)
                printf("YES\n");
            else
                printf("NO\n");
            break;

        case 4:
            // Print all elements in the hash table
            display_table(htable);
            break;

        default:
            break;
        }
    }
}
