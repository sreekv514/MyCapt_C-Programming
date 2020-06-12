// program to find lowest common multiple using recursion
#include<stdio.h>
int lcm(int n1, int n2);
int n1, n2;
int main()
{
	char ans = 'y';
	printf("\tProgram to find the lowest common multiple of 2 values\n");
	do
	{
	printf("\nEnter first number: ");
	scanf("%d", &n1);
	printf("Enter second number: ");
	scanf("%d", &n2);
	int n_lcm=lcm(n1, n2);
	printf("\n LCM (%d, %d) = %d", n1, n2, n_lcm);
	printf("\n  Do you want to check LCM for other numbers? Y/N: ");
	scanf("%s", &ans);
	} while (ans=='y' || ans=='Y');
	return 0;
}
int lcm(int n1, int n2) // recursive function
{
	static int check =1;
	if(check%n1==0 && check%n2==0)
		return check;
	else
		{
			check++;
			lcm(n1, n2); // recursive call
		}
}
