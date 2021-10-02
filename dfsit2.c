#include<stdio.h>
 
void DFS(int);
int G[10][10],visited[10],n; 
int stack[100],top=-1;
 
int main()
{
    int i,j,edges,d,s;
    printf("Enter number of vertices:");
   
	scanf("%d",&n);
	
	printf("Enter the number of edges:");
	scanf("%d",&edges);
   
	for(i=0;i<edges;i++)
	{
		printf("Enter the source and destination vertex");
		scanf("%d%d",&s,&d);
		G[s][d]=G[d][s]=1;
	}
   for(j=0;j<n;j++)
        visited[j]=0;
 
    DFS(0);
}

void DFS(int vertex)
{
int i=0,j,v;
visited[vertex]=1;
push(vertex);
		while(!empty())
		{
			v=pop();
			printf("%d",v);
			visited[v]=1;
			for(i=0;i<n;i++)
			{
				if(G[v][i]==1 && visited[i]==0)
				{
				visited[i]=1;	
				push(i);
			}
			}
		}
}
void push(int v)
{
	top++;
	stack[top]=v;
}

int pop()
{
	int x;
	x=stack[top];
	top--;
	return x;
}

int empty()
{
	if(top==-1)
	return 1;
	else return 0;
	
}
