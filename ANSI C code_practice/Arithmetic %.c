#include <stdio.h>
#include <conio.h>
void main()
{
    int X=25,Y=7;
    printf(" X mod  Y  =  %d\n",X%Y);
    printf(" X mod -Y  =  %d\n",X%-Y);
    printf("-X mod  Y  = %d\n",-X%Y);
    printf("-X mod -Y  = %d\n",-X%-Y);
    getch();
    return 0;
}
