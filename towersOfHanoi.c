#include <stdio.h>

int count;

void TOH(int n, char A, char C, char B) 
{
	count+=1;
   if (n == 1) {
       printf("Move Disk 1 From Rod %c To Rod %c \n", A, C);
       return;
    }

   else {

        TOH(n - 1, A, B, C);
        printf("move Disk %d From Rod %c to Rod %c \n",n,A,C);
		TOH(n - 1, B, C, A);
   }    
}

int main() {

  int n;
  printf("Enter Number Of Discs\n");
  scanf("%d", &n);

  TOH(n,'a','c','b');

  printf("Total Count = %d\n", count);
    
  return 0;

}
