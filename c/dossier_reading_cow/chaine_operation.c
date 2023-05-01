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