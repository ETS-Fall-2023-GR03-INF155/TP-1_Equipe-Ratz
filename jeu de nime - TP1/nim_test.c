#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include "nim_test.h"
#include "m_distributions.h"
#include <conio.h>

void main()
{
    int plateau[] = { 2, 4, 16, 5, 8, 9, 18, 10, 6, 20, 13, 30, 1 }, select, nb_colonnes;

    printf("nombre de colonnes: ");
    scanf("%d", &nb_colonnes);

    printf("choisissez une colone: ");
    scanf("%d", &select);

    printf("\n");

    plateau_afficher(plateau, nb_colonnes, select);

    printf("\n");
}

/*==========================================================*/
//Fonction C - Affiche la configuration du plateau à l'écran.
static void afficher_etoile(int x, int is_selected)
{
    if (x == is_selected)
    {
        textcolor(WHITE);
        textbackground(RED); // Fond rouge pour la colonne select
    }
    else
    {
        textcolor(WHITE);
        textbackground(BLACK); // Fond noir pour les autres colonnes
    }
}


void plateau_afficher(const int plateau[], int nb_colonnes, int col_select)
{
    int i, j;

    clrscr();				//clears the contents of the console

    printf("\n\n");

    // Afficher les numéros de colonne
    for (i = PLATEAU_MAX_PIECES; i > 0; i--)
    {
        gotoxy(1, 8 + (PLATEAU_MAX_PIECES - 1));
        textbackground(BLACK);
        textcolor(WHITE);
        if (i >= 10)
            printf("%d", i);
        else
            printf(" %d", i);

        // Nombre de pièces dans chaque colonne
        for (j = 0; j <= nb_colonnes; j++)
        {
            if (i <= plateau[j])
            {
                textbackground(BLACK);
                printf("  ");
                afficher_etoile(j, col_select);
                printf("*");
            }
            else
            {
                textbackground(BLACK);
                printf("   ");
            }

            textbackground(BLACK);
        }
        printf("\n");
    }

    printf("\n");
    printf("  ");

    for (i = 0; i <= nb_colonnes; i++)
    {
        if (i < 10)
            printf("  ");
        else
            printf(" ");

        afficher_etoile(i, col_select);
        printf("%d", i);
        textbackground(BLACK);
    }
}
