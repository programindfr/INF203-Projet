#include <stdio.h>
#include "cow.h"
#include "chaine_operation.h"

#define ARGUMENT 0                  // Etats pour l'automate de newcow.
#define OPTION1 1
#define OPTION2 2
#define FIN 3



void
options_vache(cow *vache, int argc, char *argv[])   // Cette fonction détermine et convertie les arguments en attributs de la vache.
{
    int passerArgument = 0;
    for (int i = 1; i < argc; i++)              // Boucle sur tout les arguments.
    {
        if (i + passerArgument >= argc || vache->sayPos != -1) {       // On arrête la boucle s'il n'y a plus d'argument après ou si du texte normal est trouvé.
            break;
        }
        i += passerArgument;
        passerArgument = 0;
        int etat = ARGUMENT;                    // Etat initial de l'automate.
        for (int j = 0; argv[i][j] != '\0'; j++)    // Boucle sur les caractères de l'argument.
        {
            switch (etat)
            {
            case ARGUMENT:
                switch (argv[i][j])
                {
                case '-':
                    etat = OPTION1;
                    break;
                
                default:
                    etat = FIN;
                    vache->sayPos = i;
                    break;
                }
                break;
            
            case OPTION1:
                switch (argv[i][j])
                {
                case '-':
                    etat = OPTION2;
                    break;

                case 'e':
                    etat = FIN;
                    if (argv[i][j + 1] != '\0') {       // On vérifie qu'il n'y a pas de lettre après.
                        fprintf(stderr, "Option %s inconnue.\n", argv[i]);
                        break;
                    }
                    if (i + 1 >= argc) {     // On vérifie qu'il existe un argument après.
                        fprintf(stderr, "Option -e argument manquant.\n");
                        break;
                    }
                    vache->eyes[0] = argv[i + 1][0];
                    vache->eyes[1] = argv[i + 1][1];
                    passerArgument = 1; // On saute le prochain argument.
                    break;
                
                case 'T':
                    etat = FIN;
                    if (argv[i][j + 1] != '\0') {       // On vérifie qu'il n'y a pas de lettre après.
                        fprintf(stderr, "Option %s inconnue.\n", argv[i]);
                        break;
                    }
                    if (i + 1 >= argc) {     // On vérifie qu'il existe un argument après.
                        fprintf(stderr, "Option -T argument manquant.\n");
                        break;
                    }
                    vache->tongue[0] = argv[i + 1][0];
                    vache->tongue[1] = argv[i + 1][1];
                    passerArgument = 1; // On saute le prochain argument.
                    break;
                
                case 'W':
                    etat = FIN;
                    if (argv[i][j + 1] != '\0') {       // On vérifie qu'il n'y a pas de lettre après.
                        fprintf(stderr, "Option %s inconnue.\n", argv[i]);
                        break;
                    }
                    if (i + 1 >= argc) {     // On vérifie qu'il existe un argument après.
                        fprintf(stderr, "Option -W argument manquant.\n");
                        break;
                    }
                    int result = sscanf(argv[i + 1], "%d", &(vache->width));
                    if (result != 1) {
                        fprintf(stderr, "Option -W argument %s non entier.\n", argv[i + 1]);
                        break;
                    }
                    passerArgument = 1; // On saute le prochain argument.
                    break;
                
                case 'b':
                    etat = FIN;
                    if (argv[i][j + 1] != '\0') {       // On vérifie qu'il n'y a pas de lettre après.
                        fprintf(stderr, "Option %s inconnue.\n", argv[i]);
                        break;
                    }
                    vache->eyes[0] = '=';
                    vache->eyes[1] = '=';
                    break;
                
                case 'd':
                    etat = FIN;
                    if (argv[i][j + 1] != '\0') {       // On vérifie qu'il n'y a pas de lettre après.
                        fprintf(stderr, "Option %s inconnue.\n", argv[i]);
                        break;
                    }
                    vache->eyes[0] = 'x';
                    vache->eyes[1] = 'x';
                    vache->tongue[0] = 'U';
                    vache->tongue[1] = ' ';
                    break;
                
                case 'g':
                    etat = FIN;
                    if (argv[i][j + 1] != '\0') {       // On vérifie qu'il n'y a pas de lettre après.
                        fprintf(stderr, "Option %s inconnue.\n", argv[i]);
                        break;
                    }
                    vache->eyes[0] = '$';
                    vache->eyes[1] = '$';
                    break;
                
                case 'p':
                    etat = FIN;
                    if (argv[i][j + 1] != '\0') {       // On vérifie qu'il n'y a pas de lettre après.
                        fprintf(stderr, "Option %s inconnue.\n", argv[i]);
                        break;
                    }
                    vache->eyes[0] = '@';
                    vache->eyes[1] = '@';
                    break;
                
                case 's':
                    etat = FIN;
                    if (argv[i][j + 1] != '\0') {       // On vérifie qu'il n'y a pas de lettre après.
                        fprintf(stderr, "Option %s inconnue.\n", argv[i]);
                        break;
                    }
                    vache->eyes[0] = '*';
                    vache->eyes[1] = '*';
                    vache->tongue[0] = 'U';
                    vache->tongue[1] = ' ';
                    break;
                
                case 't':
                    etat = FIN;
                    if (argv[i][j + 1] != '\0') {       // On vérifie qu'il n'y a pas de lettre après.
                        fprintf(stderr, "Option %s inconnue.\n", argv[i]);
                        break;
                    }
                    vache->eyes[0] = '-';
                    vache->eyes[1] = '-';
                    break;
                
                case 'w':
                    etat = FIN;
                    if (argv[i][j + 1] != '\0') {       // On vérifie qu'il n'y a pas de lettre après.
                        fprintf(stderr, "Option %s inconnue.\n", argv[i]);
                        break;
                    }
                    vache->eyes[0] = 'O';
                    vache->eyes[1] = 'O';
                    break;
                
                case 'y':
                    etat = FIN;
                    if (argv[i][j + 1] != '\0') {       // On vérifie qu'il n'y a pas de lettre après.
                        fprintf(stderr, "Option %s inconnue.\n", argv[i]);
                        break;
                    }
                    vache->eyes[0] = '.';
                    vache->eyes[1] = '.';
                    break;
                
                default:
                    etat = FIN;
                    fprintf(stderr, "Option %s inconnue.\n", argv[i]);
                    break;
                }
                break;
            
            case OPTION2:
                etat = FIN;
                if (compare_chaine("--eyes", argv[i])) {
                    if (i + 1 >= argc) {    // On vérifie qu'il existe un argument après.
                        fprintf(stderr, "Option --eyes argument manquant.\n");
                        break;
                    }
                    vache->eyes[0] = argv[i + 1][0];
                    vache->eyes[1] = argv[i + 1][1];
                    passerArgument = 1; // On saute le prochain argument.
                    break;
                } else if (compare_chaine("--tongue", argv[i])) {
                    if (i + 1 >= argc) {    // On vérifie qu'il existe un argument après.
                        fprintf(stderr, "Option --tongue argument manquant.\n");
                        break;
                    }
                    vache->tongue[0] = argv[i + 1][0];
                    vache->tongue[1] = argv[i + 1][1];
                    passerArgument = 1; // On saute le prochain argument.
                    break;
                } else if (compare_chaine("--tail", argv[i])) {
                    if (i + 1 >= argc) {    // On vérifie qu'il existe un argument après.
                        fprintf(stderr, "Option --tail argument manquant.\n");
                        break;
                    }
                    int result = sscanf(argv[i + 1], "%d", &(vache->tail));
                    if (result != 1) {
                        fprintf(stderr, "Option --tail argument %s non entier.\n", argv[i + 1]);
                        break;
                    }
                    passerArgument = 1; // On saute le prochain argument.
                    break;
                } else if (compare_chaine("--tall", argv[i])) {
                    if (i + 1 >= argc) {    // On vérifie qu'il existe un argument après.
                        fprintf(stderr, "Option --tall argument manquant.\n");
                        break;
                    }
                    int result = sscanf(argv[i + 1], "%d", &(vache->tall));
                    if (result != 1) {
                        fprintf(stderr, "Option --tall argument %s non entier.\n", argv[i + 1]);
                        break;
                    }
                    passerArgument = 1; // On saute le prochain argument.
                    break;
                } else if (compare_chaine("--neck", argv[i])) {
                    if (i + 1 >= argc) {    // On vérifie qu'il existe un argument après.
                        fprintf(stderr, "Option --neck argument manquant.\n");
                        break;
                    }
                    int result = sscanf(argv[i + 1], "%d", &(vache->neck));
                    if (result != 1) {
                        fprintf(stderr, "Option --neck argument %s non entier.\n", argv[i + 1]);
                        break;
                    }
                    passerArgument = 1; // On saute le prochain argument.
                    break;
                }
                fprintf(stderr, "Option %s inconnue.\n", argv[i]);
                break;
            
            case FIN:
                break;
            }
        }
    }
}