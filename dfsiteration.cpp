#include<stdio.h>
 
void DFS(int);
int G[10][10],visited[10],n; 
 
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

void DFS(int v)
{
int i=0,j;
visited[v]=1;
printf("The node :%d is visted\n",v);
		while(i<n)
		{
			travel:if(G[v][i]!=0 && visited[i]==0)
			{
				printf("The node :%d is visted\n",i);
				visited[i]=1;
				v=i;
				i++;
			}
			else i++;
		}
		//look for unvisited nodes
		for(j=0;j<n;j++)
		{
			if(visited[j]==0)
			{
				i=j;
				v=0;
				goto travel; 
			}
		}
		}
	

