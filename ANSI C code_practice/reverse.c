#include<stdio.h>
int main()
{
    int x,y,a;
    while(scanf("%d",&x)!=EOF)
    {
        while(x>0)
        {
            y=x%10;
            printf("%d",y);
            x=x/10;
        }
        printf("\n\n");
    }
    return 0;
}
