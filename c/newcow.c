/*-------------------------*\
| Définitions préprocesseur |
\*-------------------------*/
#include <stdio.h>

#define ARGUMENT 0                  // Etats pour l'automate de newcow.
#define OPTION1 1
#define OPTION2 2
#define FIN 3



/*-----------------------*\
| Structures et fonctions |
\*-----------------------*/
typedef struct                      // Le type cow est une structure anonyme qui contient les attributs de la vache.
{
    char eyes[2];                   // Les yeux de la vache.
    char tongue[2];
    int sayPos;                     // La position du premier argument qui n'est pas une option.
    int width;
    int tail;
} cow;


int
compare_chaine(char *chaine1, char *chaine2)        // Fonction qui compare deux chaînes de caractères. Elle renvoie 1 si elles sont identiques, sinon 0.
{
    int len1 = 0;
    for (; chaine1[len1] != '\0'; len1++) {}        // len1 est la taille de la chaîne 1.

    int len2 = 0;
    for (; chaine2[len2] != '\0'; len2++) {}        // len2 est la taille de la chaîne 2.

    if (len1 != len2) { return 0; }                 // Les tailles sont différentes, donc les chaînes aussi.

    for (int i = 0; i < len1; i++)
    {
        if (chaine1[i] != chaine2[i]) { return 0; } // Un caractère est différent.
    }

    return 1;                                       // Ici les chaînes sont forcément identiques.
}


int
longueur_chaine(char *chaine)                       // Donne la longueur d'une chaine.
{
    int i = 0;
    for (; chaine[i] != '\0'; i++) {}
    return i;
}


void
affiche_textbox(cow vache, int argc, char *argv[])      // Pas fini...
{
    int texteLength = 0;
    int position = (vache.sayPos == -1) ? argc : vache.sayPos;
    
    for (int i = position; i < argc; i++)
    {
        texteLength += longueur_chaine(argv[i]) + 1;
    }
    
    printf(" __");

    for (int i = 1; i < texteLength && i < vache.width; i++)
    {
        printf("_");
    }

    printf("\n< ");

    for (int i = position; i < argc; i++)
    {
        printf("%s%c", argv[i], (i + 1 < argc) ? ' ' : '\0');
    }

    printf(" >\n _");

    for (int i = 1; i < texteLength && i < vache.width; i++)
    {
        printf("_");
    }

    printf("_\n");
}


void
affiche_vache(cow vache, int argc, char *argv[])                            // Affiche la vache avec ses attributs.
{
    affiche_textbox(vache, argc, argv);
    printf("        \\   ^__^\n");
    printf("         \\  (%c%c)\\_______\n", vache.eyes[0], vache.eyes[1]); // On affiche les yeux contenus dans les attributs de la vache.
    printf("            (__)\\       )");
    for (int i = 0; i < vache.tail; i++)
    {
        printf("%c", (i % 2 == 0) ? '\\' : '/');
    }
    printf("\n             %c%c ||----w |\n", vache.tongue[0], vache.tongue[1]);  // On affiche la langue contenu dans les attributs de la vache.
    printf("                ||     ||\n");
}


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
                    if (argv[i][j + 1] != '\0') {
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
                    if (argv[i][j + 1] != '\0') {
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
                
                case 'b':
                    etat = FIN;
                    if (argv[i][j + 1] != '\0') {
                        fprintf(stderr, "Option %s inconnue.\n", argv[i]);
                        break;
                    }
                    vache->eyes[0] = '=';
                    vache->eyes[1] = '=';
                    break;
                
                case 'd':
                    etat = FIN;
                    if (argv[i][j + 1] != '\0') {
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
                    if (argv[i][j + 1] != '\0') {
                        fprintf(stderr, "Option %s inconnue.\n", argv[i]);
                        break;
                    }
                    vache->eyes[0] = '$';
                    vache->eyes[1] = '$';
                    break;
                
                case 'p':
                    etat = FIN;
                    if (argv[i][j + 1] != '\0') {
                        fprintf(stderr, "Option %s inconnue.\n", argv[i]);
                        break;
                    }
                    vache->eyes[0] = '@';
                    vache->eyes[1] = '@';
                    break;
                
                case 's':
                    etat = FIN;
                    if (argv[i][j + 1] != '\0') {
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
                    if (argv[i][j + 1] != '\0') {
                        fprintf(stderr, "Option %s inconnue.\n", argv[i]);
                        break;
                    }
                    vache->eyes[0] = '-';
                    vache->eyes[1] = '-';
                    break;
                
                case 'w':
                    etat = FIN;
                    if (argv[i][j + 1] != '\0') {
                        fprintf(stderr, "Option %s inconnue.\n", argv[i]);
                        break;
                    }
                    vache->eyes[0] = 'O';
                    vache->eyes[1] = 'O';
                    break;
                
                case 'y':
                    etat = FIN;
                    if (argv[i][j + 1] != '\0') {
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
                }
                else if (compare_chaine("--tail", argv[i])) {
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
                }
                fprintf(stderr, "Option %s inconnue.\n", argv[i]);
                break;
            
            case FIN:
                break;
            }
        }
    }
}



/*-------------------*\
| Fonction principale |
\*-------------------*/
int
main(int argc, char *argv[])
{
    cow vache = {
        .eyes = { 'o', 'o' },
        .tongue = { ' ', ' ' },
        .sayPos = -1,
        .width = 40,
        .tail = 3
    };

    options_vache(&vache, argc, argv);
    affiche_vache(vache, argc, argv);

    return 0;
}