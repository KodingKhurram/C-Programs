#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int key;
	char name[50];
	struct node* link;
};
typedef struct node node_t;

struct hash
{
	node_t* head;
};
typedef struct hash hash_t;


void initialize_Hash(hash_t*, int);
void insert_Into_Hash(hash_t*, int, char*, int);
void display_Hash(hash_t*, int);
void search(hash_t*, int, int);
void delete_From_Hash(hash_t*, int, int);



int main()
{
	int ch;
	int key;
	char name[50];
	int tablesize;
	printf("Enter the tablesize\n");
	scanf("%d", &tablesize);

	hash_t* hashtable = (hash_t*)malloc(sizeof(hash_t) * tablesize);
	
	initialize_Hash(hashtable, tablesize);

	while(1)
	{
		printf("Enter your choice\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("Enter the key and name to be inserted\n");
					scanf("%d%s", &key, name);
					insert_Into_Hash(hashtable, key, name, tablesize);
					break;

			case 2: display_Hash(hashtable, tablesize);
					break;

			case 3: printf("Enter the key to be searched\n");
					scanf("%d", &key);
					search(hashtable, key, tablesize);
					break;

			case 4: printf("Enter the key to be deleted\n");
					scanf("%d", &key);
					delete_From_Hash(hashtable, key, tablesize);
					break;
		}
	}
	return 0;
}

void initialize_Hash(hash_t* hashtable, int tablesize)
{
	int i;
	for(i = 0; i < tablesize; ++i)
	{
		hashtable[i].head = NULL;
	}	
}

node_t* create_Node(int key, char* name)
{
	node_t* new = (node_t*)malloc(sizeof(node_t));
	new -> key = key;
	strcpy(new -> name, name);
	new -> link = NULL;
	
	return new;
}

void insert_Into_Hash(hash_t* hashtable, int key, char* name, int tablesize)
{
	int index = key % tablesize;

	node_t* temp = create_Node(key, name);

	temp -> link = hashtable[index].head;
	hashtable[index].head = temp;
}

void display_Hash(hash_t* hashtable, int tablesize)
{
	int i;
	for(i = 0; i < tablesize; ++i)
	{
		printf("%d :", i);
		
		node_t* temp = hashtable[i].head;
		while(temp != NULL)
		{
			printf("%d ", temp -> key);
			printf("%s", temp -> name);
			printf("->");

			temp = temp -> link;
			
		}
		printf("\n");
	}
}


void search(hash_t* hashtable, int key , int tablesize)
{
	int index = key % tablesize;
	node_t* temp = hashtable[index].head;
	while(temp != NULL && temp -> key != key)
	{
		temp = temp -> link;
	}
	if(temp == NULL)
	{
		printf("Key not found\n");
	}
	else
	{
		printf("%d %s", temp -> key, temp -> name);
	}
}

void delete_From_Hash(hash_t* hashtable, int key , int tablesize)
{
	int index = key % tablesize;
	node_t* temp = hashtable[index].head;
	node_t* prev = NULL;
	while(temp != NULL && temp -> key != key)
	{
		prev = temp;
		temp = temp -> link;
	}
	if(temp == NULL)
	{
		printf("Key not found\n");
	}
	else
	{
		if(prev == NULL)
		{
			hashtable[index].head = temp -> link;
			//free(temp);
		}
		else
		{
			prev -> link = temp -> link;
			//free(temp);
		}
		free(temp);
	}
}











