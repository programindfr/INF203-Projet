#include <stdio.h>
#include <stdlib.h>
#include "cow.h"
#include "chaine_operation.h"
#include "printf_color.h"

int color = GREEN;

void
affiche_textbox(cow vache, int argc, char *argv[])      // Pas fini...
{
    int texteLength = 0;
    int position = (vache.sayPos == -1) ? argc : vache.sayPos;
    
    for (int i = position; i < argc; i++)
    {
        texteLength += longueur_chaine(argv[i]) + 1;
    }
    
    color_printf(" __", color);

    for (int i = 1; i < texteLength && i < vache.width; i++)
    {
        color_printf("_", color);
    }

    color_printf("\n< ", color);

    for (int i = position; i < argc; i++)
    {
        color_printf("%s%c", color, argv[i], (i + 1 < argc) ? ' ' : '\0');
    }

    color_printf(" >\n -", color);

    for (int i = 1; i < texteLength && i < vache.width; i++)
    {
        color_printf("-", color);
    }

    color_printf("-\n", color);
}


void
affiche_vache(cow vache, int argc, char *argv[])                            // Affiche la vache avec ses attributs.
{
    affiche_textbox(vache, argc, argv);
    char *neckChar = malloc(vache.neck * sizeof(char));
    char *neckSpace = malloc(vache.neck * sizeof(char));
    if (neckChar == NULL || neckSpace == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire.\n");
    }
    for (int i = 0; i < vache.neck; i++)
    {
        neckChar[i] = '_';
        neckSpace[i] = ' ';
    }
    color_printf("        \\   ^__^%s\n", color, neckChar);
    color_printf("         \\  (%c%c)%s\\_______\n", color, vache.eyes[0], vache.eyes[1], neckChar); // On affiche les yeux contenus dans les attributs de la vache.
    color_printf("            (__)%s\\       )", color, neckSpace);
    for (int i = 0; i < vache.tail; i++)
    {
        color_printf("%c", color, (i % 2 == 0) ? '\\' : '/');
    }
    color_printf("\n             %c%c %s||----w |\n", color, vache.tongue[0], vache.tongue[1], neckSpace);  // On affiche la langue contenu dans les attributs de la vache.
    for (int i = 0; i < vache.tall; i++)
    {
        color_printf("                %s||     ||\n", color, neckSpace);
    }
}