#include <stdio.h>
#include <conio.h>
void main()
{
    int a=5,b=10,c=15;
    printf("    -a    -b   -c\n");
    printf("--------------------\n");
    while(--a,--b,--c);
        printf("%5d %5d %5d\n ",a,b,c);
    getch();
    return 0;
}
