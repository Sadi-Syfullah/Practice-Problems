//Written by Iqbal Mahmud
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
int main()
{
    char ch;
    printf("Enter a character: ");
    scanf("%c",&ch);
    if(isalnum(ch))
        printf("The character is alpha numeric");
    else
        printf("The character is not alpha numeric");
    getch();
    return 0;
}
