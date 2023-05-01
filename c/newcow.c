#include "cow_traitement.h"
#include "cow_affichage.h"
#include "cow.h"
#include "printf_color.h"



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

    options_vache(&vache, argc, argv);
    affiche_vache(vache, argc, argv);

    return 0;
}