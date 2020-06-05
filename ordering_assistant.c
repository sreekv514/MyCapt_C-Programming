#include<stdio.h>
int main()
{ //switch case statement for food menu
    int num, counter, counter2;
    char exit_but[1]; // to delay exit till user gives some input
    char YN1='y';
    printf("\tWelcome to C Surprises!\n");
    printf("\nCraving a snack? Let's order!'\n");
    printf("\nWould you like to see our menu? Y/N: ");
    scanf("%s", &YN1);
    if (YN1=='y' || YN1=='Y')
    {
        printf("\n\n\tMENU:\n");
        printf("1. 2 croissants. INR 130. \n2. 1 plate of moules frites. INR 150. \n3. 2 chaussons aux pommes. INR 150. \n4. 1 plate of panisses. INR 100. \n5. 1 plate of gougeres. INR 100. ");
        printf("\n6. 2 croissants and a coffee. INR 150. \n7. 1 regular veg pizza. INR 250.\n8. 1 regular chicken pizza. INR 350.\n9. 1 veg burger and a soda. INR 250. \n10. 1 chicken burger and a soda. INR 350.");
        printf("\n \nEnter the number of the item you would like to order. In case, you would like us to recommend something, press 0.\n Your choice: ");
        scanf("%d", &num);
    }
    else if(YN1=='n' || YN1=='N')
    {
        char YN2 ='y';
        printf("\n \nWould you like us to recommend an item from our menu instead? Y/N: ");
        scanf("%s", &YN2);
        if (YN2=='y' || YN2=='Y')
        {
            printf("\nChoose a number between 1 and 10, and let us suggest something for you.\n");
            printf("Enter a number: ");
            scanf("%d", &num);
        }
        else
        {
            printf("\n You have chosen not to eat with us for now. We hope you come again!");
            printf("\n\nPress X to exit program. ");
			scanf("%s",&exit_but);
     		return 0;
		}
		
    }

    else
        {
		printf("\nIncorrect user input!");
		printf("\n\nPress X to exit program. ");
		scanf("%s",&exit_but);
		}
	
// menu service from here
    if (num>=1 && num<=10)
    {
    printf("\n\nHere's what you chose from our menu:\n");
    switch(num)
    {
    case 1: printf("\n Item: 2 croissants.\n Price: INR 130.\n");
             break;
    case 2: printf("\n Item: 1 plate of moules frites. \n Price: INR 150.\n");
             break;
    case 3: printf("\n Item: 2 chaussons aux pommes. \n Price: INR 150. \n");
             break;
    case 4: printf("\n Item: 1 plate of panisses. \n Price: INR 100. \n");
             break;
    case 5: printf("\n Item: 1 plate of gougeres. \n Price: INR 100. \n");
             break;
    case 6: printf("\n Item: 2 croissants and a coffee. \n Price: INR 150. \n");
             break;
    case 7: printf("\n Item: 1 regular veg pizza. \n Price: INR 250. \n");
             break;
    case 8: printf("\n Item: 1 regular chicken pizza. \n Price: INR 350. \n");
             break;
    case 9: printf("\n Item: 1 veg burger and a soda. \n Price: INR 250. \n");
             break;
    case 10: printf("\n Item: 1 chicken burger and a soda. \n Price: INR 350. \n");
             break;
    default: printf("Not Applicable.");
    }
    printf("\n \tHope you like it!\n");
    }
    else if (num==0)
    {
        int newnum =30;
        printf("\n \n You have chosen to get a suggestion from us. Enter a value between 20 and 30:");
        scanf("%d", &newnum);
        switch(newnum)
    {
    case 22: printf("\n Item: 2 croissants.\n Price: INR 130.\n");
             break;
    case 24: printf("\n Item: 1 plate of moules frites. \n Price: INR 150.\n");
             break;
    case 26: printf("\n Item: 2 chaussons aux pommes. \n Price: INR 150. \n");
             break;
    case 28: printf("\n Item: 1 plate of panisses. \n Price: INR 100. \n");
             break;
    case 25: printf("\n Item: 1 plate of gougeres. \n Price: INR 100. \n");
             break;
    case 30: printf("\n Item: 2 croissants and a coffee. \n Price: INR 150. \n");
             break;
    case 21: printf("\n Item: 1 regular veg pizza. \n Price: INR 250. \n");
             break;
    case 23: printf("\n Item: 1 regular chicken pizza. \n Price: INR 350. \n");
             break;
    case 27: printf("\n Item: 1 veg burger and a soda. \n Price: INR 250. \n");
             break;
    case 29: printf("\n Item: 1 chicken burger and a soda. \n Price: INR 350. \n");
             break;
    default: printf("Not Applicable.");
    }
    printf("\n \tHope you like it!\n");
    }
    else
        printf("\nIncorrect input. Program terminated.\n");
    printf("\nPress X to exit program. ");
	scanf("%s",&exit_but);
    return 0;
}
