#include <stdio.h>
#include "chaine_operation.h"



void
read_vache(int argc, char *argv[], char *outv[])        // Copie de tableaux 2d.
{
    for (int i = 0; i < argc; i++)
    {
        for (int j = 0; argv[i][j] != '\0'; j++)
        {
            outv[i][j] = argv[i][j];
        }
    }
}


int
read_size(int argc, char *argv[])       // Donne la taille du plus grand element d'un tableau 2d.
{
    int maxSize = 0;
    int size;
    for (int i = 0; i < argc; i++)
    {
        size = longueur_chaine(argv[i]);
        if (size > maxSize) {
            maxSize = size;
        }
    }
    return maxSize;
}