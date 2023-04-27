#include <stdio.h>
#include <unistd.h>


void
update()
{
    printf("\033[H\033[J");
}

void
gotoxy(int x ,int y)
{
    printf("\033[%d;%dH", y, x);
}


int
main(int argc, char *argv[])
{
    update();
    printf("Hello World !\nHello World !\nHello World !\nHello World !\nHello World !\nHello World !\nHello World !\n");
    gotoxy(0, 0);
    printf("\033[0;96mMathias");
    gotoxy(0, 8);
    printf("\033[39m");
    return 0;
}