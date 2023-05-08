#ifndef __COW_H__
#define __COW_H__

typedef struct                      // Le type cow est une structure anonyme qui contient les attributs de la vache.
{
    char eyes[2];                   // Les yeux de la vache.
    char tongue[2];                 // La langue.
    int sayPos;                     // La position du premier argument qui n'est pas une option.
    int width;                      // La taille max de la bulle de texte.
    int tail;                       // Taille de la queue.
    int tall;                       // Taille des jambes.
    int neck;                       // Taille du cou.
    int color[16];                  // Tableau contenant les couleurs pour l'affichage.
    int colorLen;                   // Nombre de couleurs, entre 1 et 16.
} cow;

#endif