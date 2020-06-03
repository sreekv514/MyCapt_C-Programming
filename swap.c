#include<stdio.h>
main()
{ // Program to swap 2 numbers without a temp variable.
int a = 1, b = 3; 
int swap = 1; // allows user to decide if or not to swap
printf("Enter two space-separated numbers: ");
scanf("%d", &a);
scanf("%d", &b);
printf("The numbers are stored as:\n A: %d , B: %d", a, b);
printf("\nWould you like to swap the numbers? Press 1 for YES or 0 for NO: ");
scanf("%d", &swap);
if (swap == 0)
{
    printf("\nProgram terminated without swapping numbers.\n");
}
else
{
  a = a + b; // a = 1+3 = 4
  b = a - b; // b = 4-3 = 1 
  a = a - b; // a = 4-1 = 3 
  printf("\nSwap successful. A:%d , B:%d \n", a, b);
}
return 0;
}
