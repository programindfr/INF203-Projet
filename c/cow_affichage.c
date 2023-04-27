#include <stdio.h>
#include <stdlib.h>
#include "cow.h"
#include "chaine_operation.h"



void
affiche_textbox(cow vache, int argc, char *argv[])      // Pas fini...
{
    int texteLength = 0;
    int position = (vache.sayPos == -1) ? argc : vache.sayPos;
    
    for (int i = position; i < argc; i++)
    {
        texteLength += longueur_chaine(argv[i]) + 1;
    }
    
    printf(" __");

    for (int i = 1; i < texteLength && i < vache.width; i++)
    {
        printf("_");
    }

    printf("\n< ");

    for (int i = position; i < argc; i++)
    {
        printf("%s%c", argv[i], (i + 1 < argc) ? ' ' : '\0');
    }

    printf(" >\n -");

    for (int i = 1; i < texteLength && i < vache.width; i++)
    {
        printf("-");
    }

    printf("-\n");
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
    printf("        \\   ^__^%s\n", neckChar);
    printf("         \\  (%c%c)%s\\_______\n", vache.eyes[0], vache.eyes[1], neckChar); // On affiche les yeux contenus dans les attributs de la vache.
    printf("            (__)%s\\       )", neckSpace);
    for (int i = 0; i < vache.tail; i++)
    {
        printf("%c", (i % 2 == 0) ? '\\' : '/');
    }
    printf("\n             %c%c %s||----w |\n", vache.tongue[0], vache.tongue[1], neckSpace);  // On affiche la langue contenu dans les attributs de la vache.
    for (int i = 0; i < vache.tall; i++)
    {
        printf("                %s||     ||\n", neckSpace);
    }
}