#include <stdio.h>
#include <conio.h>
void sqre_value(long int any_value)
{
    long int result;
    result=any_value*any_value;
    printf("The square value of %d is %d.",any_value,result);
}
void main()
{
    sqre_value(10);
    getch();
    return 0;
}
