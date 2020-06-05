#include <stdio.h>
int main()
{ // Program to convert marks to grades.
    int mark=0;
    printf("\nConvert your marks to the associated grade!\n");
    printf("\nEnter marks out of 100: ");
    scanf("%d", &mark);
    if(mark>100 || mark<0)
    {
        printf("\nUser input error! Please re-run the program.\n");
    }
    else
    {
    if (mark>=85)
    {
        printf("\nCongrats! Your grade is: A.\n");
    }
    else if(mark>=70)
    {
        printf("\nYour grade is: B.\n");
    }
    else if(mark>=55)
    {
        printf("\nYour grade is: C.\n");
    }
    else if(mark>=40)
    {
        printf("\nYour grade is: D.\n");
    }
    else
    {
        printf("\nYour grade is: F.\n");
    }
    }
    return 0;
}
