//0*11
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int id_num;
    int st_val;
    struct node *link0;
    struct node *link1;
};
struct node *start, *q, *ptr;
int vst_arr[100], a[10];
int main()
{
    freopen("DFA.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int count, i, posi, j;
    char n[10];
    printf("Enter the number of states: ");
    scanf("%d",&count);

    q=(struct node *)malloc(sizeof(struct node)*count);

    for(i=0; i<count; i++)
    {
        (q+i)->id_num=i;

        printf("State Machine::%d\n",i);
        printf("Next State if i/p is 0: ");
        scanf("%d",&posi);
        (q+i)->link0=(q+posi);

        printf("Next State if i/p is 1: ");
        scanf("%d",&posi);
        (q+i)->link1=(q+posi);

        printf("Is the state final state(0/1)? ");
        scanf("%d",&(q+i)->st_val);
    }

    printf("Enter the Initial State: ");
    scanf("%d",&posi);
    start=q+posi;
    while(1)
    {
        ptr=start;
        printf("Enter the string of inputs: ");
        scanf("%s",n);
        posi=0;

        while(n[posi]!='\0')
        {
            a[posi]=(n[posi]-'0');
            posi++;
        }

        i=0;
        printf("The visited States: ");
        do
        {
            vst_arr[i]=ptr->id_num;
            if(a[i]==0)
            {
                ptr=ptr->link0;
            }
            else if(a[i]==1)
            {
                ptr=ptr->link1;
            }
            else
            {
                printf("iNCORRECT iNPUT\n");
                break;
            }
            printf("[%d]",vst_arr[i]);
            i++;
        }
        while(i<posi);

        printf("\n");
        printf("Present State:%d\n",ptr->id_num);
        printf("String Status:: ");
        if(ptr->st_val==1)
            printf("String Accepted\n");
        else
            printf("String Not Accepted\n");
        return 0;
    }
    return 0;
}
