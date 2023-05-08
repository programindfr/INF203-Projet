#include <stdlib.h>
#include <stdio.h>
#include "cow_traitement.h"
#include "cow_affichage.h"
#include "cow.h"
#include "printf_color.h"
#include "cow_read.h"



int
main(int argc, char *argv[])
{
    cow vache = {                   // Crée la vache.
        .eyes = { 'o', 'o' },
        .tongue = { ' ', ' ' },
        .sayPos = -1,
        .width = 40,
        .tail = 3,
        .tall = 1,
        .neck = 0,
        .color = { BRIGHT_WHITE, },
        .colorLen = 1
    };

    FILE *file = stdin;                 // Si le premier argument est un fichier on le lis sinon on prends depuis stdin.
    if (argc > 1) {
        file = fopen(argv[1], "r");
        if (file == NULL) {
            file = stdin;
        }
    }

    char buffer[4096];
    int ichar = 0;
    fscanf(file, "%c", &buffer[ichar]);
    while (!feof(file))
    {
        ichar++;
        fscanf(file, "%c", &buffer[ichar]);     // On stock le contenu du fichier.
    }

    int newargc = argc + 1;
    int newsize = read_size(argc, argv);
    newsize = (newsize > ichar) ? newsize : ichar;
    char **newargv;

    newargv = malloc(newargc * sizeof(*newargv));
    for (int i = 0; i < newargc; i++)
    {
        newargv[i] = malloc(newsize * sizeof(newargv[0]));      // Tableau 2d dynamiquement alloué.
    }

    read_vache(argc, argv, newargv);        // Copie.

    for (int i = 0; i < ichar; i++)
    {
        newargv[newargc - 1][i] = buffer[i];        // Ajout du texte après les options.
    }

    options_vache(&vache, newargc, newargv);    // Change la vache en fonction des options.
    affiche_vache2(vache, newargc, newargv);    // Affiche la vache (j'ai pas réussi à finir).

    return 0;
}