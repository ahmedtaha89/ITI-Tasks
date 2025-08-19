#include<stdio.h>
#include<windows.h>
#include <conio.h>
void gotoxy(int x,int y);
void draw_box();
void main(void){
    char *menu[5] = { "-1) Add a new record            ", "-2) Update a new record         ", "-3) Delete an existing record   ", "-4) Exit                        " };
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    int pos=1;
    char ch;
    draw_box();
    do{
            SetConsoleTextAttribute(Console,15);
            gotoxy(45,15);
            printf(" %s",menu[0]);
            gotoxy(45,17);
            printf(" %s",menu[1]);
            gotoxy(45,19);
            printf(" %s",menu[2]);
            gotoxy(45,21);
            printf(" %s",menu[3]);
    switch(pos){
    case 1:
            SetConsoleTextAttribute(Console,240);
            gotoxy(45,15);
            printf(" %s",menu[0]);
            break;
    case 2:
            SetConsoleTextAttribute(Console,240);
            gotoxy(45,17);
            printf(" %s",menu[1]);
            break;
    case 3 :
            SetConsoleTextAttribute(Console,240);
            gotoxy(45,19);
            printf(" %s",menu[2]);
            break;
    case 4 :
            SetConsoleTextAttribute(Console,240);
            gotoxy(45,21);
            printf(" %s",menu[3]);
            break;
    }
        ch=getch();
        if(ch==-32)
            ch=getch();
        if(ch==72)
        {
            pos--;
            if(pos==0)
                pos=4;
        }
        if(ch==80){
            pos++;
            if(pos==5)
                pos=1;
        }
 }while(ch!=13);

 gotoxy(45,25);
 SetConsoleTextAttribute(Console,15);
 printf("Your selection is %s \n",menu[pos-1]);

}

void gotoxy(int x,int y){
COORD coord ={0,0};
coord.X=x;
coord.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void draw_box()
{
    gotoxy(44,14);
    printf("%c",201);

    for(int i=0;i<33;i++)
        printf("%c",205);

    printf("%c",187);
    gotoxy(44,15);

    for(int i=0;i<10;i++)
    {
     printf("%c",186);
     gotoxy(44,15+i);
    }
    gotoxy(78,15);

    for(int i=0;i<10;i++)
    {
     printf("%c",186);
     gotoxy(78,15+i);
    }

    gotoxy(45,24);
    for(int i=0;i<33;i++)
    printf("%c",205);

     gotoxy(44,24);
    printf("%c",200);

    gotoxy(78,24);
    printf("%c",188);

}
