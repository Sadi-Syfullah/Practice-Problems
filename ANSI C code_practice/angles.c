#include <stdio.h>
#include <math.h>
int main()
{


    int n,ang;
    while(scanf("%d",&n)!=EOF)
    {

        for(n=3; n<=100; n++)
            ang=((n-2)*180);
        printf("%d\n",ang);

    }
    return 0;
}
