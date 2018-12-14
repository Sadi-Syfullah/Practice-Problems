#include<stdio.h>
int main()
{
    int x,i,sum=0;
    printf("what's the last digit??  ");
    scanf("%d",&x);
    for(i=0; i<=x; i++)
        sum+=i;
    printf("%d\n\n",sum);
    return 0;
}
