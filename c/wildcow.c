#include <stdio.h>


void
update()
{
    printf("\033[H\033[J");
}

void
gotoxy(int x ,int y)
{
    printf("\033[%d;%dH", x, y);
}


int
main(int argc, char *argv[])
{
    printf("Hello World !");
    gotoxy(4, 0);
    // update();
    return 0;
}