#include<stdio.h>
int main()
{
    while(1)
    {
        int x,i,j;
        printf("\nwhat's will be the line?? ");
        printf("\n\n\a");
        scanf("%d",&x);
        for(i=1; i<=x; i++)
        {
            if(i==1||i==x)
            {
                for(j=1; j<=x; j++)
                    printf("b");
                    printf("\n");
            }
            else
            {
                for(j=1; j<=x; j++)
                {
                    if(j==(x-i+1))
                        printf("b");
                    else
                        printf(" ");
                }
                printf("\n");
            }
        }
    }
    return 0;
}
