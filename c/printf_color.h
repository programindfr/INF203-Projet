#ifndef __COLOR_PRINTF_H__
#define __COLOR_PRINTF_H__

#define BLACK 30            // define les couleurs selon ANSI escape code.
#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define MAGENTA 35
#define CYAN 36
#define WHITE 37
#define GREY 90
#define BRIGHT_RED 91
#define BRIGHT_GREEN 92
#define BRIGHT_YELLOW 93
#define BRIGHT_BLUE 94
#define BRIGHT_MAGENTA 95
#define BRIGHT_CYAN 96
#define BRIGHT_WHITE 97

int color_printf(char *chaine, int colorLen, int *color, ...);    // color est de taille 16

#endif