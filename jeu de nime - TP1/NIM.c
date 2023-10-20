#include "m_distributions.h"
#include "nim.h"

/*==========================================================*/

/*Fonction B*/ void plateau_init(int plateau[], int nb_colonnes);
/*Fonction D*/ int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces);
/*Fonction E*/ void plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer);
/*Fonction F*/ int plateau_defragmenter(int plateau[], int nb_colonnes);
/*Fonction G*/ void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int* choix_colonne, int* choix_nb_pieces);

/*==========================================================*/
//Fonction B - Initialise le plateau de jeu en remplissant les "nb_colonnes" d'un nombre aleatoire de pieces entre 1 et PLATEAU_MAX_PIECES = 35.
void plateau_init(int plateau[], int nb_colonnes)
{
	int i;

	for (i = 1; i < nb_colonnes; i++)
	{
		plateau[i] = md_randi(PLATEAU_MAX_PIECES);
	}
}

/*==========================================================*/
//Fonction D - Applique des changements a la configuration du plateau de jeu en retirant "nb_pieces" de la colonne "colonne" du plateau. 
int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces)
{
	if (colonne < nb_colonnes && nb_pieces < plateau[colonne])
	{
		plateau[colonne] -= nb_pieces;
		return TRUE;
	}

	else
		return FALSE;
}

/*==========================================================*/
//Fonction E - Supprime la colonne "col_a_supprimer" du plateau.
void plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer)
{
	int i;

	nb_colonnes--;

	for (i = col_a_supprimer; i < nb_colonnes; i++)
	{
		plateau[i] = plateau[i + 1];
	}
}

/*==========================================================*/
//Fonction F - Fonction qui supprime les colonnes vides du tableau en utilisant la fonction "plateau_supprimer_colonne". Le nombre de colonnes restant est retourne.
int plateau_defragmenter(int plateau[], int nb_colonnes)
{
	int i, N = 0;

	for (i = 0; i < nb_colonnes; i++)
	{
		if (plateau[i] == 0)
		{
			plateau_supprimer_colonne(plateau, nb_colonnes, i);
		}

		else
			++N;
	}

	return N;
}

/*==========================================================*/
//Fonction G - Fonction qui effectue un jeu aleatoire en choisissant au hasard une colonne, puis au hasard le nombre de pieces a jouer de cette colonne. 
void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int* choix_colonne, int* choix_nb_pieces)
{
	srand(time(NULL));

	*choix_colonne = rand() % nb_colonnes;

	*choix_nb_pieces = 1 + rand() % (plateau[*choix_colonne] + 1);
}
