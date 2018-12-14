#include<stdio.h>
#include <conio.h>
#define pi 3.1416
int main()
{
    float r1,r2,r3,volume;
    printf("enter the value of r1 r2 r3:\n");
    scanf("%f%f%f",&r1,&r2,&r3);
    volume=(4*pi*r1*r2*r3)/3;
    printf("The volume is=%f",volume);
    return 0;

}
