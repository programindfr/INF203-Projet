#include <stdlib.h>
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
        .color = { WHITE, },
        .colorLen = 1
    };

    int newargc = argc - 1;
    int newsize = read_size(argc, argv);
    char **newargv;

    newargv = malloc(newargc * sizeof(*newargv));
    for (int i = 0; i < newargc; i++)
    {
        newargv[i] = malloc(newsize * sizeof(newargv[0]));
    }

    read_vache(argc, argv, newargv);
    options_vache(&vache, newargc, newargv);
    affiche_vache(vache, newargc, newargv);

    return 0;
}