#include<stdio.h>
int main()
{
    int m,n,i,s,a,b;
    while(scanf("%d",&m)!=EOF)
    {
        b=1;
        s=m-1;
        for(i=1; i<=m; i++)
        {
            for(n=1; n<=s; n++)
                printf("  ");
            for(a=1; a<=i; a++)
                printf(" %3d",b);
            b++;
            printf("\n");
            s--;
        }
        printf("\n\n");
    }
    return 0;
}
