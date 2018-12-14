#include<stdio.h>
#include<string.h>
int current;
int num_acc;
int name_check(char*);
void new_acc();
void deposite();
void withdraw();
void balance();
int main()
{
    char menu;
    int num_acc=0;
    while(1)
    {
        printf("\n\n\nWelcome to ANTINODE Banking Service.\nChoose an option : \n\n1. New Account\n2. Deposite\n3. Withdraw\n4. Balance Check\n5. Exit\n\nThank You for Banking With Us.");
        menu=getch();
        switch(menu)
        {
            case '1':new_acc();
            break;
            case '2':deposite();
            break;
    //        case '3':withdraw();
      //      break;
        //    case '4':balance();
          //  break;
            case '5':

                return 0;
        }
    }
    return 0;
}

void new_acc()
{
    char acc_name[31];
    char acc_fname[31];
    int d,m,y;
    getch();
    printf("\n\n\nName : ");
    gets(acc_name);
    printf("\nFather's Name : ");
    gets(acc_fname);
    printf("\nDate of Birth : ");
    scanf("%d.%d.%d",&d,&m,&y);
    printf("\nYour Account Has Been Successfully Created.Your Account No. %d%d%d",d,m,y);
}

void deposite()
{
    int add_sum;
    int balnc=0;
    printf("\nHow Much Would You Like to Deposite?\n: tk.");
    scanf("%d",&add_sum);
    balnc+=add_sum;
    printf("Your Account Balance is tk.%d",balnc);
}
