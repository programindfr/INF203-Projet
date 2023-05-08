#include <stdio.h>
#include <stdlib.h>
#include "cow_affichage.h"
#include "cow_read.h"

int etat = 0; // Etats 0 1 2 pour rocklife lifesucks byebyelife
int fitness = 5;
int stock = 5;
int crop;
int digestion;
int lunchfood;
int lifetime = 0;

void
stock_update(int lunchfood)
{
    stock = stock - lunchfood + rand() % 3; // pas aléatoire
}

void 
fitness_update(int lunchfood)
{
    fitness = fitness + lunchfood + rand() % 3;
}

void
transition(int fitness)
{
    printf("fitness = %d\n", fitness);
    switch (fitness)
    {
    case 0:
        etat = 2;
        break;

    
    case 4:
        etat = 0;
        break;
    
    case 5:
        etat = 0;
        break;

    case 6:
        etat = 0;
        break;

    default:
        etat = 1;
        break;

    case 10:
        etat = 2;
        break;
    }
}


int
main()
{
    while (!(etat==2))
    {
        // affiche_vache();
        printf("stock : %d\n", stock);
        lifetime += 1;
        printf("Lunchfood : ");
        scanf("%d", &lunchfood); // (entrée) attention fausses entrees
        stock_update(lunchfood); // actualiser stock
        fitness_update(lunchfood); // actualiser fitness
        transition(fitness);       // (transition)
    }
    // affiche byebyelife
    printf("Votre score est : %d\n", lifetime);
}