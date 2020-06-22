// Program to check if the number is prime or not using recursion
#include<stdio.h>
int check_prime(int num, int num2);
int num;
int main()
{
	printf("\tProgram to check whether the given number is a prime number.\n\n");
	char ans='y';
	do
	{
	printf(" Enter the number: ");
	scanf("%d", &num);
	int test, num2 = num/2;		// max divisible num for any num is its half
	test = check_prime(num, num2);
	if (test == 1)
		printf("\n %d is a prime number.", num);
	else
		printf("\n %d is not a prime number.", num);
	printf("\n\n Do you want to check another number? Y/N: ");
	scanf("%s", &ans);
	} while (ans=='y' || ans=='Y');
	printf("\n");
	return 0;
}
int check_prime(int num, int num2)
{
	if(num2==1)		// divisible for all nums, num2 acts as base condition
		return 1;
	
	else
	{
		if(num%num2 == 0)	// num is divisible by other numbers
			return 0;	
		else
			return check_prime(num, --num2);	// recursive call;
	}
}
