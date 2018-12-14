#include <stdio.h>
#include <conio.h>
int x=100;
void global_var(void);
void static_var(void);
void local_var(void);
int main(void)
{
    printf("First Time: \n");
    local_var();
    static_var();
    global_var();
    printf("Second Time: \n");
    local_var();
    static_var();
    global_var();
    getch();
    return (0);
}
void local_var(void)
{
    int x=1;
    printf("     As a local variable:\n\t");
    printf("x=%d\n\t",x);
    x++;
    printf("x++=%d\n\n",x++);
}
void static_var(void)
{
    static int x=10;
    printf("     As a static variable:\n\t");
    printf("x=%d\n\t",x);
    x++;
    printf("x++=%d\n\n",x++);
}
void global_var(void)
{
    printf("     As a global variable:\n\t");
    printf("x=%d\n\t",x);
    x++;
    printf("x++=%d\n\n",x++);
}
