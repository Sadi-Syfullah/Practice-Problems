#include <stdio.h>
#include <conio.h>
#define ROW 3
#define COL 5
int main()
{
    int row, col;
    int array2d[ROW][COL] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
    for(row=0; row<ROW; row++)
    {
        for(col=0; col<COL; col++)
        {
            printf("\nElement [%d][%d]=%d",row,col,array2d[row][col]);
        }
    }
    getch();
    return 0;
}
