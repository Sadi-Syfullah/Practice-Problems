#include <stdio.h>
#include <conio.h>
void main()
{
    char ch;
    printf("Press any key without N or n to hear a noisy sound: ");
    ch=getche();
    while((ch!='N')&&(ch!='n'))
    {
        putch('\a');
        putch('\b');
        ch=getche();
    }
    printf("\n\n\nThank you for not hearing a noisy sound.");
    getch;
    return 0;
}
