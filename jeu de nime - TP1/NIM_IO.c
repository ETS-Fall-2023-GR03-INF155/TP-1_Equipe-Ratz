#include "nim.h"

/*==========================================================*/

/*Fonction A*/ int lire_entier(int min, int max);

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