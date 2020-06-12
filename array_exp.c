// Program to intialize 3*3 array, insert elements in the array, read and print the array using only pointers
// Also to find and print sum of all diagonal elements
#include<stdio.h>
int main()
{
	// Initialize 3*3 matrix and pointer
	int mat[3][3];
	int *p;
	int i=0, j=0; // loop variables
	int sum=0;
	// Insert input to 2d array
	printf(" Enter the values for the matrix:\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf(" Element[%d][%d]: ", i, j);
			scanf("%d", &mat[i][j]);
		}
	}
	// Display array using pointer variable
	printf("\n The matrix is:\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			p = &mat[i][j]; // pointer
			printf(" %d \t", *p);
		}
		printf("\n");
	}
	// Print sum of diagonal elements
	printf("\n\n The diagonal elements are: ");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			if(i==j)
				{
					sum+=mat[i][j];
					printf("%d\t", mat[i][j]);
				}
			else if ((i+j)==2)
				{
					sum+=mat[i][j];
					printf("%d\t", mat[i][j]);
				}
		}
	}
	printf("\n Sum of all diagonal elements = %d", sum);
	return 0;
}
