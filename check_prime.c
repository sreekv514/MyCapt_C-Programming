// Program to check if the number is prime or not
#include<stdio.h>
int check_prime(int num);
int num = 2;
int main()
{
	printf("\tProgram to check whether the given number is a prime number.\n\n");
	char ans='y';
	do
	{
	printf(" Enter the number: ");
	scanf("%d", &num);
	int test = check_prime(num);
	if (test == 0)
		printf("\n %d is a prime number.", num);
	else
		printf("\n %d is not a prime number.", num);
	printf("\n\n Do you want to check another number? Y/N: ");
	scanf("%s", &ans);
	} while (ans=='y' || ans=='Y');
	printf("\n");
	return 0;
}
int check_prime(int num)
{
	int i;
	for(i=2; i<=num-1; i++)
	{
		if(num%i == 0)
			return 1;
	}
	return 0;
}
