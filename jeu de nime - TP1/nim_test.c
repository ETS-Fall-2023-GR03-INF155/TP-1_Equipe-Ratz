#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include "nim_test.h"
#include "m_distributions.h"

#define TAILLE 10

void main()
{
	int plateau[TAILLE] = {0, 4}, select;

	printf("choisissez une colone: ");
	scanf("%d", &select);

    printf("\n");

	plateau_afficher(plateau, TAILLE, select);
}

/*==========================================================*/
//Fonction C - Affiche la configuration du plateau à l'écran.
void plateau_afficher(const int plateau[], int nb_colonnes, int col_select)
{
    int i, j, ligne = 10;

    printf("   ");  // Marge pour les numéros de colonnes

    for (i = 0; i < nb_colonnes; i++)
    {
        printf("%d ", i);
    }

    printf("\n");

    for (i = 0; i < nb_colonnes; i++)
    {
        printf("%d: ", i);
        
        for (j = 0; j < plateau[i]; j++)
        {
            if (i == col_select)
            {
                textcolor(15);
                textbackground(4);
                gotoxy(ligne, i);
                printf("* ");

                ligne -= 1;
            }

            else
            {
                textcolor(15);
                textbackground(0);
                printf("* ");
            }
        }

        printf("\n");
    }
}