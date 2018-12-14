#include<stdio.h>
int main()
{
    int a,i,j,k,l,m,n,o,p;
    while(scanf("%d",&a)!=EOF)
    {
        for(i=0; a>=500; i++)
            a=a-500;
        printf("500 money =%d\n",i);
        for(j=0; a>=100; j++)
            a=a-100;
        printf("100 money =%d\n",j);
        for(k=0; a>=50; k++)
            a=a-50;
        printf(" 50 money =%d\n",k);
        for(l=0; a>=20; l++)
            a=a-20;
        printf(" 20 money =%d\n",l);
        for(m=0; a>=10; m++)
            a=a-10;
        printf(" 10 money =%d\n",m);
        for(n=0; a>=5; n++)
            a=a-5;
        printf("  5 money =%d\n",n);
        for(o=0; a>=2; o++)
            a=a-2;
        printf("  2 money =%d\n",o);
        for(p=0; a>=1; p++)
            a=a-1;
        printf("  1 money =%d\n\n\n",p);
    }
    return 0;
}
