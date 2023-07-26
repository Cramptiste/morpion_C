#include <stdio.h>
#include <stdlib.h>

void dessinerGrille(char grille[])
{
    for (int i = 0; i < 9; i++)
    {
        printf("|%c", grille[i]);
        if (i == 2 || i == 5)
        {
            printf("|\n");
        }
    }
    printf("|\n");
}
int saisie_utilisateur()
{
    int saisie;
    printf("Joueur X, ou voulez-vous jouer (0-8) ?\n");
    scanf("%d", &saisie);
    return saisie;
}

int validitee(char grille[], int index)
{
    if (grille[index] == 'X' || grille[index] == 'O')
    {
        return 1;
    }
    return 0;
}
int jeu_termine(char grille[])
{
    for (int i = 0; i < 3; i++)
    {
        if (grille[i] == grille[i + 3] && grille[i + 3] == grille[i + 6] && grille[i] != '.')
        {
            return 1; 
        }
        if (grille[3 * i] == grille[3 * i + 1] && grille[3 * i + 1] == grille[3 * i + 2] && grille[3 * i] != '.')
        {
            return 1; 
        }
    }
    if (grille[0] == grille[4] && grille[4] == grille[8] && grille[0] != '.')
    {
        return 1; 
    }
    if (grille[2] == grille[4] && grille[4] == grille[6] && grille[2] != '.')
    {
        return 1; 
    }


    for (int i = 0; i < 9; i++)
    {
        if (grille[i] == '.')
        {
            return 0; 
        }
    }

    return -1; 
}
int main()
{
    printf("TP9: Les fonctions\n");
    int fin_partie = 0;
    char joueur = 'X';
    int coord;
    char grille[9] = {'.', '.', '.', '.', '.', '.', '.', '.', '.'};
    dessinerGrille(grille);

    do
    {
        int index;
        do
        {
            index = saisie_utilisateur();
        } while (validitee(grille, index) == 1);

        grille[index] = joueur;
        dessinerGrille(grille);

        int resultat = jeu_termine(grille);
        if (resultat == 1)
        {
            printf("Le joueur %c a gagne !\n", joueur);
            fin_partie = 1;
        }
        else if (resultat == -1)
        {
            printf("Match nul !\n");
            fin_partie = 1;
        }


        joueur = (joueur == 'X') ? 'O' : 'X';
    } while (fin_partie != 1);

    return 0;
}
