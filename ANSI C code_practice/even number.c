#include<stdio.h>
int main()
{
    int x,i,j=0,sum=0;
    printf("what's the last digit??  ");
    scanf("%d",&x);
    for(i=0; i<=x; i++){
        sum+=j;
    j+=2;
    }
    printf("%d\n\n",sum);
    return 0;
}
