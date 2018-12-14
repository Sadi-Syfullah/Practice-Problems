#include<stdio.h>
int main()
{
    int x,y;
    while(scanf("%d",&y)!=EOF)
    {
        x=y-1421;
        //printf("%d\n",x);
        if(x%3==0)
            printf("the programme will be held\n");
        else
            printf("the programme won't be held\n");
    }
    return 0;
}
