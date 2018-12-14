#include <stdio.h>
#include <conio.h>
void sum_of_all(void) //User defined function
{
    int n, sum;
    sum=0;
    for(n=1;n<=100;n++)
        sum+=n;
    printf("sum of all numbers from 1 to 100 is: %d",sum);
}
void main(void)// Main Function
{
    sum_of_all();
    getch();
    return 0;
}
