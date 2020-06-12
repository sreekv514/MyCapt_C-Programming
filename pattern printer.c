#include<stdio.h>
int main()
{ // program to print 3 different patterns with 2 different styles using loops, depending on user's choice 
int i=0, j=0, k=0; // common loop variables for all patterns
int row=1; // for user to input num of rows
int ans; // to ask if user wants to exit program
int cho_pat, cho_des;
char exiter[1]; // to delay abrupt prgm exit
printf("\tWelcome to pyramid builder!\n");
do
	{
	printf("\nWhat PATTERN would you like to build?\n");
	printf("\tMENU:\n 1.Half pyramid\n 2.Inverted half pyramid\n 3.Full pyramid\n");
	printf("Enter your choice here: ");
	scanf("%d", &cho_pat);
	printf("\nWhat STYLE would you like to use?\n");
	printf("\tMENU:\n 1.Stars\n 2.0s and 1s\n");
	printf("Enter your choice here: ");
	scanf("%d", &cho_des);
	printf("\nEnter the number of rows for your pattern: ");
	scanf("%d", &row);
	
	if(cho_des==1) // Stars for patterning
		{
			switch(cho_pat)
				{
					case 1: { // Half pyramid
							printf("\n\tHalf pyramid with %d rows\n", row);
							for(i=0; i<row; ++i) // number of rows
								{
								printf("\t");
								for(j=0; j<=i; ++j) // number of characters in one line of triangle
									{
									printf("* "); 	
									}
								printf("\n");
								}
							break;
							}
					case 2: { // Inverted half pyramid
							printf("\n\tInverted half pyramid with %d rows\n", row);
							for(i = row; i > 0; --i) // reducing num of rows
   								{
   								printf("\t");
        						for(j = 1; j <= i; ++j) // characters in one line
        							{
            						printf("* ");
        							}
        						printf("\n");
    							}
							break;
							}
					case 3: { // Full pyramid
							printf("\n Full pyramid with %d rows\n", row);
							for(i=1; i<=row; ++i) // for rows
								{
									for(j=1; j<=row-i; j++) // to print leading spaces
										{
											printf(" ");
										}
									k=0;
									while(k!=(i*2)-1) // to print stars
										{
											if (i==1)
											 {
											 	printf(" *");
											 }
											else
											 {
											 	printf("* "); 
											 }
											++k; 
										}
									printf("\n");
								}
							break;
							}
					default: {
							  printf("\n\n Incorrect user input for pattern choice!");
						      break;
							 } 
				}
		}
		
	else if(cho_des==2) // 0101 pattern
		{
		switch(cho_pat)
				{
					case 1: { // Half pyramid
							printf("\n\tHalf pyramid with %d rows\n", row);
							for(i=0; i<row; ++i) // number of rows
								{
								printf("\t");
								for(j=0; j<=i; ++j) // number of characters in one line of triangle
									{
									printf("01"); 	
									}
								printf("\n");
								}
							break;
							}
					case 2: { // Inverted half pyramid
							printf("\n\tInverted half pyramid with %d rows\n", row);
							for(i = row; i > 0; --i) // reducing num of rows
   								{
   								printf("\t");
        						for(j = 1; j <= i; ++j) // characters in one line
        							{
            						printf("01");
        							}
        						printf("\n");
    							}
							break;
							}
					case 3: { // Full pyramid
							printf("\n Full pyramid with %d rows\n", row);
							for(i=1; i<=row; ++i) // for rows
								{
									for(j=1; j<=row-i; j++) // to print leading spaces
										{
											printf("  ");
										}
									k=0;
									while(k!=(i*2)-1) // to print pattern
										{
											if (i==1)
											 {
											 	printf(" 01");
											 }
											else
											 {
											 	printf("01 "); 
											 }
											++k; 
										}
									printf("\n");
								}
							break;
							}
					default: {
							  printf("\n\n Incorrect user input for pattern choice!");
						      break;
							 } 
				}	
		}
	else
		{
		  	printf("\n\n Incorrect user input for style choice!");
		}
	printf("\n\nWould you like to print another pattern? Press 1 for YES, or 0 for NO: ");
	scanf("%d", &ans);
	} while (ans==1);
printf("\n\t Thank you! Hope you enjoyed it!\n");
printf("\nPress X to exit the program.");
scanf(" %c", &exiter);
return 0;
}
