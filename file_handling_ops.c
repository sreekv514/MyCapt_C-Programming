//Program to work with files: To reverse content, to copy content, to append content.

#include<stdio.h>
#include<conio.h>
#include<string.h>

#define OPERR printf("\n***ERROR: Unable to open file***\n");
#define USERR printf("\n Incorrect user input. No action taken. \n");

#define MAXSIZE 500

// Program to reverse contents of a file and to copy from one file to another

FILE *fp1, *fp2;

void createfile();
void printfile();
void reversefile();
void copyfile();

char dummy;
char str1[MAXSIZE], str2[MAXSIZE];

int main()
{
	int choice = 1;
	char ans = 'y';
	printf("\n ---File Handling Program with 2 Files--- \n");
	do
	{
		printf("\n Functions available:\n");
		printf(" 1. Create and write to new text files\n");
		printf(" 2. View contents of files\n");
		printf(" 3. Reverse content of file\n");
		printf(" 4. Copy content to another file\n");
		printf(" 5. Exit program\n");
		printf("\n\tEnter your choice: ");
		scanf("%d", &choice);
				
		switch(choice)
		{
			case 1: {
					createfile();
					break;
					}
			case 2: {
					printfile();
					break;
					}
			case 3: {
					reversefile();
					break;
					}
			case 4: {
					copyfile();
					break;
					}
			case 5: {
					printf("\n End of program. Press any key to exit.\n");
					getch();
					break;
					}
			default: USERR;
		}
		
		printf("\n Would you like to continue? Y/N: ");
		scanf("%s", &ans);
		
	} while(ans=='y' || ans=='Y' && choice!=5);
	return 0;
}

void createfile()
{
	char cho;
	int length;
	
	fp1 = fopen("File1.txt", "w");
	fp2 = fopen("File2.txt", "w");
	
	if(fp1 == NULL)
	{
		OPERR;
		printf("\n\t Details: Error in creating File1.\n");
		return;
	}
	if(fp2 == NULL)
	{
		OPERR;
		printf("\n\t Details: Error in creating File2.\n");
		return;
	}
	
	printf("\n Successfully created 2 new files. Would you like to write text to the files? Y/N: ");
	scanf("%s", &cho);
	
	if(cho=='n' || cho=='N')
	{
		strcpy(str1, "Hello! This is a sample text.");
		strcpy(str2, "Just another sample text.");
		fputs(str1, fp1);
		fputs(str2, fp2);		
		
		printf("\n Successfully inserted sample text in files.\n");
	}
	else if(cho =='y' || cho=='Y')
	{
		printf("\nEnter text to write in File1.txt (max %d characters): ", MAXSIZE);
		scanf("%c", &dummy);
		fgets(str1, sizeof(str1), stdin);
		fputs(str1, fp1);
		
		printf("\nEnter text to write in File2.txt (max %d characters): ", MAXSIZE);
		fgets(str2, sizeof(str2), stdin);
		fputs(str2, fp2);
		
		printf("\n Successfully inserted text in files.\n");
	}
	else
	{
		USERR;
	}
	
	fclose(fp1);
	fclose(fp2);
}

void printfile()
{
	fp1 = fopen("File1.txt", "r");
	fp2 = fopen("File2.txt", "r");
	
	char ch;
	
	if(fp1 == NULL && fp2 == NULL)
	{
		OPERR;
		printf("\n Details: Unable to open both files.\n");
	}
	else if (fp1 == NULL)
	{
		OPERR;
		printf("\n Details: Unable to open first file.\n");
	}
	else if (fp2 == NULL)
	{
		OPERR;
		printf("\n Details: Unable to open second file.\n");
	}
	else
	{
		printf("\n Current content of file 1: ");
		int i=0;
	while(!feof(fp1))
		{
			str1[i]=fgetc(fp1);
			printf("%c", str1[i]);
			++i;
		}
		
		printf("\n Current content of file 2: ");
		i=0;
		while(!feof(fp2))
		{
			str2[i]=fgetc(fp2);
			printf("%c", str2[i]);
			++i;
		}
	}
	
	fclose(fp1);
	fclose(fp2);
}

void reversefile()
{
	// char temp[MAXSIZE], ch;
	int i=0, length, cho;
	
	printf("\n\n Which file's content would you like to reverse?\n 1. File1.txt\n 2. File2.txt\n");
	printf("\t Enter your choice: ");
	scanf("%d", &cho);
					
	switch(cho)
	{
		case 1:
			{
				fp1 = fopen("File1.txt", "r");
				if(fp1==NULL)
				{
					OPERR;
					printf("\t Details: File does not exist to read data.\n");
					return;
				}
				
				i=0;
				while(!feof(fp1))		// not working from here 
					{
						str1[i]=fgetc(fp1); 
						i++;
					}				
				fclose(fp1);
				
				fp1 = fopen("File1.txt", "w");
				if(fp1==NULL)
				{
					OPERR;
					return;
				}
				
				length = strlen(str1);
				
				for(i=length-1; i>=0; i--)
					{
					fputc(str1[i], fp1);	
					}
				
				printf("\n Successfully reversed content in file. \n");
				fclose(fp1);
				
				break;
			}
		case 2:
			{
				fp2 = fopen("File2.txt", "r");
				if(fp2==NULL)
				{
					OPERR;
					printf("\t Details: File does not exist to read data.\n");
					return;
				}
				
				i=0;
				while(!feof(fp2))
					{
						str2[i]=fgetc(fp2);
						i++;
					}
				
				fclose(fp2);
				
				fp2 = fopen("File2.txt", "w");
				if(fp1==NULL)
				{
					OPERR;
					return;
				}
				
				length = strlen(str2);
								
				for(i=length-1; i>=0; i--)
					{
					fputc(str2[i], fp2);	
					}
					
				printf("\n Successfully reversed content in file. \n");
				fclose(fp2);
				
				break;
			}
		default: USERR;
	}
}

void copyfile()
{
	char store1[MAXSIZE], store2[MAXSIZE];		// variables to store file content temporarily in stack
	int choice;
	int i=0, length;
	
	printf("\n Please specify the desired operation:\n");
	printf(" 1. Copy content from file 1 to file 2\n");
	printf(" 2. Copy content from file 2 to file 1\n");
	printf(" 3. Exchange the content within both files\n");
	printf("\t Enter your choice: ");
	scanf("%d", &choice);
	
	switch(choice)
	{
		case 1: 
		{
			fp1 = fopen("File1.txt", "r");
			fp2 = fopen("File2.txt", "a");
			
			if(fp1 == NULL || fp2 == NULL)
			{
				OPERR;
				return;
			}
			
			fgets(store1, MAXSIZE, fp1);
			length = strlen(store1);
			
			printf("\n --- Copying %s to file 2 ---\n", store1);
			
			for(i=0; i<length; i++)
			{
				putc(store1[i], fp2);
			}
			
			printf("\n Successfully copied contents from file 1 and appended to file 2.\n");
			
			fclose(fp1);
			fclose(fp2);
			
			break;
		}
		case 2:
		{
			fp1 = fopen("File1.txt", "a");
			fp2 = fopen("File2.txt", "r");
			
			if(fp1 == NULL || fp2 == NULL)
			{
				OPERR;
				return;
			}
			
			fgets(store2, MAXSIZE, fp2);
			length = strlen(store2);
			
			printf("\n --- Copying %s to file 1 ---\n", store2);
			
			for(i=0; i<length; i++)
			{
				putc(store2[i], fp1);
			}
			
			printf("\n Successfully copied contents from file 2 and appended to file 1.\n");
			
			fclose(fp1);
			fclose(fp2);
			
			break;
		}
		case 3:
		{
			fp1 = fopen("File1.txt", "r");
			fp2 = fopen("File2.txt", "r");	
			
			if(fp1 == NULL || fp2 == NULL)
			{
				OPERR;
				return;
			}
			
			i=0;
			while(!feof(fp1))
			{
				store1[i]=fgetc(fp1);
				++i;
			}
			
			i=0;
			while(!feof(fp2))
			{
				store2[i]=fgetc(fp2);
				++i;
			}
			
			fclose(fp1);
			fclose(fp2);
			
			fp1 = fopen("File1.txt", "w");
			fp2 = fopen("File2.txt", "w");
			
			if(fp1 == NULL || fp2 == NULL)
			{
				OPERR;
				return;
			}
			
			length = strlen(store1);
			for(i=0; i<length; i++)
			{
				putc(store1[i], fp2);
			}
			
			length = strlen(store2);		
			for(i=0; i<length; i++)
			{
				putc(store2[i], fp1);
			}
			
			printf("\n Successfully exchanged contents of both files.\n");
			
			fclose(fp1);
			fclose(fp2);
			
			break;
		}
		default: USERR;
	}
}
