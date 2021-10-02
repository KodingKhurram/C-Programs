
#A simple Handkerchief game 

#include<stdio.h>
#include<conio.h>
#include<unistd.h>
#include<stdlib.h>
 int front=-1,n,i,choice;
 int *a;
 void creategame();
 void playgame();
 void deleteplayer();
 int ch;

 int main()
 {
    printf("----- Handkerchief passing game -----\n");
    player:printf("\n Enter the number of players: ");
    scanf("%d",&n); 
    if(n<=1) 
    {
    	printf(" Players should more than 1\n");
    	goto player; 
	}
    creategame(); //placing the players.
    printf("\n Playing music press 'Enter' key to stop\n");
    printf(" ");
    playgame();
    getchar();
    return(0);
 }

 void creategame()
  {
  	a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
     a[i]=i+1;
  }

 void playgame()//Playing game ie playing music
 {
    while(!kbhit())
    {
        printf("#");
        front=(front+1)%n;//Passing of Handkerchief
        usleep(99000);
    }
    deleteplayer();//To know who have Handkerchief in his/her hand
 }

 void deleteplayer()
 { 
	printf("\n\n Player '%d' is out\n",a[front]);
    a[front]=0; // Deleting the player from list because he/she is out.
    for(i=0;i<n;i++)
    {
	    if(a[i]==0)
	    {
	     a[i]=a[i+1];// Rearranging the players
	     a[i+1]=0;
        }
    } 
    n--;//Players count-- after a player is out
    if(n==1)//Knowing the winner
    {
	  printf("\n _________ Player '%d' wins the game _________\n",a[n-1]);
	  printf("\n Enter '0' to exit or '1' to play new game:");
	  scanf("%d",&choice);
	  if(choice==1)
	   main();
	  else
	   exit(0);
    }
    printf("\n Remaing players are\n");
    for(i=0;i<n;i++)
    {
	  printf(" %d\n",a[i]);
    }
    getch();
    printf("\n Enter 1 to continue:\n ");
    scanf("%d",&ch);
    if(ch==1)
    {
	  printf("\n Playing music press 'Enter' key to stop\n");
	  printf(" ");
      playgame();
    }
 }
