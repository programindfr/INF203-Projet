#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>



int color_printf(char *chaine, int colorLen, int *color, ...)       // La fonction affiche en couleur.
{
    char buffer[4096];
    va_list args;
    va_start(args, color);                                          // Les arguments après color sont à capturer.
    int rc = vsnprintf(buffer, sizeof(buffer), chaine, args);       // Formate le texte avec les variables en argument.
    va_end(args);                                                   // On libère après la capture.
    for (int i = 0; buffer[i] != '\0'; i++)
    {
        int random = rand() % colorLen;                             // Couleur aléatoire.
        printf("\033[0;%dm%c", color[random], buffer[i]);           // Affiche chaque caractère d'une couleur différente.
    }
    return rc;
}