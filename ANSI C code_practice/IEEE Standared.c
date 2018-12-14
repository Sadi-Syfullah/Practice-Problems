#include <stdio.h>
#include <conio.h>
void main()
{
    float a=10.375;
    char *p;
    int i;
    p=(char *)&a;
    for (i=0; i<=3;i++)
    printf ("%02x", (unsigned char)p[i]);
    getch();
}
