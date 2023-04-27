#ifndef __COW_H__
#define __COW_H__

typedef struct                      // Le type cow est une structure anonyme qui contient les attributs de la vache.
{
    char eyes[2];                   // Les yeux de la vache.
    char tongue[2];
    int sayPos;                     // La position du premier argument qui n'est pas une option.
    int width;
    int tail;
    int tall;
    int neck;
} cow;

#endif