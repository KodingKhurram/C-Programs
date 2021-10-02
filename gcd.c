#include<stdio.h>

int gcdmiddleschool(int m); 
int main()
{
	int m;
	printf("enter m value:");
	scanf("%d",&m);
	//gcdmiddleschool(m);
	return(0);
}

int gcdmiddleschool(int m)
{
	int i,j,factor[m],q;
	for(i=2;i<=m;i++)
	{
		if(m%i==0)
		{
			factor[i]=i;
			q=m/i;
		}
	}
	
	printf("factor of m are:");
	for(j=0;j<m;j++)
	printf("%d",factor[j]);
}


