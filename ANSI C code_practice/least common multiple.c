#include<stdio.h>
#include<math.h>
int main()
{
    int x,y,m,z,lcm;
    while(scanf("%d %d",&x,&y)!=EOF)
    {
        m=x*y;
        if(x>y)
            z=x;
        else
            z=y;
        for(; z<=m; z++)
        {
            if(z%x==0&&z%y==0)
            {
                lcm=z;
                break;
            }
        }
        printf("the least common multiple is %d\n\n",lcm);
    }
    return 0;
}

