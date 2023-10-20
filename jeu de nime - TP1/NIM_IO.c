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
//Fonction C - Initialise le plateau de jeu en remplissant les "nb_colonnes" d'un nombre aleatoire de pieces entre 1 et PLATEAU_MAX_PIECES = 35.
void plateau_afficher(const int plateau[], int nb_colonnes, int col_select)
{

}