#include <stdio.h>
#include <conio.h>
void main(void)
{
    int x=0,y=0,z=0,a=0,b=0,c=0;
    printf("(x=1)&&(x=2)&&(x=2)=%d\n",(x=1)||(x=2)||(x=3));
    printf("x=%d y=%d z=%d\n\n",x,y,z);
    printf("(a=1)&&b&&(c=3)=%d\n",a||(b=1)||(c=3));
    printf("a=%d b=%d c=%d",a,b,c);
    getch();
}
