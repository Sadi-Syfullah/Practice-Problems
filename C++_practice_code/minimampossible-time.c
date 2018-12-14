#include<stdio.h>
#define num_line 2
#define num_station 6
int min(int a,int b)
{
    return a<b? a:b;
}
int carassembly(int a[][num_station],int t[][num_station],int *e,int *x)
{
    int t1[num_station],t2[num_station],i;
    t1[0]=e[0]+a[0][0];
    t2[0]=e[1]+a[1][0];

    for (i=1; i<num_station; i++)
    {
        t1[i]=min(t1[i-1]+a[0][i],t2[i-1]+t[1][i]+a[0][i]);
        t2[i]=min(t2[i-1]+a[1][i],t1[i-1]+t[0][i]+a[1][i]);

    }
    return min(t1[num_station-1]+x[0],t2[num_station-1]+x[1]);

}
int main()
{
    int a[][num_station]= {{7,9,3,4,8,4},{8,5,6,4,5,7}};
    int t[][num_station]= {{0,2,3,1,3,4},{0,2,1,2,2,1}};
    int e[]= {2,4},x[]= {3,2};
    printf("%d",carassembly(a,t,e,x));
    return 0;
}

