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
/*
void plateau_afficher(const int plateau[], int nb_colonnes, int col_select)
{
	for (int i = 0; i < nb_colonnes; i++)
	{
		printf("x");
	}
}
*/