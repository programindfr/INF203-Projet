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
    cow vache = {
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

    FILE *file = stdin;
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
        fscanf(file, "%c", &buffer[ichar]);
    }

    int newargc = argc + 1;
    int newsize = read_size(argc, argv);
    newsize = (newsize > ichar) ? newsize : ichar;
    char **newargv;

    newargv = malloc(newargc * sizeof(*newargv));
    for (int i = 0; i < newargc; i++)
    {
        newargv[i] = malloc(newsize * sizeof(newargv[0]));
    }

    read_vache(argc, argv, newargv);

    for (int i = 0; i < ichar; i++)
    {
        newargv[newargc - 1][i] = buffer[i];
    }

    options_vache(&vache, newargc, newargv);
    affiche_vache2(vache, newargc, newargv);

    return 0;
}