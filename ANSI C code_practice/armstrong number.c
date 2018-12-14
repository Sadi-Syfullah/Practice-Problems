#include<stdio.h>

int main()
{
    while(1){
    int x,y,z,sum;
    printf("Put your desired number");
    scanf("%d",&x);
    x=y;
    sum=0;
    printf("\n");
    while(y>0)
    {
        z=x%10;
        sum+=(z*z*z);
        y=y/10;
    }
    if(x==sum)
        printf("%d is an armstrong number\n",sum);
    else
        printf("%d is not an armstrong number\n",sum);}
    return 0;
}

