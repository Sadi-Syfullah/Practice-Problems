#include <stdio.h>
#include <conio.h>
int func_elmnt(int val1,int val2);
int main()
{
    int x,romi[5]={5,6,7,8};
    x=func_elmnt(romi[1],romi[3]);
    printf("\n Return value is: %d",x);
    getch();
    return 0;
}
int func_elmnt(int val1, int val2)
{
    int y;
    y=val1+val2;
    return y;
}
