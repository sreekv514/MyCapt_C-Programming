#include<stdio.h>
//Program to fnd sum of digits of any number using a recursive function
int num;
int sum (int num);

int main() 
{ 
    int ans;
    printf("\n***Program to find the sum of digits of the number***\n");
	printf("\n Enter the number: ");
	scanf("%d", &num); 
    ans = sum(num); 
    printf("\n The sum of digits of %d is %d.\n", num, ans); 
    return 0; 
} 

int sum(int num) 		// recursive function
{ 
	if (num==0)		// base block
    	return 0;
    return (num%10 + sum(num/10));	// recursive call
} 
