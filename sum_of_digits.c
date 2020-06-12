#include<stdio.h>
// program to find sum of digits of a number
int dsum = 0;
int find_sum(int num);
int main()
{
	int num = 0;
	printf("Program to find the sum of the digits of a number.\n\n");
	printf("Enter the number: ");
	scanf("%d", &num);
	printf("\nSum of digits of this number is %d.", find_sum(num));
	return 0;
}
int find_sum(int num)
{
	while (num!=0)
	{
		dsum+=(num%10);
		num=num/10;
	}
	return dsum;
}
