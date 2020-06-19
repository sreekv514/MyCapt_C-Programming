// Program to create an employee file of 20 records using structures
#include<stdio.h>
#include<string.h>
#define MAXSIZE 20		// max size of records predefined as 20
#define EXCEED printf("\n\tYou cannot store more than 20 records.\n");
#define EMPTY printf("\n\tThere are no employee records available in storage.\n");

struct employee
{
	char name[50];
	int empno;
	int age;
	unsigned long long salary;
	unsigned long long mobile;
	char dept[50];
};

typedef struct employee EMP;
EMP record[20];
typedef unsigned long long ULL;

void input_details();
void display_all();
void display_specific();
void delete_specific();

static int counter=0;

void main()				// menu
{
	int cho;			// choice of action
	char exiter = 'y';
	record[0].empno = 0;

	printf("**********EMPLOYEE RECORDS**********\n");

	while(exiter == 'y' || exiter == 'Y')
	{
		printf("_________________________________________________\n");
		printf(" Please choose from the menu below:\n");
		printf("\t1. Add new employee details\n");
		printf("\t2. Display specific employee's details\n");
		printf("\t3. Display all employee details\n");
		printf("\t4. Delete a specific employee record\n");
		printf("\t5. Exit program\n");
		printf("_________________________________________________\n");
		printf("Enter your choice: ");
		scanf("%d", &cho);

		switch(cho)
		{
		case 1: input_details(); break;
		case 2: display_specific(); break;
		case 3: display_all(); break;
		case 4: delete_specific(); break;
		case 5: return;
		default: printf("\n Incorrect user input!\n");
		}
		printf("\nDo you wish to continue? Y/N: ");
		scanf("%s", &exiter);
	}
}

// To input employee details
void input_details()
{
	int i, numofemp;
	printf("\n Enter the number of employees whose details you need to upload: ");
	scanf("%d", &numofemp);
	if(numofemp<=MAXSIZE)
	{
			for(i=0; i<numofemp; i++)
			{
			counter = counter + 1;
			printf("\n\n Record %d:\n", counter);
			printf("Enter employee's name: ");
			scanf("%s", &record[i].name);
			printf("Enter employee number: ");
			scanf("%d", &record[i].empno);
			printf("Enter employee's department: ");
			scanf("%s", record[i].dept);
			printf("Enter employee's age: ");
			scanf("%d", &record[i].age);
			printf("Enter employee's mobile number: ");
			scanf("%llu", &record[i].mobile);
			printf("Enter employee's salary in numbers: ");
			scanf("%llu", &record[i].salary);
			}
			printf("\n %d record(s) added to file.\n", counter);
	}
	else
		EXCEED;
}

// To display all employee details
void display_all()
{
	int i=0;
	printf("\n %d record(s) present in file.\n", counter);
	if (counter<1)
	{
		EMPTY;
	}
	else
	{
		printf("\n******************************************************************************************\n");
		printf("Employee Name\t EmpNo\t Mobile Number\t Department\t Age\t Salary\t\n");
		while(i<counter)
		{
			printf("%s \t %d \t %llu\t %s\t %d \t %llu \n", record[i].name, record[i].empno, record[i].mobile, record[i].dept, record[i].age, record[i].salary);
			++i;
		}
		printf("\n******************************************************************************************\n");
	}
}

// To display specific employee's details
void display_specific()
{
	ULL num=0, mob=0;
	int option, i;
	printf("\n %d record(s) present in file.\n", counter);
	if (counter<1)
	{
		EMPTY;
	}
	else
	{
		printf("\n You may search for an employee's details: ");
		printf("\n 1.Through mobile number, OR\n 2.Through employee number.");
		printf("\n Enter choice here: ");
		scanf("%d", &option);
		switch (option)
			{
			case 1: {
					printf("\nEnter employee mobile number: ");
					scanf("%llu", &mob);
					break;
					}
			case 2: {
					printf("\nEnter employee number: ");
					scanf("%d", &num);
					break;
					}
			default: printf("\n Incorrect user input.\n");
			}
		if(mob>0)
		{
		for(i=0; i<counter; i++)
			{
			if(mob==record[i].mobile)
				{
				printf("Employee Name\t EmpNo\t Mobile Number\t Department\t Age\t Salary\t\n");
				printf("%s \t %d \t %llu\t %s\t %d \t %llu \n", record[i].name, record[i].empno, record[i].mobile, record[i].dept, record[i].age, record[i].salary);
				break;
				}
			else
				{
				    if(i==counter-1)
                    {
                        printf("\n No matches found!\n");
                    }
                    else
                        continue;
				}
			}
		}
		else if(num>0)
		{
			for(i=0; i<counter; i++)
			{
			if(num==record[i].empno)
				{
				printf("Employee Name\t EmpNo\t Mobile Number\t Department\t Age\t Salary\t\n");
				printf("%s \t %d \t %llu\t %s\t %d \t %llu \n", record[i].name, record[i].empno, record[i].mobile, record[i].dept, record[i].age, record[i].salary);
				break;
				}
			else
				{
				   if(i==counter-1)
                    {
                        printf("\n No matches found!\n");
                    }
                    else
                        continue;
				}
			}
		}
	}
}

// To delete specific employee record
void delete_specific()
{
	ULL num=0, mob=0;
	int option, i, j;
	printf("\n %d record(s) present in file.\n", counter);
	if (counter<1)
	{
		EMPTY;
	}
	else if(counter == 1)
    {
        strcpy(record[0].name, " ");
        strcpy(record[0].dept, " ");
        record[0].age = record[0].empno = 0;
        record[0].mobile = record[0].salary = 0;
        counter = 0;
        printf("\nAll records deleted.\n");
    }
	else
	{
		printf("\nYou may search and delete an employee's details by: ");
		printf("\n 1.Search and delete using mobile number, OR\n 2.Search and delete using employee number.");
		printf("\n Enter choice here: ");
		scanf("%d", &option);
		switch (option)
			{
			case 1: {
					printf("\nEnter employee mobile number: ");
					scanf("%llu", &mob);
					break;
					}
			case 2: {
					printf("\nEnter employee number: ");
					scanf("%d", &num);
					break;
					}
			default: printf("\n Incorrect user input.\n");
			}
		if(mob>0)
		{
		for(i=0; i<counter; i++)
			{
			if(mob==record[i].mobile)
				{
					for(j=i; j<counter-1; j++)
					{
						record[j] = record [j+1];
					}
					counter = counter - 1;
					printf("\nRecord deleted.\n");
					break;
				}
			else
				{
				   if(i==counter-1)
                    {
                        printf("\n No matches found!\n");
                    }
                    else
                        continue;
				}
			}
		}
		else if(num>0)
		{
			for(i=0; i<counter; i++)
			{
			if(num==record[i].empno)
				{
					for(j=i; j<counter-1; j++)
					{
						record[j] = record[j+1];
					}
					counter = counter - 1;
					printf("\nRecord deleted.\n");
					break;
				}
			else
				{
				   if(i==counter-1)
                    {
                        printf("\n No matches found!\n");
                    }
                    else
                        continue;
				}
			}
		}
	}
}
