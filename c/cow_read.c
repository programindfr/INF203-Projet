#include <stdio.h>
#include "chaine_operation.h"



void
read_vache(int argc, char *argv[], char *outv[])
{
    for (int i = 1; i < argc; i++)
    {
        outv[i - 1] = argv[i];
    }
}


int
read_size(int argc, char *argv[])
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