#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "cow.h"
#include "chaine_operation.h"
#include "printf_color.h"



void
affiche_textbox(cow vache, int argc, char *argv[])      // Pas fini, mais la taille de la bulle s'adapte à la longeur du texte s'il est moins long que la taille définie.
{
    int texteLength = 0;
    int position = (vache.sayPos == -1) ? argc : vache.sayPos;      // Position du premier mot.
    
    for (int i = position; i < argc; i++)
    {
        texteLength += longueur_chaine(argv[i]) + 1;                // On mesure la taille de ce qu'il faut écrire.
    }
    
    color_printf(" __", vache.colorLen, vache.color);

    for (int i = 1; i < texteLength && i < vache.width; i++)
    {
        color_printf("_", vache.colorLen, vache.color);             // Affiche les _ du haut.
    }

    color_printf("\n< ", vache.colorLen, vache.color);

    for (int i = position; i < argc; i++)
    {
        color_printf("%s%c", vache.colorLen, vache.color, argv[i], (i + 1 < argc) ? ' ' : '\0');        // Affiche les mots.
    }

    color_printf(" >\n -", vache.colorLen, vache.color);

    for (int i = 1; i < texteLength && i < vache.width; i++)
    {
        color_printf("-", vache.colorLen, vache.color);             // Affiche les - du bas.
    }

    color_printf("-\n", vache.colorLen, vache.color);
}


void
affiche_vache(cow vache, int argc, char *argv[])                            // Affiche la vache avec ses attributs.
{
    affiche_textbox(vache, argc, argv);                                     // Affiche la bulle de texte.
    char *neckChar = malloc(vache.neck * sizeof(char));                     // Tableaux pour la taille du cou de la vache.
    char *neckSpace = malloc(vache.neck * sizeof(char));
    if (neckChar == NULL || neckSpace == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire.\n");
    }
    for (int i = 0; i < vache.neck; i++)                                    // On remplit les deux tableaux.
    {
        neckChar[i] = '_';
        neckSpace[i] = ' ';
    }
    // On affiche la vache.
    color_printf("        \\   ^__^%s\n", vache.colorLen, vache.color, neckChar);
    color_printf("         \\  (%c%c)%s\\_______\n", vache.colorLen, vache.color, vache.eyes[0], vache.eyes[1], neckChar); // On affiche les yeux contenus dans les attributs de la vache.
    color_printf("            (__)%s\\       )", vache.colorLen, vache.color, neckSpace);
    for (int i = 0; i < vache.tail; i++)
    {
        color_printf("%c", vache.colorLen, vache.color, (i % 2 == 0) ? '\\' : '/');     // On affiche un queue plus ou moins grande.
    }
    color_printf("\n             %c%c %s||----w |\n", vache.colorLen, vache.color, vache.tongue[0], vache.tongue[1], neckSpace);  // On affiche la langue contenu dans les attributs de la vache.
    for (int i = 0; i < vache.tall; i++)
    {
        color_printf("                %s||     ||\n", vache.colorLen, vache.color, neckSpace);      // On affiche des jambes plus ou moins grandes.
    }
}


void
affiche_vache2(cow vache, int argc, char *argv[])                            // Affiche la vache avec ses attributs.
{                                                                           // c'est pas fini et ça marche pas. J'ai pas réussi à finir.
    char buffer[4112];
    int pos = 0;
    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j] != '\0'; j++)
        {
            printf("\033[H\033[J");
            char tmp[4096] = "./newcow -T \"";
            tmp[13] = argv[i][j];
            tmp[14] = ' ';
            tmp[15] = '"';
            for (int k = 0; k < pos; k++)
            {
                tmp[16 + k] = buffer[k];
            }
            system(tmp);
            buffer[pos] = argv[i][j];
            pos++;
            sleep(1);
        }
    }
}