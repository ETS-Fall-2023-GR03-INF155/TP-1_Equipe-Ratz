#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "nim_io.h"


/*==========================================================*/
//Fonction A - Demande a l'usager de saisir un entier entre les bornes "min" et "max".
int lire_entier(int min, int max)
{
	int entier;

	do
	{
		printf("saisisez une valeur: ");
		scanf("%d", &entier);

		if (min <= entier && entier <= max)
		{
			printf("entier valide\n");
			return entier;
		}

		else
		{
			printf("entier non valide\n");
		}

	} while (min > entier || entier > max);
}

/*==========================================================*/
//Fonction C - Affiche la configuration du plateau à l'écran.
/*static void afficher_etoile(int x, int y, int is_selected)
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
                afficher_etoile(j, 5, col_select);
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

        afficher_etoile(i, 5, col_select);
        printf("%d", i);
        textbackground(BLACK);
    }
}*/