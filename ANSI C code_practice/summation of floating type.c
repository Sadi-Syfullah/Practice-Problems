#include<stdio.h>
int main()
{
    while(1)
    {
        float x,i,sum;
        printf("what's the last digit??  ");
        scanf("%f",&x);
        sum=0;
        for(i=1; i<=x; i++)
            sum+=(1/i);
        printf("%0.3f\n\n",sum);
    }
    return 0;
}

