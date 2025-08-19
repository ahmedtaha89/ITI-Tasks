#include <stdio.h>
#include<windows.h>
#include <time.h>

void goto_row_col(int row, int col){
    COORD c;
    c.X = col;
    c.Y = row;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void delay(int s){
    time_t start = time(NULL);
    while (time(NULL) - start < s);
}

void main(void){
    int size;
    int row,col,value;
    int k;

    do
    {
        printf("please odd number:");
        scanf("%d",&size);
    } 
    while (size%2==0);

    row=1;
    col=(size+1)/2;
    value=1;

    do
    {
        goto_row_col(row,col*4);
        printf("%4d",value);
        delay(1);
        if (value%size==0)
            row++;
        else
        {
            row--;
            col--;

            if (row==0) row=size;
            if (col==0) col=size;
        }
        value++;
    } while(value<=size*size);

}
