#include <stdarg.h>
#include <stdio.h>



int color_printf(char *chaine, int color, ...)
{
    char buffer[4096];
    va_list args;
    va_start(args, color);
    int rc = vsnprintf(buffer, sizeof(buffer), chaine, args);
    va_end(args);
    for (int i = 0; buffer[i] != '\0'; i++)
    {
        printf("\033[0;%dm%c", color, buffer[i]);
    }
    return rc;
}