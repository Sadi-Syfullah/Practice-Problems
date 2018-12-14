#include <stdio.h>
int main()
{
    int c,s,t,n;
    c=0;
    t=0;
    scanf("%d",&n);
    while(c<n)
    {

        scanf("%d",&s);
        t+=s;
        printf("resut=%d\n\n",t);
        c++;
    }
    getch();
    return 0;
}
