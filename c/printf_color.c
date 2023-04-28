#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>



int color_printf(char *chaine, int colorLen, int *color, ...)
{
    char buffer[4096];
    va_list args;
    va_start(args, color);
    int rc = vsnprintf(buffer, sizeof(buffer), chaine, args);
    va_end(args);
    for (int i = 0; buffer[i] != '\0'; i++)
    {
        int random = rand() % colorLen;
        printf("\033[0;%dm%c", color[random], buffer[i]);
    }
    return rc;
}