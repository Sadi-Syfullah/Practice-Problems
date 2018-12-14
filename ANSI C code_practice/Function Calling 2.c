#include <stdio.h>
#include <conio.h>
void print_msg(void)
{
    printf("This is print_massage() function");
}
int sqr_val(int value)
{
    print_msg();
    return(value*value);
}
int main(void)
{
    int value;
    value=sqr_val(5);
    printf("\n\nSquare value is %d",value);
    getch();
    return 0;
}
