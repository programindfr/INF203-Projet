#include <stdio.h>
#include <time.h>
#include "cow_traitement.h"
#include "cow_affichage.h"
#include "cow.h"
#include "printf_color.h"


void
update()
{
    printf("\033[H\033[J");     // Positionne le curseur en haut à gauche de l'écran.
}

void
gotoxy(int x ,int y)
{
    printf("\033[%d;%dH", y, x);    // Positionne le curseur aux coordonnées.
}

void
reset()
{
    printf("\033[39m");     // Reset la couleur du texte.
}


int
main(int argc, char *argv[])
{
    cow vache = {               // Définit la vache.
        .eyes = { 'o', 'o' },
        .tongue = { ' ', ' ' },
        .sayPos = -1,
        .width = 40,
        .tail = 3,
        .tall = 1,
        .neck = 0,
        .color = {
            BRIGHT_RED, BRIGHT_GREEN, BRIGHT_YELLOW, BRIGHT_BLUE,
            BRIGHT_MAGENTA, BRIGHT_CYAN, BRIGHT_WHITE, RED, GREEN,
            YELLOW, BLUE, MAGENTA, CYAN, WHITE, GREY, BLACK
        },
        .colorLen = 16
    };
    struct timespec ts = {      // Structure de temps de 0.1s.
        .tv_sec = 0,
        .tv_nsec = 100 * 1000000
    };

    options_vache(&vache, argc, argv);      // Change la vache en fonction des options.
    for (int i = 0; i < 60; i++)            // Pendant 6s.
    {
        update();                           // Efface l'écran.
        affiche_vache(vache, argc, argv);   // Affiche en couleur.
        nanosleep(&ts, &ts);                // Pause de 0.1s.
    }
    reset();                                // Reset la couleur d'affichage.

    return 0;
}